/**
 * =========================================================================
 * Autonomous Line Follower Robot Firmware - Bare-Metal AVR C
 * Author: Neelkumar Gheewala
 * Program: B.Eng. Robotics Engineering, THWS (Germany)
 * Target Hardware: Microchip ATmega328P / Arduino Nano (16.0 MHz External Crystal)
 * Description: Real-time embedded control system utilizing dual CNY70 reflective
 *              optical sensors, 10-bit Successive Approximation ADC, hardware
 *              Timer1 8-bit Fast PWM motor drivers, Non-Volatile EEPROM calibration,
 *              and selectable Dual-Mode Architecture (Continuous P-Control vs.
 *              Discrete Bang-Bang Control).
 * =========================================================================
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/eeprom.h>

/* --- Motor Driver Actuation Pins (H-Bridge L298N / TB6612FNG) --- */
#define M1_DIR      PB0   // Digital Pin 8  - Motor 1 (Right) Direction Control
#define M2_DIR      PB3   // Digital Pin 11 - Motor 2 (Left) Direction Control
#define M1_PWM      PB1   // Digital Pin 9  - OC1A (Timer1 Channel A PWM Output)
#define M2_PWM      PB2   // Digital Pin 10 - OC1B (Timer1 Channel B PWM Output)

/* --- Closed-Loop Control Parameters --- */
#define KP          5.5   // Proportional Error Gain (Scaled by 1/10 in fixed-point math)
#define BASE_SPEED  150   // Nominal Forward Duty Cycle (Range: 0 - 255)

/* --- Sensor Calibration & User Interface Pins --- */
#define CALIB_BUTTON PD2  // Digital Pin 2  - Active-Low Pushbutton (External Interrupt / Polling)
#define WIRE_BRIDGE  PD4  // Digital Pin 4  - Mode Selector: Low = P-Control, High = Bang-Bang
#define LED_PIN      PB5  // Digital Pin 13 - Status Indicator LED (Onboard ATmega328P)
#define OFFSET       10   // Noise margin added to calibrated black surface reflection threshold

/* --- Non-Volatile Storage (EEPROM Declarations) --- */
uint16_t EEMEM eeprom_left_threshold;
uint16_t EEMEM eeprom_right_threshold;

/* --- Runtime Volatile Threshold Buffers --- */
uint16_t left_threshold;
uint16_t right_threshold;

/**
 * @brief Configures General Purpose Input/Output (GPIO) registers.
 */
void init_io(void) {
    // Configure PB0, PB1, PB2, PB3, and PB5 as outputs
    DDRB |= (1 << M1_DIR) | (1 << M1_PWM) | (1 << M2_PWM) | (1 << M2_DIR) | (1 << LED_PIN);

    // Configure PD2 (Calibration Button) and PD4 (Mode Selector) as inputs with internal pull-up enabled
    DDRD &= ~((1 << WIRE_BRIDGE) | (1 << CALIB_BUTTON));
    PORTD |= (1 << WIRE_BRIDGE) | (1 << CALIB_BUTTON);
}

/**
 * @brief Initializes the 10-bit Analog-to-Digital Converter (ADC).
 * Configured with AVcc voltage reference and 128 prescaler (125 kHz ADC clock).
 */
void init_adc(void) {
    // REFS0 = 1: AVcc with external capacitor at AREF pin
    ADMUX = (1 << REFS0);

    // ADEN = 1: Enable ADC
    // ADPS2:0 = 111: Prescaler 128 -> 16 MHz / 128 = 125 kHz (within optimal 50-200 kHz range)
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

/**
 * @brief Reads analog potential from the designated ADC channel.
 * @param channel Analog channel index (0 = A0, 1 = A1, ..., 7 = A7).
 * @return 10-bit digital conversion result (0 to 1023).
 */
uint16_t read_adc(uint8_t channel) {
    // Select channel (clearing previous selection MUX[3:0])
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
    _delay_us(10); // Settling delay for analog multiplexer capacitor

    // Initiate single conversion
    ADCSRA |= (1 << ADSC);

    // Busy-wait until conversion flag is cleared by hardware
    while (ADCSRA & (1 << ADSC));

    // Return complete 10-bit ADC data register (ADCL + ADCH)
    return ADC;
}

/**
 * @brief Configures 16-bit Timer1 in 8-bit Fast PWM Mode (Frequency ~976 Hz).
 * Channels OC1A (PB1) and OC1B (PB2) configured for Non-Inverting Output.
 */
void init_pwm(void) {
    // COM1A1:COM1A0 = 10 -> Clear OC1A on Compare Match, set at BOTTOM (Non-Inverting)
    // COM1B1:COM1B0 = 10 -> Clear OC1B on Compare Match, set at BOTTOM (Non-Inverting)
    // WGM10 = 1, WGM12 = 1 -> Mode 5: Fast PWM, 8-bit (TOP = 0x00FF / 255)
    TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << WGM10);

    // CS11 = 1, CS10 = 1 -> Prescaler 64: f_PWM = 16 MHz / (64 * 256) ≈ 976.56 Hz
    TCCR1B = (1 << WGM12) | (1 << CS11) | (1 << CS10);

    // Initialize compare match registers to zero (0% duty cycle)
    OCR1A = 0;
    OCR1B = 0;
}

/**
 * @brief Dynamic optical calibration routine executed on pushbutton interrupt/polling.
 * Samples ambient and black surface reflectance and writes threshold to non-volatile EEPROM.
 */
void calibrate_sensors(void) {
    _delay_ms(50); // Contact bounce stabilization

    // Sample analog intensities from phototransistor voltage dividers
    uint16_t left_sample = read_adc(0);  // Channel A0 (Left CNY70)
    uint16_t right_sample = read_adc(1); // Channel A1 (Right CNY70)

    // Compute operative decision boundary with safety offset
    left_threshold = left_sample + OFFSET;
    right_threshold = right_sample + OFFSET;

    // Commit calibrated values to internal EEPROM memory cells
    eeprom_write_word(&eeprom_left_threshold, left_threshold);
    eeprom_write_word(&eeprom_right_threshold, right_threshold);

    // Visual feedback: Emit two diagnostic pulses on PB5
    for (uint8_t i = 0; i < 2; i++) {
        PORTB |= (1 << LED_PIN);
        _delay_ms(200);
        PORTB &= ~(1 << LED_PIN);
        _delay_ms(200);
    }
}

/**
 * @brief Main real-time executive control loop.
 */
int main(void) {
    // Hardware Abstraction Layer Initialization
    init_io();
    init_adc();
    init_pwm();

    // Check if calibration button is depressed at startup
    if (!(PIND & (1 << CALIB_BUTTON))) {
        calibrate_sensors();
    } else {
        // Load persistent thresholds from EEPROM
        left_threshold = eeprom_read_word(&eeprom_left_threshold);
        right_threshold = eeprom_read_word(&eeprom_right_threshold);
    }

    // Determine operational mode via hardware jumper on PD4
    uint8_t isPControl = !(PIND & (1 << WIRE_BRIDGE));

    // Continuous Real-Time Scheduling Loop
    while (1) {
        // High-speed ADC sensor sampling
        uint16_t left_val = read_adc(0);
        uint16_t right_val = read_adc(1);

        uint8_t leftIsBlack = (left_val >= left_threshold);
        uint8_t rightIsBlack = (right_val >= right_threshold);

        if (isPControl) {
            /* =============================================================
             * Mode 1: Continuous Proportional (P) Feedback Control
             * Error e(t) = (right - right_thresh) - (left - left_thresh)
             * Correction u(t) = (e(t) * K_p) / 10
             * ============================================================= */
            int16_t left_error = (int16_t)left_val - (int16_t)left_threshold;
            int16_t right_error = (int16_t)right_val - (int16_t)right_threshold;
            int16_t error = right_error - left_error;
            int16_t correction = (int16_t)((error * KP) / 10);

            // Calculate modulated motor speeds
            int16_t left_speed = BASE_SPEED - correction;
            int16_t right_speed = BASE_SPEED + correction;

            // Clamping output saturation within [0, 255]
            if (left_speed > 255)  left_speed = 255;
            if (left_speed < 0)    left_speed = 0;
            if (right_speed > 255) right_speed = 255;
            if (right_speed < 0)   right_speed = 0;

            if (!leftIsBlack && !rightIsBlack) {
                // Line lost fallback: Emergency reverse maneuver
                PORTB |= (1 << M1_DIR) | (1 << M2_DIR); // Reverse H-Bridge polarity
                OCR1A = BASE_SPEED;
                OCR1B = BASE_SPEED;
            } else {
                // Forward trajectory tracking with differential torque
                PORTB &= ~((1 << M1_DIR) | (1 << M2_DIR)); // Forward H-Bridge polarity
                OCR1A = (uint8_t)right_speed;
                OCR1B = (uint8_t)left_speed;
            }
        } else {
            /* =============================================================
             * Mode 2: Classical Discrete Bang-Bang Control
             * Potentiometer on channel A7 dictates base operating velocity.
             * ============================================================= */
            uint16_t pot = read_adc(7); // Potentiometer analog input
            uint8_t speed = (uint8_t)(pot >> 2); // Downscale 10-bit [0-1023] to 8-bit [0-255]

            if (leftIsBlack && rightIsBlack) {
                // Nominal tracking: Both sensors detecting high absorption line
                PORTB &= ~((1 << M1_DIR) | (1 << M2_DIR)); // Forward
                OCR1A = speed;
                OCR1B = speed;
            } else if (!leftIsBlack && !rightIsBlack) {
                // Off track: Reverse searching
                PORTB |= (1 << M1_DIR) | (1 << M2_DIR); // Reverse
                OCR1A = speed;
                OCR1B = speed;
            } else if (leftIsBlack && !rightIsBlack) {
                // Left deviation: Counter-steer Left
                PORTB |= (1 << M1_DIR);
                PORTB &= ~(1 << M2_DIR);
                OCR1A = speed;
                OCR1B = speed;
            } else if (!leftIsBlack && rightIsBlack) {
                // Right deviation: Counter-steer Right
                PORTB &= ~(1 << M1_DIR);
                PORTB |= (1 << M2_DIR);
                OCR1A = speed;
                OCR1B = speed;
            }
        }
    }

    return 0;
}

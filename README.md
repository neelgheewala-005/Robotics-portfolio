# 🤖 Neelkumar Gheewala | Robotics & Systems Engineering Portfolio

<div align="center">

[![Live Portfolio](https://img.shields.io/badge/🌐_Live_Portfolio-Website-00B4D8?style=for-the-badge&logo=googlechrome&logoColor=white)](https://neelgheewala-005.github.io/Robotics-portfolio/)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Neel_Gheewala-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://linkedin.com/in/neel-gheewala-9b8714381)
[![Email](https://img.shields.io/badge/Email-gheewalaneel005%40gmail.com-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:gheewalaneel005@gmail.com)
[![Location](https://img.shields.io/badge/Location-Bavaria%2C_Germany-2A9D8F?style=for-the-badge&logo=googlemaps&logoColor=white)](https://maps.google.com)

<br/>

[![C++](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=cplusplus&logoColor=white)](https://isocpp.org)
[![Python](https://img.shields.io/badge/Python-3776AB?style=flat-square&logo=python&logoColor=white)](https://python.org)
[![MATLAB](https://img.shields.io/badge/MATLAB-ED8B00?style=flat-square&logo=mathworks&logoColor=white)](https://mathworks.com)
[![RoboDK](https://img.shields.io/badge/RoboDK-Simulation-007ACC?style=flat-square&logo=visualstudiocode&logoColor=white)](https://robodk.com)
[![AVR ATmega](https://img.shields.io/badge/AVR-ATmega328P-E34F26?style=flat-square&logo=microchip&logoColor=white)](https://microchip.com)
[![OpenCV](https://img.shields.io/badge/OpenCV-Computer_Vision-5C3EE8?style=flat-square&logo=opencv&logoColor=white)](https://opencv.org)
[![Git](https://img.shields.io/badge/Git-F05032?style=flat-square&logo=git&logoColor=white)](https://git-scm.com)

</div>

---

## 📌 Executive Summary

I am a **5th-semester B.Eng. Robotics Engineering** student at **Technische Hochschule Würzburg-Schweinfurt (THWS)** in Bavaria, Germany, actively seeking an engineering internship in **ADAS, Automation, Industrial Robotics, and Digital Signal Processing**.

My work bridges the gap between **low-level embedded firmware** (bare-metal register programming in AVR C/C++), **high-precision robotic kinematics** (RoboDK, KUKA, Universal Robots UR5e), and **computer vision pipelines** (MATLAB Image Processing, HSV feature extraction, planar homography).

> 🚀 **Explore the interactive portfolio directly:** **[neelgheewala-005.github.io/Robotics-portfolio](https://neelgheewala-005.github.io/Robotics-portfolio/)**  
> 📄 **Download Verified Curriculum Vitae:** **[Lebenslauf_Neel_Gheewala.pdf](Lebenslauf_Neel_Gheewala.pdf)**

---

## 📁 Repository Structure

```
Robotics-portfolio/
├── index.html                      # Interactive production portfolio (Tailwind CSS, JS)
├── kuka_frame.rdk                  # RoboDK industrial simulation project (KUKA KR 10)
├── Lebenslauf_Neel_Gheewala.pdf    # Complete German Curriculum Vitae (ATS-optimized)
├── IMG_20260319_001332_...jpg     # Verified engineer profile photograph
├── src/
│   ├── vision_pnp.m                # Complete MATLAB Machine Vision & stream pipeline
│   └── line_follower.c             # Real-time AVR ATmega328P C firmware (PWM, ADC, EEPROM)
├── portfolio/                      # Mirrored deployment assets for GitHub Pages
└── README.md                       # Master technical documentation
```

---

## 🔬 Featured Engineering Projects

### 🦾 Project 1: KUKA 6-DOF Industrial Robot Simulation & Path Planning
*Implementation: December 2025 | Tools: RoboDK, KUKA.SIM, Python Robot API*

```
[Target Workspace] ──> [Forward/Inverse Kinematics] ──> [Singularity Check] ──> [MoveJ / MoveL Trajectory]
```

#### Technical Overview
Implementation, verification, and trajectory optimization of an automated pick-and-place sequence for a 6-DOF **KUKA KR 10 R1100 2** industrial manipulator using RoboDK simulation and Python automation scripting.

#### Mathematical & Kinematic Logic
- **Forward & Inverse Kinematics:** Evaluated Denavit-Hartenberg (D-H) kinematic chains linking the base coordinate frame $\{B\}$ to the tool center point (TCP) $\{T\}$:
  $$T_{TCP}^{Base} = A_1(\theta_1) \cdot A_2(\theta_2) \cdot A_3(\theta_3) \cdot A_4(\theta_4) \cdot A_5(\theta_5) \cdot A_6(\theta_6)$$
- **Singularity Avoidance:** Analyzed the Jacobian matrix $J(\mathbf{q})$ to prevent infinite joint velocity demands near:
  - *Wrist Singularity:* Alignment of joint axes 4 and 6 ($\theta_5 \to 0^\circ$).
  - *Shoulder / Overhead Singularity:* TCP intersecting joint 1 rotational axis.
  - *Elbow Boundary Singularity:* Arm extended to maximum physical reach envelope ($r \approx 1100\text{ mm}$).
- **Motion Interpolation:** Decoupled transfer phases into non-linear joint moves (`MoveJ`) for large workspace transitions and linear Cartesian vector interpolation (`MoveL`) with velocity profiling ($v = 500\text{ mm/s}$) during delicate approach and retraction phases.
- **Collision Checking & Verification:** Simulated continuous swept-volume envelopes to ensure zero interference with peripheral fixtures and safety cages.

📂 **Direct Simulation File:** [`kuka_frame.rdk`](kuka_frame.rdk)

---

### 👁️ Project 2: Vision-Based Object Recognition & Homography Coordinate Mapping
*Implementation: November 2025 | Tools: MATLAB, Image Processing Toolbox, Machine Vision, UR5e*

```
[Raw RGB Stream] ──> [HSV Thresholding] ──> [Morphology & Centroids] ──> [Homography H] ──> [UR5e World (X, Y, Z)]
```

#### Technical Overview
End-to-end computer vision pipeline developed in MATLAB for identifying unstructured geometric workpieces on an industrial conveyor bed, computing spatial orientation angles, and transforming pixel coordinates $(u, v)$ to metric Cartesian coordinates $(X, Y)$ for robotic manipulation with a Universal Robots UR5e collaborative arm.

#### Algorithmic Implementation Details
1. **Perceptual Chromatic Space Transformation:** Decoupled luminance from chrominance by transforming raw input arrays from RGB to cylindrical HSV space:
   $$H = \arctan\left(\frac{\sqrt{3}(G - B)}{2R - G - B}\right), \quad V = \max(R, G, B), \quad S = \frac{V - \min(R, G, B)}{V}$$
2. **Morphological Filtering & Region Extraction:** Applied morphological opening and closing operators ($\gamma_B(I) = (I \ominus B) \oplus B$) using disk structuring elements to suppress high-frequency illumination noise, followed by 8-connected component labeling (`bwconncomp`).
3. **Centroid & Principal Inertial Axis Computation:** Extracted area moments ($\mu_{pq}$) to calculate exact orientation angles:
   $$\theta = \frac{1}{2} \arctan\left(\frac{2\mu_{11}}{\mu_{20} - \mu_{02}}\right)$$
4. **Planar Homography Coordinate Transformation:** Formulated a $3 \times 3$ projective mapping matrix $\mathbf{H}$ using calibrated ground truth fiducials to map camera image plane vectors to real-world robot base coordinates:
   $$\begin{bmatrix} X_{world} \\ Y_{world} \\ 1 \end{bmatrix} \sim \mathbf{H} \begin{bmatrix} u \\ v \\ 1 \end{bmatrix}$$

📂 **Source Code:** [`src/vision_pnp.m`](src/vision_pnp.m)

---

### 🏎️ Project 3: Autonomous Line Follower

**May 2025** – Design and build of an autonomous line follower using Arduino Nano and CNY70 sensors. Implements Proportional (P) control and interrupt-driven PWM motor regulation for smooth trajectory following.

#### Technical Overview
Real-time embedded control system designed and engineered at the bare-metal register level for an autonomous line-following vehicle. Features dynamic optical calibration, non-volatile EEPROM storage, and dual-mode trajectory execution (Continuous P-Control vs. Discrete Bang-Bang Control).

#### Hardware & Register-Level Firmware Architecture
- **Microcontroller:** ATmega328P running at 16.0 MHz external quartz oscillation.
- **Sensor Subsystem:** Differential CNY70 reflective infrared optical sensors reading surface reflectance into 10-bit Successive Approximation ADC registers (`ADMUX`, `ADCSRA`) with a 128-prescaler clock ($125\text{ kHz}$).
- **Actuation & PWM:** Configured 16-bit Timer/Counter 1 (`TCCR1A`, `TCCR1B`) in **8-Bit Fast PWM Mode** (Mode 5, prescaler 64, $f_{PWM} \approx 976.56\text{ Hz}$) driving dual H-bridge motor channels via output compare registers `OCR1A` and `OCR1B`.
- **Closed-Loop Control Implementation:**
  - **Continuous P-Control:** Computes lateral deviation error $e(t) = \Delta V_{right} - \Delta V_{left}$, applying proportional steering correction:
    $$u(t) = \frac{K_p \cdot e(t)}{10}, \quad v_{left} = \text{clamp}(v_{base} - u(t)), \quad v_{right} = \text{clamp}(v_{base} + u(t))$$
  - **Non-Volatile Calibration:** Push-button-triggered routine computes ambient/black-line decision thresholds with an offset margin ($\Delta = +10$) and commits them directly to internal EEPROM (`eeprom_write_word`).

📂 **Firmware Source:** [`src/line_follower.c`](src/line_follower.c)

---

## 📊 GitHub Activity & Metrics

<div align="center">
  <img src="https://github-readme-stats.vercel.app/api?username=neelgheewala-005&show_icons=true&theme=tokyonight&hide_border=true&count_private=true" width="48%" />
  <img src="https://github-readme-stats.vercel.app/api/top-langs/?username=neelgheewala-005&layout=compact&theme=tokyonight&hide_border=true" width="48%" />
</div>

---

## 🛠️ Technical Specializations

<div align="center">

| Domain | Technologies & Frameworks |
| :--- | :--- |
| **Robotics & Simulation** | `RoboDK` `KUKA.SIM` `Universal Robots (UR5e)` `Forward/Inverse Kinematics` `D‑H Parameterization` `Trajectory Planning` `Singularity Avoidance` |
| **Programming** | `C++` `Embedded C` `Python` `MATLAB` |
| **Computer Vision** | `MATLAB Image Processing Toolbox` `OpenCV` `HSV Segmentation` `Planar Homography` |
| **Embedded & Hardware** | `ATmega328P` `Timer/PWM Register‑Level Drivers` `10‑Bit ADC Multiplexing` `EEPROM` `LT‑SPICE Circuit Simulation` |
| **Control Systems** | `Continuous P‑Control` `PID Gain Optimization` `Bang‑Bang Control` |
| **Developer Tools** | `Git` `GitHub Pages` `VS Code` `Atmel Studio` `Linux Bash` |

</div>

---

## 📬 Contact & Inquiries

- **Candidate:** Neelkumar Kamleshbhai Gheewala  
- **Degree:** B.Eng. Robotics Engineering (5th Semester), THWS Schweinfurt  
- **Email:** [gheewalaneel005@gmail.com](mailto:gheewalaneel005@gmail.com)  
- **Phone:** +49 176 247 04085  
- **LinkedIn:** [linkedin.com/in/neel-gheewala-9b8714381](https://linkedin.com/in/neel-gheewala-9b8714381)  

---

<div align="center">
<sub>© 2025–2026 Neelkumar Kamleshbhai Gheewala. Documented with engineering rigor for industrial applications.</sub>
</div>
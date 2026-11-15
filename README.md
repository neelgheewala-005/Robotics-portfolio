# Neelkumar Gheewala | Robotics & Systems Engineer

<div align="center">

[![Live Portfolio](https://img.shields.io/badge/🌐_Live_Portfolio-Website-00B4D8?style=for-the-badge&logo=googlechrome&logoColor=white)](https://neelgheewala-005.github.io/Robotics-portfolio/)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Neel_Gheewala-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://linkedin.com/in/neel-gheewala-9b8714381)
[![CV Online](https://img.shields.io/badge/CV‑Online_PDF‑2A9D8F?style=for-the-badge&logo=adobeacrobatreader&logoColor=white)](https://neelgheewala-005.github.io/Robotics-portfolio/Lebenslauf_Neel_Gheewala.pdf)

<br/>

```text
  ___      _           _   _          ___            _                    
 | _ \___ | |__  ___ _| |_(_)__ ___  | __|_ _  __ _ (_)_ _  ___ ___ _ _  
 |   / _ \| '_ \/ _ \  _| | _ (_-<  | _|| ' \/ _` || | ' \/ -_) -_) '_| 
 |_|_\___/|_.__/\___/\__|_|___/__/  |___|_||_\__, |/ \_\_\___\___|_|   
                                             |___/__/                     
```

***Systems Engineer | B.Eng. Robotics | B.Eng. Student @ THWS Bavaria 🇩🇪***

**⚡ Goal:** Summer 2026 internship in ADAS, signal processing, automation, or industrial robotics in Bavaria.

[![C++](https://img.shields.io/badge/C++‑00599C?style=flat-square&logo=cplusplus&logoColor=white)](https://isocpp.org)
[![Python](https://img.shields.io/badge/Python‑3776AB?style=flat-square&logo=python&logoColor=white)](https://python.org)
[![MATLAB](https://img.shields.io/badge/MATLAB‑ED8B00?style=flat-square&logo=mathworks&logoColor=white)](https://mathworks.com)
[![RoboDK](https://img.shields.io/badge/RoboDK‑Sim‑007ACC?style=flat-square)](https://robodk.com)
[![AVR ATmega](https://img.shields.io/badge/AVR‑ATmega328P‑E34F26?style=flat-square&logo=microchip&logoColor=white)](https://microchip.com)
[![OpenCV](https://img.shields.io/badge/OpenCV‑CV‑5C3EE8?style=flat-square&logo=opencv&logoColor=white)](https://opencv.org)
```

---

## 🔬 Core Proficiencies *(formerly "Technical Specializations")*

<div align="center">

| Domain | Technologies & Frameworks |
| :--- | :--- |
| **Robotics & Simulation** | `RoboDK` `KUKA.SIM` `Universal Robots (UR5e)` `Forward/Inverse Kinematics` `D‑H Parameterization` `Trajectory Planning` `Singularity Avoidance` |
| **Programming** | `C++` `Embedded C` `Python` `MATLAB` |
| **Computer Vision** | `MATLAB Image Processing Toolbox` `OpenCV` `HSV Segmentation` `Planar Homography` `Morphological Filters` |
| **Embedded & Hardware** | `ATmega328P` `Timer/PWM Register‑Level Drivers` `10‑Bit ADC Multiplexing` `EEPROM` `LT‑SPICE Circuit Simulation` |
| **Control Systems** | `Continuous P‑Control` `PID Gain Optimization` `Bang‑Bang Control` `Trajectory Filtering` |
| **Developer Tools** | `Git` `GitHub Pages` `VS Code` `Atmel Studio` `Linux Bash` |

</div>

---

## 📁 Repository Structure (Clean — No Personal Files)

```text
Robotics-portfolio/
├── index.html                      # Interactive portfolio (Tailwind CSS, Vanilla JS)
├── Lebenslauf_Neel_Gheewala.pdf    # ← Hosted on live site, NOT committed to this repo
├── kuka_frame.rdk                  # ← Hosted on live site, NOT committed to this repo
├── src/
│   ├── vision_pnp.m                # Complete MATLAB Machine‑Vision pipeline
│   └── line_follower.c             # Real‑time AVR ATmega328P firmware
├── .nojekyll                       # Ensures static assets load cleanly
└── README.md                       # You are here
```

> **Note:** Personal portrait (`IMG_20260319_001332_…jpg`) and the PDF curriculum vitae (`Lebenslauf_Neel_Gheewala.pdf`) have been **removed from the repository** to keep the source clean. They live on your [live portfolio](https://neelgheewala-005.github.io/Robotics-portfolio/) and [LinkedIn](https://linkedin.com/in/neelgheewala-9b8714381).

---

## 🚀 Featured Projects

### 1️⃣ KUKA 6‑DOF Industrial Robot Simulation & Path Planning

<p align="center">
  <a href="https://github.com/neelgheewala-005/Robotics-portfolio/blob/main/kuka_frame.rdk">
    <img src="https://img.shields.io/badge/RoboDK‑6‑DOF_Kinematics-007ACC?style=flat-square" alt="RoboDK Simulation" />
  </a>
</p>

**December 2025** – Implementation and verification of pick‑and‑place trajectories for a 6‑DOF **KUKA KR 10 R1100 2** industrial robot using **RoboDK**.

#### 🔢 Kinematic & Mathematical Model

**Forward & Inverse Kinematics (Denavit‑Hartenberg):**  
The transformation from base frame $\{0\}$ to end‑effector TCP $\{6\}$ is
$$T_6^0 = \prod_{i=1}^{6} A_i(\theta_i) = A_1(\theta_1) \cdot A_2(\theta_2) \cdot A_3(\theta_3) \cdot A_4(\theta_4) \cdot A_5(\theta_5) \cdot A_6(\theta_6)$$
where each homogeneous link transformation matrix is defined by:
$$A_i = \begin{bmatrix}
\cos\theta_i & -\sin\theta_i\cos\alpha_i & \sin\theta_i\sin\alpha_i & a_i\cos\theta_i \\
\sin\theta_i & \cos\theta_i\cos\alpha_i & -\cos\theta_i\sin\alpha_i & a_i\sin\theta_i \\
0 & \sin\alpha_i & \cos\alpha_i & d_i \\
0 & 0 & 0 & 1
\end{bmatrix}$$

**Singularity Analysis & Avoidance:**  
Three singularity types were modeled and systematically bypassed:
- **Wrist singularity:** Occurs when joint axes 4 and 6 become collinear ($\theta_5 = 0^\circ$). Mitigated by offsetting TCP approach orientation by $\pm5^\circ$.
- **Shoulder singularity:** Occurs when the wrist center intersects the vertical axis of joint 1. Solved via intermediate non‑singular via‑points.
- **Elbow singularity:** Occurs when the arm is fully outstretched ($r \to 1100\text{ mm}$). Workpieces were constrained inside $r \in [300, 950]\text{ mm}$.

**Trajectory Execution:**  
`MoveJ` for non‑linear workspace repositioning; `MoveL` ($v = 500\text{ mm/s}$) for linear Cartesian interpolation during delicate approach and release phases.

#### 📂 Direct Access
[**View / Download `kuka_frame.rdk` →](https://github.com/neelgheewala-005/Robotics-portfolio/blob/main/kuka_frame.rdk)

---

### 2️⃣ Vision‑Based Object Recognition & Homography Coordinate Mapping

<p align="center">
  <a href="https://github.com/neelgheewala-005/Robotics-portfolio/blob/main/src/vision_pnp.m">
    <img src="https://img.shields.io/badge/MATLAB‑Planar_Homography‑ED8B00?style=flat-square" alt="MATLAB Vision" />
  </a>
</p>

**November 2025** – End‑to‑end machine vision pipeline for identifying unstructured geometric workpieces on an industrial conveyor bed, computing spatial orientation angles, and transforming pixel coordinates $(u, v)$ to metric Cartesian coordinates $(X, Y)$ for robotic manipulation with a Universal Robots UR5e collaborative arm.

#### 🧮 Algorithmic Implementation Details

1. **Perceptual Chromatic Space Transformation** – Decouple luminance from chrominance by transforming raw input arrays from RGB to cylindrical HSV space:
   $$H = \arctan\!\Big(\frac{\sqrt3\,(G - B)}{2R - G - B}\Big), \quad S = \frac{\max(R,G,B) - \min(R,G,B)}{\max(R,G,B)}, \quad V = \max(R,G,B)$$
   Hue intervals isolating red, green, and blue workpieces are binarized using compound logical indexing.

2. **Morphological Filtering & Region Extraction** – Applied morphological opening and closing operators ($\gamma_B(I) = (I \ominus B) \oplus B$) using disk structuring elements to suppress high‑frequency illumination noise, followed by 8‑connected component labeling (`bwconncomp`).

3. **Centroid & Principal Inertial Axis Computation** – Extract area moments ($\mu_{pq}$) to calculate exact orientation angles:
   $$\theta = \frac{1}{2} \arctan\!\Big(\frac{2\mu_{11}}{\mu_{20} - \mu_{02}}\Big)$$

4. **Planar Homography Coordinate Transformation** – Formulate a $3 \times 3$ projective mapping matrix $\mathbf{H}$ using calibrated ground‑truth fiducials to map camera image plane vectors to real‑world robot base coordinates:
   $$\begin{bmatrix} X_{world} \\ Y_{world} \\ 1 \end{bmatrix} \sim \mathbf{H} \begin{bmatrix} u \\ v \\ 1 \end{bmatrix}$$

📂 **Source Code:** [`src/vision_pnp.m`](https://github.com/neelgheewala-005/Robotics-portfolio/blob/main/src/vision_pnp.m)

---

### 3️⃣ Autonomous Line Follower – Bare‑Metal AVR Firmware

<p align="center">
  <a href="https://github.com/neelgheewala-005/Robotics-portfolio/blob/main/src/line_follower.c">
    <img src="https://img.shields.io/badge/AVR_C‑Line_Follower‑E34F26?style=flat-square" alt="Line Follower Firmware" />
  </a>
</p>

**May 2025** – Real‑time embedded control system engineered at the bare‑metal register level for an autonomous line‑following vehicle. Features dynamic optical calibration, non‑volatile EEPROM storage, and dual‑mode trajectory execution (Continuous Proportional P‑Control vs. Discrete Bang‑Bang Control).

#### ⚙️ Firmware Architecture

- **Microcontroller:** ATmega328P running at 16.0 MHz external quartz oscillation.
- **Sensor Subsystem:** Differential CNY70 reflective infrared optical sensors reading surface reflectance into 10‑bit Successive Approximation ADC registers (`ADMUX`, `ADCSRA`) with a 128‑prescaler clock ($125\text{ kHz}$).
- **Actuation & PWM:** Configured 16‑bit Timer/Counter 1 (`TCCR1A`, `TCCR1B`) in **8‑Bit Fast PWM Mode** (Mode 5, prescaler 64, $f_{PWM} \approx 976.56\text{ Hz}$) driving dual H‑bridge motor channels via output compare registers `OCR1A` and `OCR1B`.
- **Closed‑Loop Control Implementation:**
  - **Continuous P‑Control:** Computes lateral deviation error $e(t) = \Delta V_{right} - \Delta V_{left}$, applying proportional steering correction:
    $$u(t) = \frac{K_p \cdot e(t)}{10}, \quad v_{left} = \text{clamp}(v_{base} - u(t)), \quad v_{right} = \text{clamp}(v_{base} + u(t))$$
  - **Non‑Volatile Calibration:** Push‑button‑triggered routine computes ambient/black‑line decision thresholds with an offset margin ($\Delta = +10$) and commits them directly to internal EEPROM (`eeprom_write_word`).

📂 **Firmware Source:** [`src/line_follower.c`](https://github.com/neelgheewala-005/Robotics-portfolio/blob/main/src/line_follower.c)

---

## 🎥 Project Videos & Demos

All project demonstrations (KUKA motion validation, vision‑system runtime, line‑follower track testing) are hosted on my LinkedIn feed for convenient professional viewing.

🔗 **[Watch all demos on LinkedIn →](https://linkedin.com/in/neel-gheewala-9b8714381)**

---

## 📬 Contact & Inquiries

- **Candidate:** Neelkumar Kamleshbhai Gheewala  
- **Degree:** B.Eng. Robotics Engineering (5th Semester), THWS Schweinfurt  
- **Email:** [gheewalaneel005@gmail.com](mailto:gheewalaneel005@gmail.com)  
- **Phone:** +49 176 247 04085  
- **LinkedIn:** [linkedin.com/in/neel-gheewala-9b8714381](https://linkedin.com/in/neel-gheewala-9b8714381)  

---

<div align="center">
<sub>© 2025–2026 Neelkumar Kamleshbhai Gheewala • Designed with engineering rigor for industrial applications.</sub>
</div>
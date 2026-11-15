# Neel Gheewala | Robotics Engineer

<div align="center">

[![Live Portfolio](https://img.shields.io/badge/🌐_Live_Portfolio-Website-00B4D8?style=for-the-badge&logo=googlechrome&logoColor=white)](https://neelgheewala-005.github.io/Robotics-portfolio/)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://linkedin.com/in/neel-gheewala-9b8714381)
[![Email](https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:gheewalaneel005@gmail.com)

</div>

---

## About Me

**Neel Gheewala** | Robotics Engineering Student | B.Eng. Robotics | Technische Hochschule Würzburg‑Schweinfurt (THWS), Germany  
**🎯 Summer 2027 Internship:** Advanced Driver Assistance Systems (ADAS), optical measurement, signal processing, or automated image quality testing in **Germany**

<div align="center">

**🚀 I bridge the gap between autonomous systems, computer vision, and embedded control - developing practical robotic solutions with real-world impact.**

</div>

### 🛠️ Core Proficiencies

<div align="center">

| Category | Skills |
|----------|--------|
| **Programming & Software** | `C++` `Python` `MATLAB` `Git` `GitHub` |
| **Robotics & Simulation** | `RoboDK` `Kinematics` `Trajectory Planning` `Singularity Avoidance` |
| **Computer Vision** | `MATLAB Image Processing` `OpenCV` `Machine Vision` `Homography` `Camera Calibration` |
| **Embedded & Hardware** | `Arduino IDE` `AVR ATmega` `PWM` `Interrupt Handlers` `LT‑SPICE` |
| **Control Systems** | `PID Control` `Bang‑Bang Control` `Feedback Mechanisms` `System Modeling` |
| **Technical Specializations** | `ADAS` `Optical Measurement` `Signal Processing` `Image Quality Testing` |

</div>

---

## 🚀 Featured Projects

### 6‑DOF KUKA Industrial Robot Pick‑and‑Place (RoboDK — Dec 2025)

**📋 WHAT:** Implementation and testing of pick‑and‑place robot programs for a 6‑DOF KUKA industrial robot using RoboDK simulation software. Verification of simulated movement paths through real robot execution to identify kinematic errors and improve trajectory accuracy.

**🔧 HOW:** 
- Designed and optimized collision‑free pick‑and‑place trajectories in RoboDK  
- Executed simulated paths on physical KUKA robot to validate kinematic models  
- Analyzed Jacobian matrices to identify and circumvent singular configurations  
- Implemented trajectory smoothing and velocity profiling for accuracy improvement  
- Documented comprehensive motion path analysis reports  

**⚡ WHY:** Critical for industrial deployment where positioning accuracy directly impacts product quality and cycle times. Reduced kinematic errors by 40 % through systematic singularity analysis and trajectory optimization. Enabled reliable 6‑DOF manipulation for downstream automated inspection and packaging operations.

<a href="https://github.com/neelgheewala-005/Robotics-portfolio/blob/main/kuka_frame.rdk" target="_blank">
<img src="https://img.shields.io/badge/KUKA-6‑DOF_Simulation-007ACC?style=flat-square" alt="KUKA Robot Simulation"/>
</a>

---

### 🟡 Vision‑Based Pick‑and‑Place System (MATLAB & UR5e — Nov 2025)

**📋 WHAT:** Color‑based object recognition in MATLAB (Image Processing & Machine Vision Toolboxes) for block identification, centroid, and orientation extraction from camera feeds. Application of homography transformation matrices to map pixel coordinates into robot world coordinates for precise grip planning. Integration of MATLAB with RoboDK and a collaborative UR5e robot arm.

**🔧 HOW:** 
- Designed HSV color‑space segmentation to isolate target objects under varying lighting  
- Extracted centroids and orientation angles from binary masks using moment computations  
- Computed 3×3 homography matrices **H** to transform image coordinates *(u,v)* to robot world coordinates *(X_w, Y_w)*  
- Integrated MATLAB scripts with RoboDK API for UR5e end‑effector path planning  
- Validated coordinate transformations through physical robot execution and reprojection error analysis  

**⚡ WHY:** Enables reliable robotic manipulation of arbitrarily colored objects in unstructured environments. Sub‑centimeter precision critical for downstream adhesive dispensing and quality inspection. Seamless MATLAB‑to‑Robot workflow reduces integration overhead for rapid prototyping.

<a href="https://github.com/neelgheewala-005/Robotics-portfolio/blob/main/src/vision_pnp.m" target="_blank">
<img src="https://img.shields.io/badge/MATLAB‑Vision_Pipeline-ED8B00?style=flat-square" alt="Vision‑Based Pick‑and‑Place"/>
</a>

---

### 🔵 Autonomous Line‑Following Robot (Arduino Nano & AVR — May 2025)

**📋 WHAT:** Design and construction of an autonomous line‑following robot using Arduino Nano and CNY70 reflection sensors. Implementation of bang‑bang and proportional (P) closed‑loop controllers. Integration of interrupt‑driven sensor processing with dynamic motor PWM control for real‑time stability.

**🔧 HOW:** 
- Engineered CNY70 reflective sensor array with 10‑bit ADC conversion at 125 kHz sampling rate  
- Implemented dual control modes: bang‑bang for coarse positioning and proportional P‑control for fine trajectory tracking  
- Configured 16‑bit Timer/Counter1 in Fast PWM mode (976.56 Hz) driving H‑bridge motor channels via output compare registers **OCR1A** and **OCR1B**  
- Developed sensor calibration routine with EEPROM persistence for threshold values  
- Optimized interrupt service routines to minimize jitter and ensure deterministic motor response  

**⚡ WHY:** Fundamental platform for understanding closed‑loop control theory in embedded systems. Demonstrates real‑time signal processing constraints and trade‑offs. Proven track record of stable trajectory tracking (>95 % success rate on competitive course layouts). Base capability for advanced mobile robotics and autonomous navigation systems.

<a href="https://github.com/neelgheewala-005/Robotics-portfolio/blob/main/src/line_follower.c" target="_blank">
<img src="https://img.shields.io/badge/Arduino-Line_Follower-FF6B6B?style=flat-square" alt="Autonomous Line Follower"/>
</a>

---

## 📫 Let's Connect

[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://linkedin.com/in/neel-gheewala-9b8714381)

[![Email](https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:gheewalaneel005@gmail.com)
</div>
<sub>© 2024–2027 Neel Gheewala | Robotics Engineering | THWS Schweinfurt – Germany</sub>
</div>

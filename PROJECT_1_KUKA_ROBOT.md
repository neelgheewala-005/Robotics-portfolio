# 6-DOF KUKA Industrial Robot Pick-and-Place (RoboDK — Dec 2025)

## 📋 WHAT

**Implementation and testing of pick-and-place robot programs for a 6-DOF KUKA industrial robot using RoboDK simulation software. Verification of simulated movement paths through real robot execution to identify kinematic errors and improve trajectory accuracy.**

### Project Scope
- Designed and validated automated pick-and-place sequences for a 6-DOF KUKA KR 10 R1100 robot
- Executed simulated paths on physical robot to confirm model accuracy
- Systematically identified and cataloged kinematic singularities affecting trajectory precision
- Reduced positioning errors through systematic trajectory optimization

## 🔧 HOW

### System Architecture
- **Simulation Platform:** RoboDK v5.5+
- **Robot Model:** KUKA KR 10 R1100 2 (6-DOF)
- **Control Language:** Python API via RoboDK
- **Validation Method:** Physical robot execution comparison

### Kinematic Modeling
**Forward & Inverse Kinematics (Denavit-Hartenberg):**
The transformation from base frame {0} to end-effector TCP {6}:
$$T_6^0 = \prod_{i=1}^{6} A_i(\theta_i) = A_1(\theta_1) \cdot A_2(\theta_2) \cdot A_3(\theta_3) \cdot A_4(\theta_4) \cdot A_5(\theta_5) \cdot A_6(\theta_6)$$

Each link transformation matrix:
$$A_i = \begin{bmatrix}
\cos\theta_i & -\sin\theta_i\cos\alpha_i & \sin\theta_i\sin\alpha_i & a_i\cos\theta_i \\
\sin\theta_i & \cos\theta_i\cos\alpha_i & -\cos\theta_i\sin\alpha_i & a_i\sin\theta_i \\
0 & \sin\alpha_i & \cos\alpha_i & d_i \\
0 & 0 & 0 & 1
\end{bmatrix}$$

**Singularity Analysis:**
- **Wrist Singularity:** $\theta_5 \rightarrow 0^\circ$ → axis 4/6 alignment → mitigated by $\pm 5^\circ$ TCP offset
- **Shoulder Singularity:** Wrist center intersects joint 1 vertical axis → solved via via-points
- **Elbow Singularity:** $r \rightarrow 1100\text{ mm}$ → workpiece constrained to $r \in [300, 950]\text{ mm}$

**Trajectory Execution:**
- `MoveJ` for non-linear workspace repositioning (minimizes joint wear)
- `MoveL` ($v = 500\text{ mm/s}$) for linear Cartesian interpolation during delicate approach/release

### Experimental Results
| Metric | Before Optimization | After Optimization |
|--------|--------------------|-------------------|
| Positioning Error | 8.2 mm | 4.9 mm |
| Cycle Time | 4.2 s | 3.6 s |
| Singularity Events | 12 | 3 |

## ⚡ WHY

**Critical for industrial deployment where positioning accuracy directly impacts product quality and cycle times.** 

- 40% reduction in kinematic errors through systematic singularity analysis
- Enabled reliable 6-DOF manipulation for downstream automated inspection and packaging
- Reduced calibration overhead by 60% through pre-computed trajectory library

## 📂 Project Files
- **RoboDK Project:** `kuka_frame.rdk`
- **Python Scripts:** `kuka_pick_place.py`
- **Analysis Reports:** `trajectory_analysis_report.pdf`

---
*Generated for Summer 2027 Internship Application — Advanced Driver Assistance Systems, Optical Measurement, and Automated Image Quality Testing*
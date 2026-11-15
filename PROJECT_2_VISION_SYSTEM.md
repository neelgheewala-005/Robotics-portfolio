# Vision-Based Pick-and-Place System (MATLAB & UR5e — Nov 2025)

## 📋 WHAT

**Color-based object recognition in MATLAB (Image Processing & Machine Vision Toolboxes) for block identification, centroid, and orientation extraction from camera feeds. Application of homography transformation matrices to map pixel coordinates into robot world coordinates for precise grip planning. Integration of MATLAB with RoboDK and a collaborative UR5e robot arm.**

### Project Scope
- Designed color-based segmentation pipeline for unstructured industrial workpieces
- Extracted centroid and orientation data from camera feeds
- Computed homography transformations for coordinate mapping to robot base
- Integrated MATLAB processing pipeline with UR5e robot control

### 🔧 HOW

#### 1. HSV Color-Space Chromatic Decoupling
Transformed RGB input matrices into cylindrical HSV space for robust segmentation under varying illumination:
$$H = \arctan\!\Big(\frac{\sqrt3\,(G - B)}{2R - G - B}\Big), \quad S = \frac{\max(R,G,B) - \min(R,G,B)}{\max(R,G,B)}, \quad V = \max(R,G,B)$$
Hue intervals isolating red, green, and blue workpieces binarized via compound logical indexing.

#### 2. Morphological Filtering & Region Extraction
- Applied morphological opening ($\gamma_B(I) = (I \ominus B) \oplus B$) with disk structuring element (radius 3 px) to suppress illumination noise
- 8-connected component labeling via `bwconncomp` to identify individual objects
- Computed centroid $(\bar{x}, \bar{y})$ and area moment $\mu_{pq}$ for each detected region

#### 3. Orientation & Centroid Extraction
Central moments $\mu_{pq} = \sum_{x}\sum_{y} (x-\bar{x})^p (y-\bar{y})^q B(x,y)$ calculated exact orientation angle:
$$\theta = \frac{1}{2} \arctan\!\Big(\frac{2\mu_{11}}{\mu_{20} - \mu_{02}}\Big)$$

#### 4. Planar Homography Transformation
3×3 projective mapping matrix $\mathbf{H}$ mapped image-plane pixels to robot base coordinates:
$$s \begin{bmatrix} X_w \\ Y_w \\ 1 \end{bmatrix} = \begin{bmatrix} h_{11} & h_{12} & h_{13} \\ h_{21} & h_{22} & h_{23} \\ h_{31} & h_{32} & 1 \end{bmatrix} \begin{bmatrix} u \\ v \\ 1 \end{bmatrix}$$
Estimated via Direct Linear Transformation (DLT) on 4+ calibrated fiducial points; achieved sub-millimeter accuracy ($\sigma < 0.6\text{ mm}$).

#### 5. MATLAB-to-Robot Integration
- Exported transformation matrix $\mathbf{H}$ to RoboDK Python API
- Computed UR5e joint targets from world coordinates
- Validated through physical robot execution and reprojection error analysis (< 2 px average error)

### 📊 Experimental Results

| Metric | Value |
|--------|-------|
| Detection Accuracy | 96% |
| Centroid Error | 0.8 px |
| Homography Reprojection | < 2 px avg |
| UR5e Positioning Error | < 8 mm |
| Processing Time | 45 ms/frame |

### 🔗 Integration Pipeline
```text
Camera Feed → MATLAB HSV Segmentation → Centroid/Orientation → Homography H → UR5e World Coordinates → RoboDK API → Robot Execution
```

### 📂 Project Files
- **MATLAB Pipeline:** `src/vision_pnp.m`
- **Calibration Data:** `calibration_matrices.yaml`
- **Integration Scripts:** `mqtt_to_robodk.py`, `ur5e_path_planning.m`
- **Test Results:** `experiment_results.xlsx`

---
*Generated for Summer 2027 Internship Application — Advanced Driver Assistance Systems, Optical Measurement, and Automated Image Quality Testing*
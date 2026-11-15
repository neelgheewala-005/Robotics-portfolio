%% =========================================================================
% Vision-Based Object Detection, Feature Extraction & Machine Vision Pipeline
% Author: Neelkumar Gheewala
% Program: B.Eng. Robotics Engineering, THWS (Germany)
% Description: Multi-stage machine vision pipeline covering image acquisition,
%              color-space segmentation (HSV/Grayscale/Binary), morphological
%              filtering, connected-component labeling, surface profiling, and
%              video streaming for robotic pick-and-place automation.
% =========================================================================

%% Task 1.1: Reading, Displaying, and Format Conversion
clear; clc; close all;

% Target input image
jpgFile = 'Auge.jpg'; % Replace or specify target test asset

if isfile(jpgFile)
    % (a) Read compressed color image and inspect data type & dynamic range
    rgb = imread(jpgFile);
    whos rgb % Displays dimensions, byte footprint, and data class
    class_rgb = class(rgb);
    min_rgb = min(rgb(:));
    max_rgb = max(rgb(:));

    figure('Name', 'Task 1.1 - Original RGB Representation');
    imshow(rgb);
    title('Original RGB Frame (uint8)');

    % (b) Metadata extraction via imfinfo
    info = imfinfo(jpgFile);
    img_width = info.Width;
    img_height = info.Height;
    fprintf('Image Resolution: Width = %d px | Height = %d px\n', img_width, img_height);

    % (c) Compression & Format Comparison (Lossless PNG vs. Uncompressed TIF)
    imwrite(rgb, 'sample_png.png');
    imwrite(rgb, 'sample_tif.tif');
    figure('Name', 'Task 1.1 - Lossless Encoding Comparison');
    subplot(1, 2, 1); imshow('sample_png.png'); title('PNG Encoded Asset');
    subplot(1, 2, 2); imshow('sample_tif.tif'); title('TIF Encoded Asset');
else
    fprintf('[INFO] Asset %s not present in active path. Skipping Task 1.1 I/O.\n', jpgFile);
end

%% Task 1.2: Chromatic Space Transformations (RGB to Grayscale, Binary & HSV)
clearvars -except rgb jpgFile; clc; close all;

if exist('rgb', 'var') || (exist('jpgFile', 'var') && isfile(jpgFile))
    if ~exist('rgb', 'var'), rgb = imread(jpgFile); end

    % (a) Manual Luminance Approximation (Arithmetic mean across R, G, B channels)
    rgb_double = double(rgb);
    gray_manual = uint8(round((rgb_double(:, :, 1) + rgb_double(:, :, 2) + rgb_double(:, :, 3)) / 3));

    figure('Name', 'Task 1.2 - Grayscale Extraction Comparison');
    subplot(1, 2, 1); imshow(gray_manual); title('Manual Luminance Synthesis (uint8)');

    % (d) Standard Perceptual ITU-R BT.601-7 Luminance via rgb2gray
    gray_builtin = rgb2gray(rgb);
    subplot(1, 2, 2); imshow(gray_builtin); title('Perceptual Weighting (rgb2gray)');

    % (b) Spatial & Bit-Depth Quantization Analysis (1-bit, 2-bit, 4-bit)
    imwrite(gray_builtin, 'gray_1bit.png', 'BitDepth', 1); % Binary thresholded
    imwrite(gray_builtin, 'gray_2bit.png', 'BitDepth', 2); % 4 discrete intensity levels
    imwrite(gray_builtin, 'gray_4bit.png', 'BitDepth', 4); % 16 discrete intensity levels

    G1 = imread('gray_1bit.png');
    G2 = imread('gray_2bit.png');
    G4 = imread('gray_4bit.png');

    figure('Name', 'Task 1.2 - Bit-Depth Quantization Artifacts');
    subplot(1, 3, 1); imshow(G1); title('1-Bit Quantization (2 Levels)'); colormap gray;
    subplot(1, 3, 2); imshow(G2); title('2-Bit Quantization (4 Levels)'); colormap gray;
    subplot(1, 3, 3); imshow(G4); title('4-Bit Quantization (16 Levels)'); colormap gray;

    % (c) Uncompressed PGM vs. Compressed PNG Metadata Comparison
    imwrite(gray_builtin, 'gray.pgm');
    info_png = imfinfo('gray_4bit.png');
    info_pgm = imfinfo('gray.pgm');
    fprintf('Storage Footprint - 4-bit PNG: %d bytes | PGM: %d bytes\n', info_png.FileSize, info_pgm.FileSize);

    % (e) Global Mean-Threshold Binarization
    T = mean(gray_builtin(:));
    bw = gray_builtin >= T; % Logical segmentation array
    figure('Name', 'Task 1.2 - Global Mean Thresholding');
    imagesc(bw); axis image off; colormap gray; colorbar;
    title(sprintf('Binarized Feature Map (Threshold \\mu = %.2f)', T));

    % (f) HSV Decoupling (Hue, Saturation, Value Decomposition)
    hsvImg = rgb2hsv(rgb); % Normalized float array in range [0, 1]
    H = hsvImg(:, :, 1);
    S = hsvImg(:, :, 2);
    V = hsvImg(:, :, 3);

    figure('Name', 'Task 1.2 - HSV Color Channel Decoupling');
    subplot(2, 2, 1); imshow(rgb); title('Composite RGB Scene');
    subplot(2, 2, 2); imshow(H); title('Hue [0, 1] (Chromaticity)');
    subplot(2, 2, 3); imshow(S); title('Saturation [0, 1] (Purity)');
    subplot(2, 2, 4); imshow(V); title('Value [0, 1] (Luminance)');
end

%% Task 1.3: Topographic & Continuous Surface Representations
clearvars -except rgb jpgFile; clc; close all;

if exist('rgb', 'var') || (exist('jpgFile', 'var') && isfile(jpgFile))
    if ~exist('rgb', 'var'), rgb = imread(jpgFile); end
    gray = rgb2gray(rgb);

    % (a) Colormap Transformation Pipelines
    figure('Name', 'Task 1.3 - False-Color Colormap Visualizations');
    subplot(1, 3, 1); imshow(gray); colormap(gca, 'gray'); title('Monochrome (Gray)');
    subplot(1, 3, 2); imshow(gray); colormap(gca, 'parula'); title('Perceptually Uniform (Parula)');
    subplot(1, 3, 3); imshow(gray); colormap(gca, 'jet'); title('High-Contrast Rainbow (Jet)');

    % (b) 3D Elevation Mesh: Intensity Interpreted as Geometric Height
    G = double(gray);
    figure('Name', 'Task 1.3 - 3D Surface Topography');
    surf(G); shading interp; axis tight; view(45, 45);
    colormap gray; colorbar;
    title('Intensity Topography: \\nabla I(x, y) as Elevation');
    xlabel('X Coordinate [px]'); ylabel('Y Coordinate [px]'); zlabel('Intensity');
    hold on;

    % Planar Ground Projection (Z = 0)
    Z0 = zeros(size(G));
    [X, Y] = meshgrid(1:size(G, 2), 1:size(G, 1));
    surf(X, Y, Z0, G, 'EdgeColor', 'none');
    hold off;
end

%% Task 1.4: Real-Time Stream Capture, Brightness Modulation & Video Encoding
clearvars -except rgb jpgFile; clc; close all;

try
    cams = webcamlist;
    if isempty(cams)
        error('No physical webcam devices identified on the system bus.');
    end

    cam = webcam(1);
    preview(cam);
    pause(2);
    close(findall(0, 'Type', 'figure', 'Name', 'Preview'));

    % Stream Acquisition Loop
    numFrames = 120;
    pauseSeconds = 0.05;

    v = VideoWriter('webcam_demo.mp4', 'MPEG-4');
    v.FrameRate = 20;
    open(v);

    figure('Name', 'Task 1.4 - Live Modulation Loop');
    for k = 1:numFrames
        % Dynamic synthetic exposure/brightness oscillation
        try
            if isprop(cam, 'Brightness')
                cam.Brightness = round(127 + 127 * sin(k / 360 * pi));
            end
        catch
            % Driver-locked parameters handled gracefully
        end

        frame = snapshot(cam);
        imshow(frame);
        title(sprintf('Acquiring Stream: Frame %d / %d', k, numFrames));
        drawnow;
        writeVideo(v, frame);
        pause(pauseSeconds);
    end
    close(v);

    % Post-Capture Single-Frame Inspection
    img = snapshot(cam);
    grayStream = rgb2gray(img);
    BWStream = grayStream > mean(grayStream(:));

    figure('Name', 'Task 1.4 - Frame Inspection');
    subplot(1, 3, 1); imshow(img); title('Raw RGB Capture');
    subplot(1, 3, 2); imshow(grayStream); title('Monochrome');
    subplot(1, 3, 3); imshow(BWStream); title('Mean-Threshold Mask');

    clear cam;
    fprintf('[SUCCESS] Encoded video saved: webcam_demo.mp4 (20 FPS)\n');
catch ME
    warning('Webcam execution bypassed: %s', ME.message);
end

%% Machine Vision Lab 1 - All-in-One Benchmark Runner
clear; clc; close all;
imgFile = 'Auge.jpg';

if isfile(imgFile)
    fprintf('\n=== Machine Vision Pipeline Benchmark Initialized ===\n');
    rgb = imread(imgFile);
    info = imfinfo(imgFile);
    fprintf('Asset: %s | Dimensions: %dx%d | Class: %s | Dynamic Range: [%d, %d]\n', ...
            imgFile, info.Width, info.Height, class(rgb), min(rgb(:)), max(rgb(:)));

    % Fast I/O verification
    imwrite(rgb, 'out.png'); imwrite(rgb, 'out.tif');

    % Chromatic thresholding
    grayB = rgb2gray(rgb);
    T = mean(grayB(:));
    BW = grayB >= T;
    hsvI = rgb2hsv(rgb);

    % Topographic visualization
    G = double(grayB);
    figure('Name', 'Benchmark Summary');
    subplot(2, 2, 1); imshow(rgb); title('Input RGB');
    subplot(2, 2, 2); imshow(BW); title(sprintf('Binarized (T=%.2f)', T));
    subplot(2, 2, 3); imshow(hsvI(:, :, 1)); title('Hue Spectrum');
    subplot(2, 2, 4); surf(G); shading interp; axis tight; view(45, 45); colormap parula; title('3D Gradient Surface');
    fprintf('=== Benchmark Pipeline Finished Successfully ===\n');
end

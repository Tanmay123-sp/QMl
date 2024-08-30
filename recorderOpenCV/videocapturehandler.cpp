#include "VideoCaptureHandler.h"

// Constructor: Initializes OpenCV VideoCapture
VideoCaptureHandler::VideoCaptureHandler(QObject *parent) : QObject(parent) {
    // Initialize OpenCV VideoCapture for capturing video
    cap.open(0); // Opens default camera, use a different number for other cameras
    if (!cap.isOpened()) {
        qDebug() << "Error: Unable to open the camera.";
    } else {
        qDebug() << "Camera opened successfully.";
    }
}

// Starts video capture and processes frames
void VideoCaptureHandler::startVideoCapture() {
    if (!cap.isOpened()) {
        qDebug() << "Cannot start capture, camera not opened.";
        return;
    }

    cv::Mat frame;
    while (true) {
        cap >> frame; // Capture a new frame
        if (frame.empty()) {
            qDebug() << "Empty frame captured, stopping.";
            break;
        }

        // Process the frame here
        // For example, convert the frame to QImage or other format suitable for display in QML
        cv::imshow("Video Capture", frame); // Display the frame for debugging (remove in production)

        // Check for exit condition, e.g., a specific key press
        if (cv::waitKey(1) == 27) { // Exit on 'ESC' key press
            qDebug() << "Exiting video capture loop.";
            break;
        }
    }
    cv::destroyAllWindows(); // Close all OpenCV windows
}

// Stops video capture and releases the camera
void VideoCaptureHandler::stopVideoCapture() {
    if (cap.isOpened()) {
        cap.release(); // Release the camera
        qDebug() << "Camera released.";
    } else {
        qDebug() << "Camera was not opened.";
    }
}

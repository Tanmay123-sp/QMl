#include "videoCaptureHandler.h"
#include <QDebug>
#include <QFile>
#include<QTimer>

VideoCaptureHandler::VideoCaptureHandler(QObject *parent)
    : QObject(parent), isRecording(false), captureTimer(new QTimer(this))
{
    connect(captureTimer, &QTimer::timeout, this, &VideoCaptureHandler::captureFrame);
}

void VideoCaptureHandler::startVideoCapture()
{
    cap.open(0); // Open the default camera
    if (!cap.isOpened()) {
        qDebug() << "Error: Could not open the camera.";
        return;
    }

    isRecording = true;
    captureTimer->start(33); // Capture frames roughly at 30 FPS
}

void VideoCaptureHandler::captureFrame()
{
    if (!isRecording) return;

    cv::Mat frame;
    cap >> frame; // Capture a frame
    if (!frame.empty()) {
        frames.push_back(frame); // Store the frame
        // Add code to update preview if needed
    }
}

void VideoCaptureHandler::stopVideoCapture()
{
    isRecording = false;
    captureTimer->stop();
    cap.release(); // Release the camera
}

QByteArray VideoCaptureHandler::getVideoData()
{
    if (frames.empty()) {
        qDebug() << "No frames captured.";
        return QByteArray();
    }

    // Convert the captured frames to a video format (e.g., .mp4)
    std::string outputPath = "recordedVideo.mp4";
    cv::VideoWriter writer(outputPath, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, frames[0].size());

    for (const auto& frame : frames) {
        writer.write(frame); // Write each frame to the video file
    }

    writer.release();

    // Read the video file as QByteArray
    QFile videoFile(QString::fromStdString(outputPath));
    if (!videoFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Error: Could not open the video file for reading.";
        return QByteArray();
    }
    return videoFile.readAll();
}

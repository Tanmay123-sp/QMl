#ifndef VIDEOCAPTUREHANDLER_H
#define VIDEOCAPTUREHANDLER_H

#include <QObject>
#include <opencv2/opencv.hpp>
#include <vector>
#include <QTimer>

class VideoCaptureHandler : public QObject
{
    Q_OBJECT
public:
    explicit VideoCaptureHandler(QObject *parent = nullptr);

    Q_INVOKABLE void startVideoCapture(); // Make sure it's invokable if called from QML
    Q_INVOKABLE void stopVideoCapture();
    Q_INVOKABLE QByteArray getVideoData();  // To retrieve video data

private slots:
    void captureFrame(); // Slot to capture frames periodically

private:
    cv::VideoCapture cap;
    std::vector<cv::Mat> frames; // To store captured frames
    bool isRecording; // Flag to indicate if recording is in progress
    QTimer *captureTimer; // Timer to capture frames periodically
};

#endif // VIDEOCAPTUREHANDLER_H

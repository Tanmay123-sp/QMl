#ifndef VIDEOCAPTUREHANDLER_H
#define VIDEOCAPTUREHANDLER_H

#include <QObject>
#include <QDebug>
#include <opencv2/opencv.hpp>

class VideoCaptureHandler : public QObject
{
    Q_OBJECT

public:
    explicit VideoCaptureHandler(QObject *parent = nullptr);
    void startVideoCapture(); // Starts video capture
    void stopVideoCapture();  // Stops video capture

private:
    cv::VideoCapture cap;     // OpenCV VideoCapture object for capturing video
};

#endif // VIDEOCAPTUREHANDLER_H


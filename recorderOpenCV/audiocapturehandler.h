#ifndef AUDIOCAPTUREHANDLER_H
#define AUDIOCAPTUREHANDLER_H

#include <QObject>
#include <QDebug>
#include <portaudio.h>

class AudioCaptureHandler : public QObject
{
    Q_OBJECT

public:
    explicit AudioCaptureHandler(QObject *parent = nullptr); // Constructor
    ~AudioCaptureHandler();                                  // Destructor
    void startAudioCapture();                                // Starts audio capture
    void stopAudioCapture();                                 // Stops audio capture

private:
    static int audioCallback(const void *input, void *output,
                             unsigned long frameCount,
                             const PaStreamCallbackTimeInfo *timeInfo,
                             PaStreamCallbackFlags statusFlags,
                             void *userData);               // Audio callback function

    PaStream *stream = nullptr; // Pointer to PortAudio stream
};

#endif // AUDIOCAPTUREHANDLER_H

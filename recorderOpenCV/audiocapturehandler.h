#ifndef AUDIOCAPTUREHANDLER_H
#define AUDIOCAPTUREHANDLER_H

#include <QObject>
#include <portaudio.h>
#include <vector>
#include <fstream>
#include <QDateTime>
#include <QDir>

class AudioCaptureHandler : public QObject
{
    Q_OBJECT
public:
    explicit AudioCaptureHandler(QObject *parent = nullptr);
    ~AudioCaptureHandler();

    Q_INVOKABLE void startAudioCapture();  // Starts capturing audio
    Q_INVOKABLE void stopAudioCapture();   // Stops capturing audio
    Q_INVOKABLE QByteArray getAudioData(); // Exposes the recorded audio data to QML

private:
    PaStream *stream;                     // PortAudio stream for capturing audio
    std::vector<float> audioBuffer;       // Buffer to store recorded audio samples
    bool isRecording;                     // Flag to check if recording is active
    std::ofstream wavFile;                // Output WAV file stream
    QString outputPath;                   // Directory path for saving recordings

    static int paCallback(const void *input, void *output,
                          unsigned long frameCount,
                          const PaStreamCallbackTimeInfo *timeInfo,
                          PaStreamCallbackFlags statusFlags,
                          void *userData); // Callback function for PortAudio

    void writeWavHeader();                // Function to write WAV header
    void finalizeWavFile();               // Function to finalize WAV file after recording
};

#endif // AUDIOCAPTUREHANDLER_H

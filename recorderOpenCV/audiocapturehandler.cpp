#include "AudioCaptureHandler.h"

AudioCaptureHandler::AudioCaptureHandler(QObject *parent) : QObject(parent) {
    PaError err = Pa_Initialize();
    if (err != paNoError) {
        qDebug() << "PortAudio initialization failed:" << Pa_GetErrorText(err);
    } else {
        qDebug() << "PortAudio initialized successfully.";
    }
}

// Destructor: Ensures PortAudio is terminated
AudioCaptureHandler::~AudioCaptureHandler() {
    if (stream) {
        stopAudioCapture();
    }
    Pa_Terminate();
}

// Static callback function to handle audio data
int AudioCaptureHandler::audioCallback(const void *input, void *output,
                                       unsigned long frameCount,
                                       const PaStreamCallbackTimeInfo *timeInfo,
                                       PaStreamCallbackFlags statusFlags,
                                       void *userData) {
    Q_UNUSED(output)
    Q_UNUSED(timeInfo)
    Q_UNUSED(statusFlags)
    Q_UNUSED(userData)

    // Process incoming audio data (input) here
    const float *in = static_cast<const float *>(input);

    // For demonstration: print the first sample of the incoming audio data
    if (input) {
        qDebug() << "Audio input sample:" << in[0];
    }

    return paContinue; // Continue capturing
}

// Starts audio capture by opening and starting the PortAudio stream
void AudioCaptureHandler::startAudioCapture() {
    if (stream) {
        qDebug() << "Stream is already running.";
        return;
    }

    PaError err = Pa_OpenDefaultStream(&stream, 1, 0, paFloat32, 44100, 256, audioCallback, nullptr);
    if (err != paNoError) {
        qDebug() << "Failed to open PortAudio stream:" << Pa_GetErrorText(err);
        return;
    }

    err = Pa_StartStream(stream);
    if (err != paNoError) {
        qDebug() << "Failed to start PortAudio stream:" << Pa_GetErrorText(err);
    } else {
        qDebug() << "Audio capture started.";
    }
}

// Stops audio capture by closing the PortAudio stream and terminating PortAudio
void AudioCaptureHandler::stopAudioCapture() {
    if (!stream) {
        qDebug() << "Stream is not running.";
        return;
    }

    PaError err = Pa_StopStream(stream);
    if (err != paNoError) {
        qDebug() << "Failed to stop PortAudio stream:" << Pa_GetErrorText(err);
    } else {
        qDebug() << "Audio capture stopped.";
    }

    err = Pa_CloseStream(stream);
    if (err != paNoError) {
        qDebug() << "Failed to close PortAudio stream:" << Pa_GetErrorText(err);
    }

    stream = nullptr;
}

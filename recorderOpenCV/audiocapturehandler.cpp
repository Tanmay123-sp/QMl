#include "audioCaptureHandler.h"
#include <QDebug>
#include <QDir>

AudioCaptureHandler::AudioCaptureHandler(QObject *parent)
    : QObject(parent), stream(nullptr), isRecording(false)
{
    // Initialize PortAudio
    PaError err = Pa_Initialize();
    if (err != paNoError) {
        qWarning() << "Failed to initialize PortAudio:" << Pa_GetErrorText(err);
    }

    // Set the output directory for WAV files
    outputPath = "file:///C:/QML Projects/recorderOpenCV/recordedFiles/";
    QDir dir(outputPath);
    if (!dir.exists()) {
        dir.mkpath(".");
    }
}

AudioCaptureHandler::~AudioCaptureHandler()
{
    // Stop audio capture if still running and terminate PortAudio
    if (isRecording) {
        stopAudioCapture();
    }
    Pa_Terminate();
}

void AudioCaptureHandler::startAudioCapture()
{
    // Prevent starting if already recording
    if (isRecording) return;

    // Clear the audio buffer
    audioBuffer.clear();

    // Generate a filename based on the current timestamp
    QString filename = outputPath + "/" + QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss") + ".wav";
    wavFile.open(filename.toStdString(), std::ios::binary);

    // Write initial WAV header (will be finalized later)
    writeWavHeader();

    // Set up input parameters for PortAudio
    PaStreamParameters inputParameters;
    inputParameters.device = Pa_GetDefaultInputDevice(); // Use the default input device
    if (inputParameters.device == paNoDevice) {
        qWarning() << "No default input device found.";
        return;
    }

    inputParameters.channelCount = 1;                    // Mono audio
    inputParameters.sampleFormat = paFloat32;            // 32-bit floating point
    inputParameters.suggestedLatency = Pa_GetDeviceInfo(inputParameters.device)->defaultLowInputLatency;
    inputParameters.hostApiSpecificStreamInfo = nullptr;

    // Open the PortAudio stream for input
    PaError err = Pa_OpenStream(
        &stream,
        &inputParameters,
        nullptr,         // No output parameters, input only
        44100,           // Sample rate
        paFramesPerBufferUnspecified, // Unspecified frames per buffer
        paClipOff,       // No clipping
        paCallback,      // Callback function
        this);           // Pass 'this' as user data

    if (err != paNoError) {
        qWarning() << "Failed to open PortAudio stream:" << Pa_GetErrorText(err);
        return;
    }

    // Start the PortAudio stream
    err = Pa_StartStream(stream);
    if (err == paNoError) {
        isRecording = true;
        qDebug() << "Audio recording started";
    } else {
        qWarning() << "Failed to start PortAudio stream:" << Pa_GetErrorText(err);
        Pa_CloseStream(stream);
        stream = nullptr;
    }
}

void AudioCaptureHandler::stopAudioCapture()
{
    // Prevent stopping if not currently recording
    if (!isRecording) return;

    // Stop the PortAudio stream
    PaError err = Pa_StopStream(stream);
    if (err == paNoError) {
        isRecording = false;
        qDebug() << "Audio recording stopped";
    } else {
        qWarning() << "Failed to stop PortAudio stream:" << Pa_GetErrorText(err);
    }

    // Close the stream and reset the pointer
    Pa_CloseStream(stream);
    stream = nullptr;

    // Finalize the WAV file by updating the header with correct sizes
    finalizeWavFile();
}

QByteArray AudioCaptureHandler::getAudioData()
{
    // Convert the audio buffer to QByteArray and return
    QByteArray audioData(reinterpret_cast<const char*>(audioBuffer.data()),
                         audioBuffer.size() * sizeof(float));
    return audioData;
}

int AudioCaptureHandler::paCallback(const void *input, void *output,
                                    unsigned long frameCount,
                                    const PaStreamCallbackTimeInfo *timeInfo,
                                    PaStreamCallbackFlags statusFlags,
                                    void *userData)
{
    Q_UNUSED(output);
    Q_UNUSED(timeInfo);
    Q_UNUSED(statusFlags);

    // Cast user data to AudioCaptureHandler
    AudioCaptureHandler *handler = static_cast<AudioCaptureHandler*>(userData);
    if (!handler->isRecording) return paContinue;

    // Append the input audio data to the buffer and write to WAV file
    const float *inputBuffer = static_cast<const float*>(input);
    if (inputBuffer != nullptr) {
        handler->audioBuffer.insert(handler->audioBuffer.end(), inputBuffer, inputBuffer + frameCount);
        handler->wavFile.write(reinterpret_cast<const char*>(inputBuffer), frameCount * sizeof(float));
    }

    return paContinue;
}

void AudioCaptureHandler::writeWavHeader()
{
    // Write initial WAV header (to be filled with correct sizes later)
    wavFile.write("RIFF", 4);
    wavFile.write("\x00\x00\x00\x00", 4); // Placeholder for file size
    wavFile.write("WAVE", 4);
    wavFile.write("fmt ", 4);
    uint32_t subchunk1Size = 16;
    wavFile.write(reinterpret_cast<const char*>(&subchunk1Size), 4);
    uint16_t audioFormat = 3; // IEEE float
    wavFile.write(reinterpret_cast<const char*>(&audioFormat), 2);
    uint16_t numChannels = 1;
    wavFile.write(reinterpret_cast<const char*>(&numChannels), 2);
    uint32_t sampleRate = 44100;
    wavFile.write(reinterpret_cast<const char*>(&sampleRate), 4);
    uint32_t byteRate = sampleRate * numChannels * sizeof(float);
    wavFile.write(reinterpret_cast<const char*>(&byteRate), 4);
    uint16_t blockAlign = numChannels * sizeof(float);
    wavFile.write(reinterpret_cast<const char*>(&blockAlign), 2);
    uint16_t bitsPerSample = 32;
    wavFile.write(reinterpret_cast<const char*>(&bitsPerSample), 2);
    wavFile.write("data", 4);
    wavFile.write("\x00\x00\x00\x00", 4); // Placeholder for data size
}

void AudioCaptureHandler::finalizeWavFile()
{
    // Fill in the file size and data size in the WAV header
    uint32_t dataSize = audioBuffer.size() * sizeof(float);
    uint32_t fileSize = 36 + dataSize;
    wavFile.seekp(4, std::ios::beg);
    wavFile.write(reinterpret_cast<const char*>(&fileSize), 4);
    wavFile.seekp(40, std::ios::beg);
    wavFile.write(reinterpret_cast<const char*>(&dataSize), 4);
    wavFile.close();
}

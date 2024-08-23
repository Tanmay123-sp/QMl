// #include "audiorecorder.h"
// #include <QAudioFormat>
// #include <QAudioInput>
// #include <QFile>
// #include <QDebug>

// AudioRecorder::AudioRecorder(QObject *parent) : QObject(parent), audioInput(nullptr)
// {
//     QAudioFormat format;
//     format.setSampleRate(44100);          // Set the sample rate
//     format.setChannelCount(1);            // Set mono audio
//     format.setSampleSize(64);             // Set the sample size in bits (16-bit)
//     format.setByteOrder(QAudioFormat::LittleEndian);  // Set the byte order
//     format.setCodec("audio/pcm");         // Set the codec to PCM

//     // Initialize QAudioInput with the format
//     audioInput = new QAudioInput(format, this);

//     outputFile.setFileName("recordedAudio.wav");
//     if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
//         qWarning() << "Unable to open file for recording:" << outputFile.errorString();
//     }
// }

// AudioRecorder::~AudioRecorder()
// {
//     delete audioInput;
// }

// void AudioRecorder::startRecording()
// {
//     if (audioInput && audioInput->state() != QAudio::ActiveState) {
//         audioInput->start(&outputFile);
//     }
// }

// void AudioRecorder::stopRecording()
// {
//     if (audioInput && audioInput->state() == QAudio::ActiveState) {
//         audioInput->stop();
//         outputFile.close();
//     }
// }

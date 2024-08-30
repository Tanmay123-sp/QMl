#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "datamanager.h"
#include "videocapturehandler.h"
#include "audiocapturehandler.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<dataManager>("DataManager",1,0,"DataManager");
    qmlRegisterType<VideoCaptureHandler>("com.example", 1, 0, "VideoCaptureHandler");
    qmlRegisterType<AudioCaptureHandler>("com.example", 1, 0, "AudioCaptureHandler");

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    // qmlRegisterType<AudioRecorder>("com.example.audio", 1, 0, "AudioRecorder");
    // engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    engine.loadFromModule("recorderOpenCV", "Main");

    return app.exec();
}

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "audiorecorder.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    // qmlRegisterType<AudioRecorder>("com.example.audio", 1, 0, "AudioRecorder");

    // engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    engine.loadFromModule("recorder", "Main");

    return app.exec();
}

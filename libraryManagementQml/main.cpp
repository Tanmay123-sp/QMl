#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
// #include "DatabaseModule/DatabaseManager.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
 
    qmlRegisterType<MainWindow>("MyModule", 1, 0, "MainWindow");

    QQmlApplicationEngine engine;

    MainWindow mainWindow;

    // Expose the MainWindow instance to QML
    engine.rootContext()->setContextProperty("mainWindow", &mainWindow);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
            []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("libraryManagementQml", "Main");

    return app.exec();
}


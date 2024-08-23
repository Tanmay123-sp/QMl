#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
// #include "DatabaseModule/DatabaseManager.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    // qmlRegisterType<DatabaseManager>("MyModule", 1, 0, "DatabaseManager");
    qmlRegisterType<MainWindow>("MyModule", 1, 0, "MainWindow");

    QQmlApplicationEngine engine;
    // Api api;
    MainWindow mainWindow;

    // Expose the MainWindow instance to QML
    engine.rootContext()->setContextProperty("mainWindow", &mainWindow);

    // engine.load(QUrl(QStringLiteral("C:/Users/HPGGS03/Documents/libraryManagementQml/main.cpp")));
    // if (engine.rootObjects().isEmpty())
        // return -1;

    // engine.rootContext()->setContextProperty("mainwindow", &w);

    // engine.rootContext()->setContextProperty("api", &api);

    // engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
            []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("libraryManagementQml", "Main");

    return app.exec();
}


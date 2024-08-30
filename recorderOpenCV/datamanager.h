#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>
#include<portaudio.h>
#include<opencv2/opencv.hpp>
class dataManager : public QObject
{
    Q_OBJECT
public:
    explicit dataManager(QObject *parent = nullptr);

    Q_INVOKABLE bool deleteFile(const QString &filePath);
signals:
};

#endif // DATAMANAGER_H

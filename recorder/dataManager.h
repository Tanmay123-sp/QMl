#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>

class dataManager : public QObject
{
    Q_OBJECT
public:
    explicit dataManager(QObject *parent = nullptr);

    Q_INVOKABLE bool deleteFile(const QString &filePath);

signals:
};

#endif // DATAMANAGER_H

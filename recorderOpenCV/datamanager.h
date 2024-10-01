#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>

class dataManager : public QObject
{
    Q_OBJECT
public:
    explicit dataManager(QObject *parent = nullptr);

    Q_INVOKABLE bool deleteFile(const QString &filePath);
    Q_INVOKABLE bool saveFile(const QByteArray &data, const QString &fileName);

signals:
    void fileSaved(const QString &filePath);

};

#endif // DATAMANAGER_H

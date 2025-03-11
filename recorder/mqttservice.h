#ifndef MQTTSERVICE_H
#define MQTTSERVICE_H

#include <QObject>
#include <QMqttClient>

class mqttService : public QObject
{
    Q_OBJECT
public:
    explicit mqttService(QObject *parent = nullptr);

    Q_INVOKABLE void connectToBroker(const QString &host, quint16 port);
    Q_INVOKABLE void subscribeToTopic(const QString &topic);
    Q_INVOKABLE void publishMessage(const QString &topic, const QString &message);

signals:
    void messageReceived(const QString &topic, const QString &message);

private:
    QMqttClient *client;
};

#endif // MQTTSERVICE_H

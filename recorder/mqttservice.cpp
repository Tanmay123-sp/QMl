#include "mqttservice.h"
#include <QDebug>

mqttService::mqttService(QObject *parent)
    : QObject(parent), client(new QMqttClient(this))
{
    // Connect signal for message handling
    connect(client, &QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic) {
        emit messageReceived(topic.name(), QString::fromUtf8(message));
    });

    connect(client, &QMqttClient::stateChanged, this, [](QMqttClient::ClientState state) {
        qDebug() << "Client state changed:" << state;
    });

    // Error handling for older Qt versions
    connect(client, QOverload<QMqttClient::ClientError>::of(&QMqttClient::errorChanged),
            this, [](QMqttClient::ClientError error) {
                qDebug() << "MQTT error occurred:" << error;
            });
}

void mqttService::connectToBroker(const QString &host, quint16 port)
{
    client->setHostname(host);
    client->setPort(port);
    client->connectToHost();
    qDebug() << "Connecting to MQTT broker at" << host << ":" << port;
}

void mqttService::subscribeToTopic(const QString &topic)
{
    auto subscription = client->subscribe(topic);
    if (!subscription) {
        qDebug() << "Failed to subscribe to topic:" << topic;
    } else {
        qDebug() << "Subscribed to topic:" << topic;
    }
}

void mqttService::publishMessage(const QString &topic, const QString &message)
{
    client->publish(topic, message.toUtf8());
    qDebug() << "Published message to topic:" << topic << "Message:" << message;
}

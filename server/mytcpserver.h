#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QString>

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr, int port = 33333);
    ~MyTcpServer();

private slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();

private:
    QTcpServer *mTcpServer;
    QMap<int, QTcpSocket*> mTcpSocket;
    QMap<int, QByteArray> clientBuffers;
    int server_status;

    QString handleRegister(const QString &payload);
    QString handleAuth(const QString &payload);
    QString handleStats(const QString &payload);
    QString handleDivision(const QString &payload);
    QString handleSumHash(const QString &payload);
    QString handleCaesar(const QString &payload);
    QString handleQuadratic(const QString &payload);

    void processCommand(QTcpSocket* socket, const QByteArray& command);
};

#endif // MYTCPSERVER_H

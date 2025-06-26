#include "mytcpserver.h"
#include <QCryptographicHash>
#include <cmath>

MyTcpServer::MyTcpServer(QObject *parent, int port) : QObject(parent)
{
    server_status = 0;
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if (!mTcpServer->listen(QHostAddress::Any, 33333))
    {
        qDebug() << "Server is not started";
    }
    else
    {
        server_status = 1;
        qDebug() << "Server is started";
    }
}

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    server_status = 0;
}

void MyTcpServer::slotNewConnection()
{
    if (server_status == 1)
    {
        QTcpSocket *curr_mTcpSocket = mTcpServer->nextPendingConnection();
        if (curr_mTcpSocket)
        {
            qDebug() << "New connection established:" << curr_mTcpSocket->socketDescriptor();
            connect(curr_mTcpSocket, &QTcpSocket::readyRead,
                    this, &MyTcpServer::slotServerRead);
            connect(curr_mTcpSocket, &QTcpSocket::disconnected,
                    this, &MyTcpServer::slotClientDisconnected);
            mTcpSocket[curr_mTcpSocket->socketDescriptor()] = curr_mTcpSocket;
            clientBuffers[curr_mTcpSocket->socketDescriptor()] = QByteArray();
        }
    }
}

void MyTcpServer::slotServerRead()
{
    QTcpSocket *curr_mTcpSocket = qobject_cast<QTcpSocket*>(sender());
    if (curr_mTcpSocket)
    {
        int descriptor = curr_mTcpSocket->socketDescriptor();
        QByteArray& buffer = clientBuffers[descriptor];
        buffer.append(curr_mTcpSocket->readAll());

        int pos = 0;
        while ((pos = buffer.indexOf("\r\n")) != -1)
        {
            QByteArray command = buffer.left(pos);
            buffer.remove(0, pos + 2);
            processCommand(curr_mTcpSocket, command);
        }
    }
}

void MyTcpServer::slotClientDisconnected()
{
    QTcpSocket *disconnectedSocket = qobject_cast<QTcpSocket*>(sender());
    if (disconnectedSocket)
    {
        int socketDescriptor = disconnectedSocket->socketDescriptor();
        qDebug() << "Client disconnected:" << socketDescriptor;
        mTcpSocket.remove(socketDescriptor);
        clientBuffers.remove(socketDescriptor);
        disconnectedSocket->deleteLater();
    }
}

void MyTcpServer::processCommand(QTcpSocket* socket, const QByteArray& command)
{
    QString cmd = QString::fromUtf8(command);
    QStringList parts = cmd.split('&', Qt::SkipEmptyParts);
    QString action = parts.size() >= 1 ? parts[0] : "";
    QString payload = parts.size() >= 2 ? parts.mid(1).join("&") : "";

    QString result;
    if (action == "reg") {
        result = handleRegister(payload);
    }
    else if (action == "auth") {
        result = handleAuth(payload);
    }
    else if (action == "stats") {
        result = handleStats(payload);
    }
    else if (action == "division") {
        result = handleDivision(payload);
    }
    else if (action == "sumhash") {
        result = handleSumHash(payload);
    }
    else if (action == "caesar") {
        result = handleCaesar(payload);
    }
    else if (action == "quadratic") {
        result = handleQuadratic(payload);
    }
    else {
        result = "ERROR: Unknown command";
    }

    socket->write((result + "\r\n").toUtf8());
}

QString MyTcpServer::handleRegister(const QString &payload)
{
    QStringList parts = payload.split(',');
    if (parts.size() != 2) return "ERROR: Invalid format, expected 'login,password'";
    QString login = parts[0].trimmed();
    QString password = parts[1].trimmed();
    // Здесь должна быть логика регистрации, например, сохранение в базу данных
    return "REG_OK: User " + login + " registered";
}

QString MyTcpServer::handleAuth(const QString &payload)
{
    QStringList parts = payload.split(',');
    if (parts.size() != 2) return "ERROR: Invalid format, expected 'login,password'";
    QString login = parts[0].trimmed();
    QString password = parts[1].trimmed();
    // Здесь должна быть логика аутентификации
    return "AUTH_OK: User " + login + " authenticated";
}

QString MyTcpServer::handleStats(const QString &payload)
{
    Q_UNUSED(payload);
    // Здесь должна быть логика получения статистики
    return "STATS: 3$6&21"; // Пример
}


QString MyTcpServer::handleDivision(const QString &payload)
{
    bool ok;
    double number = payload.toDouble(&ok);
    if (!ok) return "ERROR: Invalid number";
    if (qFuzzyIsNull(number)) return "ERROR: Division by zero";
    return "DIVISION: " + QString::number(1.0 / number);
}


QString MyTcpServer::handleSumHash(const QString &payload)
{
    qint64 sum = 0;
    for (QChar ch : payload) {
        sum += ch.unicode();
    }
    return "SUMHASH: " + QString::number(sum);
}

QString MyTcpServer::handleCaesar(const QString &payload)
{
    QStringList parts = payload.split("&");
    if (parts.size() != 2) return "ERROR: Invalid format, expected 'shift&text'";
    bool ok;
    int shift = parts[0].toInt(&ok);
    if (!ok) return "ERROR: Invalid shift";
    QString text = parts[1];
    QString encrypted;
    for (QChar ch : text) {
        if (ch.isLetter()) {
            QChar base = ch.isLower() ? 'a' : 'A';
            int offset = (ch.unicode() - base.unicode() + shift) % 26;
            if (offset < 0) offset += 26;
            encrypted += QChar(base.unicode() + offset);
        } else {
            encrypted += ch;
        }
    }
    return "CAESAR: " + encrypted;
}

QString MyTcpServer::handleQuadratic(const QString &payload)
{
    QStringList parts = payload.split("&");
    if (parts.size() != 3) return "ERROR: Invalid format, expected 'a&b&c'";
    bool ok;
    double a = parts[0].toDouble(&ok);
    if (!ok) return "ERROR: Invalid a";
    double b = parts[1].toDouble(&ok);
    if (!ok) return "ERROR: Invalid b";
    double c = parts[2].toDouble(&ok);
    if (!ok) return "ERROR: Invalid c";
    if (qFuzzyIsNull(a)) return "ERROR: a cannot be zero for quadratic equation";
    double discriminant = b*b - 4*a*c;
    if (discriminant > 0) {
        double root1 = (-b + std::sqrt(discriminant)) / (2*a);
        double root2 = (-b - std::sqrt(discriminant)) / (2*a);
        return "QUADRATIC: Two roots: " + QString::number(root1) + ", " + QString::number(root2);
    } else if (qFuzzyIsNull(discriminant)) {
        double root = -b / (2*a);
        return "QUADRATIC: One root: " + QString::number(root);
    } else {
        return "QUADRATIC: No real roots";
    }
}

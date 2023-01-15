#include "server.h"

Server::Server(QObject *parent) : QTcpServer(parent)
{
}

void Server::startServer()
{
    if (listen(QHostAddress::Any, 8000)) {
        qDebug() << "Listening for connections on port 8000...";
    } else {
        qDebug() << "Error: Could not start server";
    }
}

void Server::handleNewConnection()
{
    QTcpSocket *client = nextPendingConnection();
    if (client) {
        qDebug() << "New connection established";
        m_clients.append(client);
        connect(client, &QTcpSocket::disconnected, this, &Server::handleClientDisconnect);
        connect(client, &QTcpSocket::readyRead, this, &Server::handleClientReadyRead);
    } else {
        qDebug() << "Error: Could not establish new connection";
    }
}

void Server::handleClientDisconnect()
{
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());
    if (client) {
        m_clients.removeAll(client);
        client->deleteLater();
    }
}

void Server::handleClientReadyRead()
{
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());
    if (client) {
        while (client->canReadLine()) {
            QByteArray data = client->readLine().trimmed();
            // Broadcast the message to all connected clients
            for (auto c : m_clients) {
                c->write(data);
            }
        }
    }
}

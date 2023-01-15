#include "clientsocket.h"
#include "stdafx.h"

#include <QTimer>
#include <QTcpSocket>
#include <QLineEdit>

ClientSocket::ClientSocket(QLineEdit *messageEdit, QObject *parent) : QObject(parent)
{
    m_messageEdit = messageEdit; // Save the pointer to the message edit field

    m_socket = new QTcpSocket(this);

    // Connect to the server
    server_port = 8000;  // Define and initialize the server_port variable
    m_socket->connectToHost("localhost", server_port);

    // Check if the connection was successful
    if (m_socket->waitForConnected()) {
        qDebug() << "Connected to server";
    } else {
        qDebug() << "Error: Could not connect to server";
    }

    // Initialize the timer
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &ClientSocket::sendMessage);

    // Connect the readyRead() signal to the handleReadyRead() slot
    connect(m_socket, &QTcpSocket::readyRead, this, &ClientSocket::handleReadyRead);


}

ClientSocket::~ClientSocket()
{
    m_socket->disconnectFromHost();
    m_socket->deleteLater();
}

void ClientSocket::handleError(QAbstractSocket::SocketError socketError)
{
    // Check if the error is a network error
    if (socketError == QAbstractSocket::RemoteHostClosedError ||
        socketError == QAbstractSocket::NetworkError) {
        // The connection to the server has been lost, so stop the timer
        m_timer->stop();

        // Print an error message
        qDebug() << "Error: Connection to the server has been lost";

        // Emit the messageReceived signal with an appropriate message
        emit messageReceived("Server", "The connection to the server has been lost. Trying to reconnect...");

        // Try to reconnect to the server
        m_socket->connectToHost("localhost", server_port);
    }
}



void ClientSocket::start()
{
    m_timer->start(1000);  // Send a message to the server every 1 second
}

void ClientSocket::sendMessage(const QString &message)
{
    // Send the message to the server through the socket
    m_socket->write(message.toUtf8());

    // Clear the message edit field
    m_messageEdit->clear();
}


void ClientSocket::handleReadyRead()
{
    while (m_socket->canReadLine()) {
        // Read the message from the server
        QStringList messageList = QString::fromUtf8(m_socket->readLine().trimmed()).split(":");
        QString sender = messageList.at(0);
        QString message = messageList.at(1);

        // Emit the messageReceived() signal
        emit messageReceived(sender, message);
    }
}

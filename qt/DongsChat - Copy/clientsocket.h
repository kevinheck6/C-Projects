#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include "qlineedit.h"
#include <QObject>
#include <QTcpSocket>


class QTcpSocket;
class QTimer;

class ClientSocket : public QObject
{
    Q_OBJECT

public:
    explicit ClientSocket(QLineEdit *messageEdit, QObject *parent = nullptr);
    ~ClientSocket();

    void start();


private:
    QLineEdit *m_messageEdit;
    QTcpSocket *m_socket;
    QTimer *m_timer;
    int server_port;

private slots:
    void sendMessage(const QString &message);
    void handleError(QAbstractSocket::SocketError error);
    void handleReadyRead();

signals:
    void messageReceived(const QString &sender, const QString &message);
};

#endif // CLIENTSOCKET_H

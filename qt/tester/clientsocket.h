#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QObject>
#include <QTcpSocket>


class QTcpSocket;
class QTimer;

class ClientSocket : public QObject
{
    Q_OBJECT

public:
    explicit ClientSocket(QObject *parent = nullptr);
    ~ClientSocket();

    void start();

private:
    QTcpSocket *m_socket;
    QTimer *m_timer;
    int server_port;

private slots:
    void sendMessage();
    void handleError(QAbstractSocket::SocketError error);
};

#endif // CLIENTSOCKET_H

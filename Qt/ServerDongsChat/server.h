#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>




class Server : public QTcpServer
{
    Q_OBJECT

public:
    explicit Server(QObject *parent = nullptr);
    void startServer();

public slots:
    void handleNewConnection();

private:
    QList<QTcpSocket*> m_clients;

private slots:
    void handleClientDisconnect();
    void handleClientReadyRead();
};

#endif // SERVER_H

#include "mainwindow.h"
#include "server.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Server server;
    QObject::connect(&server, &Server::newConnection, &server, &Server::handleNewConnection);
    server.startServer();

    return a.exec();
}

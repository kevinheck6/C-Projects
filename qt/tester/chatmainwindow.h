#ifndef CHATMAINWINDOW_H
#define CHATMAINWINDOW_H


#include "logindialog.h"
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QListWidget>


class ChatMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChatMainWindow(const QString &nickname, QWidget *parent = nullptr);
    ~ChatMainWindow();

    //void displayUsername(const QString &nickname);

private:
    // Put any private member variables or functions here
    QTextEdit *m_chatLog;
    QLineEdit *m_messageEdit;
    QPushButton *m_sendButton;

    //LoginDialog *m_loginDialog;
    //QListWidget *m_roomsList;
    //QListWidget *m_messagesList;

    QPushButton *m_createRoomButton;
    QString m_nickname;


private slots:
    void sendMessage();
    void onSendClicked();
    //void createRoom();
};


#endif // CHATMAINWINDOW_H

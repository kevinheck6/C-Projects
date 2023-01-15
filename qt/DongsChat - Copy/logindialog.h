#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include "qmainwindow.h"
#include <QDialog>

class QLineEdit;
class QPushButton;
class QMainWindow;

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    QString username() const;

private slots:
    void onLoginClicked();
    void onRegisterClicked();
    void showChatMainWindow();

private:
    QLineEdit *m_usernameEdit;
    QLineEdit *m_passwordEdit;
    QPushButton *m_loginButton;
    QPushButton *m_registerButton;
    QMainWindow *m_mainWindow;
    QString m_username;
};


#endif // LOGINDIALOG_H

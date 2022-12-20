#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H



#include <QDialog>

class QLineEdit;
class QPushButton;

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);

private slots:
    void onLoginClicked();
    void onRegisterClicked();

private:
    QLineEdit *m_usernameEdit;
    QLineEdit *m_passwordEdit;
    QPushButton *m_loginButton;
    QPushButton *m_registerButton;

};

#endif // LOGINDIALOG_H

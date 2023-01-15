#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>

class QLineEdit;
class QPushButton;

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);

    QString username() const;
    QString password() const;
    QString passwordConfirmation() const;



private slots:
    void onRegisterClicked();

private:
    QLineEdit *m_usernameEdit;
    QLineEdit *m_passwordEdit;
    QLineEdit *m_passwordConfirmationEdit;
    QPushButton *m_registerButton;
};

#endif // REGISTERDIALOG_H

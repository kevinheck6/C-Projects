#include "logindialog.h"
#include "registerdialog.h"
#include "logindatabase.h"

#include <QFile>
#include <QString>
#include <QApplication>

#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Login");

    // Read the contents of the style.qss file from the application's resources
    QFile file(":/style.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    // Set the style sheet for the login dialog
    setStyleSheet(styleSheet);

    // Set the size of the login dialog
    resize(400, 300);

    // Create the username and password fields
    m_usernameEdit = new QLineEdit(this);
    m_passwordEdit = new QLineEdit(this);
    m_passwordEdit->setEchoMode(QLineEdit::Password);

    // Create the login and register buttons
    m_loginButton = new QPushButton("Login", this);
    connect(m_loginButton, &QPushButton::clicked, this, &LoginDialog::onLoginClicked);
    m_registerButton = new QPushButton("Register", this);
    connect(m_registerButton, &QPushButton::clicked, this, &LoginDialog::onRegisterClicked);

    // Create the form layout
    QVBoxLayout *formLayout = new QVBoxLayout;
    formLayout->addWidget(new QLabel("Username:", this));
    formLayout->addWidget(m_usernameEdit);
    formLayout->addWidget(new QLabel("Password:", this));
    formLayout->addWidget(m_passwordEdit);

    // Create the button layout
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch();
    buttonLayout->addWidget(m_loginButton);
    buttonLayout->addWidget(m_registerButton);

    // Add the layouts to the main layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);
}

void LoginDialog::onLoginClicked()
{
    LoginDatabase loginDatabase;

    QString username = m_usernameEdit->text();
    QString password = m_passwordEdit->text();

    if (loginDatabase.checkLogin(username, password)) {
        accept();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password");
    }
}

void LoginDialog::onRegisterClicked()
{
    RegisterDialog registerDialog(this);
    int result = registerDialog.exec();
    if (result == QDialog::Accepted) {
        // The user successfully registered, so update the login database
        LoginDatabase loginDatabase;
        loginDatabase.addUser(registerDialog.username(), registerDialog.password());
    }
}

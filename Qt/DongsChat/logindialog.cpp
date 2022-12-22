#include "logindialog.h"
#include "chatmainwindow.h"
#include "qmainwindow.h"
#include "registerdialog.h"
#include "logindatabase.h"

#include "stdafx.h"

void LoginDialog::showChatMainWindow()
{
    QString username = m_usernameEdit->text();
    // Create an instance of the ChatMainWindow class
    ChatMainWindow *chatMainWindow = new ChatMainWindow(username, nullptr);

    // Set the ChatMainWindow object as the main window
    chatMainWindow->setWindowTitle("Chat Main Window");
    chatMainWindow->resize(600, 400);

    // Show the ChatMainWindow
    chatMainWindow->show();
}



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

    // Print the contents of the style sheet to the console
    //qDebug() << styleSheet;

    // Create the main window
    m_mainWindow = new QMainWindow;
    // Set the main window's properties (e.g. size, title, layout)
    m_mainWindow->setWindowTitle("Main Window");
    m_mainWindow->resize(600, 400);

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

QString LoginDialog::username() const
{
    return m_username;
}

void LoginDialog::onLoginClicked()
{
    LoginDatabase loginDatabase;

    QString username = m_usernameEdit->text();
    m_username = username; // store the username
    QString password = m_passwordEdit->text();

    if (loginDatabase.checkLogin(username, password)) {
        QString username = m_username;
        // Hide the login dialog
        hide();

        // Show the ChatMainWindow
        showChatMainWindow();
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



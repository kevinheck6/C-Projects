#include "registerdialog.h"
#include "logindatabase.h"

#include "stdafx.h"

RegisterDialog::RegisterDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Register");

    // Create the username and password fields
    m_usernameEdit = new QLineEdit(this);
    m_passwordEdit = new QLineEdit(this);
    m_passwordEdit->setEchoMode(QLineEdit::Password);

    // Create the password confirmation field
    m_passwordConfirmationEdit = new QLineEdit(this);
    m_passwordConfirmationEdit->setEchoMode(QLineEdit::Password);

    // Create the register button
    m_registerButton = new QPushButton("Register", this);
    connect(m_registerButton, &QPushButton::clicked, this, &RegisterDialog::onRegisterClicked);

    // Create the form layout
    QVBoxLayout *formLayout = new QVBoxLayout;
    formLayout->addWidget(new QLabel("Username:", this));
    formLayout->addWidget(m_usernameEdit);
    formLayout->addWidget(new QLabel("Password:", this));
    formLayout->addWidget(m_passwordEdit);
    formLayout->addWidget(new QLabel("Password Confirmation:", this));
    formLayout->addWidget(m_passwordConfirmationEdit);

    // Create the button layout
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch();
    buttonLayout->addWidget(m_registerButton);

    // Add the layouts to the main layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);
}

QString RegisterDialog::username() const
{
    return m_usernameEdit->text();
}

QString RegisterDialog::password() const
{
    return m_passwordEdit->text();
}

QString RegisterDialog::passwordConfirmation() const
{
    return m_passwordConfirmationEdit->text();
}


void RegisterDialog::onRegisterClicked()
{
    LoginDatabase loginDatabase;

    // Check if the username is already taken
    if (loginDatabase.isUsernameTaken(username())) {
        QMessageBox::warning(this, "Registration Failed", "This username is already taken");
        return;
    }

    // Check if the password and password confirmation match
    if (password() != passwordConfirmation()) {
        QMessageBox::warning(this, "Registration Failed", "The password and password confirmation do not match");
        return;
    }

    // Register the new user
    if (loginDatabase.registerUser(username(), password(), passwordConfirmation())) {
        QMessageBox::information(this, "Registration Successful", "You have successfully registered a new account");
        accept();
    } else {
        QMessageBox::warning(this, "Registration Failed", "An error occurred while trying to register the new account");
    }
}





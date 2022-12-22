#include "chatmainwindow.h"
#include "stdafx.h"


ChatMainWindow::ChatMainWindow(const QString &nickname, QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("Chat Main Window");
    resize(600, 400);

    // Read and set the style sheet
    QFile file(":/styleChat.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);

  //  // Initialize the login dialog
  //  m_loginDialog = new LoginDialog(this);

    // Store the nickname
    m_nickname = nickname;

    // Create the chat log and input widgets
    m_chatLog = new QTextEdit;
    m_chatLog->setReadOnly(true);
    m_messageEdit = new QLineEdit;
    m_sendButton = new QPushButton("Send");

    // Create the input layout
    QHBoxLayout *inputLayout = new QHBoxLayout;
    inputLayout->addWidget(m_messageEdit);
    inputLayout->addWidget(m_sendButton);

    // Create the main layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(m_chatLog);
    mainLayout->addLayout(inputLayout);

    // Set the main layout as the central widget
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // Connect the send button signal to the input handler slot
    connect(m_sendButton, &QPushButton::clicked, this, &ChatMainWindow::onSendClicked);

}


ChatMainWindow::~ChatMainWindow()
{
    // Put any cleanup code here (e.g. deleting pointers, closing connections, etc.)
}


void ChatMainWindow::sendMessage()
{
    // ... other code ...
    QString message = m_messageEdit->text();

    // Construct the message to be sent, including the nickname
    QString messageToSend = QString("%1: %2").arg(m_nickname, message);
    // Send the message to the server

    // Display the message in the chat log
    m_chatLog->append(messageToSend);

    // Clear the message edit field
    m_messageEdit->clear();

    // Send the message to the server
}

void ChatMainWindow::onSendClicked()
{
    sendMessage();
}



#include <QApplication>
#include "logindialog.h"
#include "tests.h"
#include "chatmainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Check if the database is in a good state
    if (!checkDatabase()) {
        qDebug() << "Error: database check failed";
        return 1;
    }

    // Create the login dialog
    LoginDialog loginDialog;
    int result = loginDialog.exec();
    if (result == QDialog::Accepted) {
        // The user successfully logged in, so show the ChatMainWindow object
        QString username = loginDialog.username();  // Get the login username
        ChatMainWindow *chatMainWindow = new ChatMainWindow(username);  // Create the ChatMainWindow object with the username as an argument
        chatMainWindow->setWindowTitle("Chat Main Window");
        chatMainWindow->resize(600, 400);
        chatMainWindow->show();
    }

    return a.exec();
}

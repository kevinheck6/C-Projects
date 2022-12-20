#include <QApplication>
#include <QMainWindow>
#include "logindialog.h"

#include <QResource>
#include <QApplication>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
bool checkDatabase()
{
    // Connect to the database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("login.db");
    if (!db.open()) {
        qWarning() << "Failed to open database:" << db.lastError().text();
        return false;
    }

    // Check if the users table exists and has the necessary columns
    QSqlQuery query(db);
    query.prepare("SELECT * FROM users LIMIT 1");
    if (!query.exec()) {
        // If the query fails, it means that the users table or columns don't exist
        // Try creating the users table
        query.prepare("CREATE TABLE users (username TEXT, password TEXT)");
        if (!query.exec()) {
            qWarning() << "Error: failed to create users table - " << query.lastError();
            return false;
        }
    }

    return true;
}





bool checkUsersTable()
{
    // Connect to the database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("login.db");
    if (!db.open()) {
        qWarning() << "Failed to open database:" << db.lastError().text();
        return false;
    }

    // Check if the users table exists and has the necessary columns
    QSqlQuery query(db);
    query.prepare("SELECT * FROM users LIMIT 1");
    if (!query.exec()) {
        // If the query fails, it means that the users table or columns don't exist
        // Try creating the users table
        query.prepare("CREATE TABLE users (username TEXT, password TEXT)");
        if (!query.exec()) {
            qWarning() << "Error: failed to create users table - " << query.lastError();
            return false;
        }
    }

    return true;
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create the login dialog
    LoginDialog loginDialog;

    // Check if the database is in a good state
    if (checkDatabase()) {
        qDebug() << "login.db file exists and is readable and writable, and users table exists and has the necessary columns";
    } else {
        qDebug() << "Error: database check failed";
        return 1;
    }

    // Show the login dialog and wait for the user to login or cancel
    if (loginDialog.exec() == QDialog::Accepted) {
        // Login was successful, so create the main window and show it
        QMainWindow mainWindow;
        mainWindow.show();
        return app.exec();
    } else {
        // Login was cancelled, so exit the application
        return 0;
    }
}


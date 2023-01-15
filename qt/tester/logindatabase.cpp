#include "logindatabase.h"
#include "stdafx.h"


LoginDatabase::LoginDatabase()
{
    openDatabase();
}

bool LoginDatabase::openDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("login.db");
    if (!db.open()) {
        qWarning() << "Failed to open database:" << db.lastError().text();
        return false;
    }
    return true;
}

bool LoginDatabase::checkLogin(const QString &username, const QString &password)
{
    QSqlQuery query(m_database);
    query.prepare("SELECT * FROM users WHERE username = (:username) AND password = (:password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    if (!query.exec()) {
        qWarning() << "Error: login failed - " << query.lastError();
        return false;
    }

    if (query.next()) {
        return true;
    } else {
        return false;
    }
}

bool LoginDatabase::addUser(const QString &username, const QString &password)
{
    QSqlQuery query(m_database);
    query.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    if (!query.exec()) {
        qWarning() << "Error: failed to add user - " << query.lastError();
        return false;
    }

    return true;
}

bool LoginDatabase::isUsernameTaken(const QString &username) const
{
    if (username.isEmpty()) {
        qWarning() << "Username is empty";
        return false;
    }

    // Connect to the database
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        if (!db.open()) {
            qWarning() << "Failed to open database:" << db.lastError().text();
            return false;
        }
    }

    // Check if the username is already taken
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM users WHERE username = :username");
    query.bindValue(":username", username);
    if (!query.exec()) {
        qWarning() << "Failed to execute query:" << query.lastError().text();
        return false;
    }
    if (!query.first()) {
        qWarning() << "Failed to retrieve query result:" << query.lastError().text();
        return false;
    }
    int count = query.value(0).toInt();
    return (count > 0);
}

bool LoginDatabase::registerUser(const QString &username, const QString &password, const QString &passwordConfirmation)
{
    if (username.isEmpty()) {
        qWarning() << "Username is empty";
        return false;
    }
    if (password.isEmpty()) {
        qWarning() << "Password is empty";
        return false;
    }

    if (password != passwordConfirmation) {
        QMessageBox::warning(nullptr, "Registration Failed", "The password and password confirmation do not match");
        return false;
    }

    // Connect to the database
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        if (!db.open()) {
            qWarning() << "Failed to open database:" << db.lastError().text();
            return false;
        }
    }

    // Register the new user
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    if (!query.exec()) {
        qWarning() << "Failed to execute query:" << query.lastError().text();
        return false;
    }
    return true;
}


bool LoginDatabase::checkCredentials(const QString &username, const QString &password) const
{
    if (username.isEmpty()) {
        qWarning() << "Username is empty";
        return false;
    }
    if (password.isEmpty()) {
        qWarning() << "Password is empty";
        return false;
    }

    // Connect to the database
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        if (!db.open()) {
            qWarning() << "Failed to open database:" << db.lastError().text();
            return false;
        }
    }

    // Check the login credentials
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    if (!query.exec()) {
        qWarning() << "Failed to execute query:" << query.lastError().text();
        return false;
    }
    if (!query.first()) {
        qWarning() << "Failed to retrieve query result:" << query.lastError().text();
        return false;
    }
    int count = query.value(0).toInt();
    return (count > 0);
}



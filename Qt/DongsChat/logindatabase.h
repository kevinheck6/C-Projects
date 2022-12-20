#ifndef LOGINDATABASE_H
#define LOGINDATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class LoginDatabase
{
public:
    LoginDatabase();
    bool checkLogin(const QString &username, const QString &password);
    bool addUser(const QString &username, const QString &password);
    bool isUsernameTaken(const QString &username) const;
    bool registerUser(const QString &username, const QString &password, const QString &passwordConfirmation);
    bool checkCredentials(const QString &username, const QString &password) const;

private:
    QSqlDatabase m_database;
    bool openDatabase();
};

#endif // LOGINDATABASE_H

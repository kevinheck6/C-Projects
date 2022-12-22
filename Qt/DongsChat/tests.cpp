#include "tests.h"

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


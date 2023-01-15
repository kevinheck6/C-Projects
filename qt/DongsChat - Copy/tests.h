#ifndef TESTS_H
#define TESTS_H


#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

// Function to check if the database is in a good state
bool checkDatabase();
bool checkUsersTable();

#endif // TESTS_H

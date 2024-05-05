#include "connection.h"
#include <QMessageBox>
#include "mainwindow.h"
#include <QApplication>
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test_bd");
db.setUserName("oumayma");//inserer nom de l'utilisateur
db.setPassword("esprit");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;


    return test ;
}

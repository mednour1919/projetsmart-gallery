#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("source_projet2A");
db.setUserName("nourh");//inserer nom de l'utilisateur
db.setPassword("nourh");
if (db.open())
test=true;





    return  test;
}

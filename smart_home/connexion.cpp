#include "connexion.h"


connexion::connexion()
{

}

bool connexion::createConnexion()
{
    bool test=false;
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet QT");
    db.setUserName("eya");
    db.setPassword("root");

    if (db.open())
        test=true;

    return test;
}

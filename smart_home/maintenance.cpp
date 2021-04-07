#include "maintenance.h"
#include <iostream>

maintenance::maintenance()
{

}
bool maintenance::ajouter()
{
    QSqlQuery querym;
    querym.prepare("INSERT INTO MAINTENANCE (ID_MAINTENANCE, REFERENCE_MAINTENANCE, ETAT, DATE_MAINTENANCE, ID_REPARATEUR) VALUES (:ID_MAINTENANCE, :REFERENCE_MAINTENANCE, :ETAT, :DATE_MAINTENANCE, :ID_REPARATEUR)");
    querym.bindValue(":ID_MAINTENANCE", ID_MAINTENANCE);
    querym.bindValue(":REFERENCE_MAINTENANCE", REFERENCE);
    querym.bindValue(":ETAT", ETAT);
    querym.bindValue(":DATE_MAINTENANCE", DATE);
    querym.bindValue(":ID_REPARATEUR", ID_REPARATEUR);
    return querym.exec();


}

bool maintenance::supprimer(QString idmaintenance)
{
    QSqlQuery qury;
    qury.prepare("Delete from MAINTENANCE where ID_MAINTENANCE = :Idmaintenance");
    qury.bindValue(":Idmaintenance",idmaintenance);
    return qury.exec();
}



QSqlQueryModel *maintenance::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM MAINTENANCE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_MAINTENANCE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("REFERENCE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID_REPARATEUR"));
    return model;
}

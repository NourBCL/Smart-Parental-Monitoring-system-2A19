#ifndef MAINTENANCE_H
#define MAINTENANCE_H
#include<QString>
#include<qstring.h>
#include<QDate>
#include<QSqlQuery>
#include<QVariant>
#include<QSqlQueryModel>
#include<QSqlRecord>
#include<QtDebug>
#include<qtableview.h>
#include<QFileDialog>
#include<QCoreApplication>
#include<QSqlTableModel>



class maintenance
{
public:
    maintenance();

    maintenance(QString i,QString n,QString c,QString b,QString r):ID_MAINTENANCE(i),REFERENCE(n),ETAT(c),DATE(b),ID_REPARATEUR(r) {}

    //getters
    QString getId(){return ID_MAINTENANCE;};
    QString getReference(){return REFERENCE;};
    QString getEtat(){return ETAT;};
    QString getDate(){return DATE;};
    QString getIdReperateur(){return ID_REPARATEUR;};

    //setters

    void setId(QString IdMaintenance){IdMaintenance= ID_MAINTENANCE;};
    void setReference(QString reference){reference = REFERENCE;};
    void setEtat(QString etat){etat= ETAT;};
    void setDate(QString date){date= DATE;};
    void setIdReperateur(QString id_reperateur){id_reperateur= ID_REPARATEUR;};

    //fonctions
    bool ajouter();
    bool supprimer(QString);
    QSqlQueryModel *afficher();



private:
    QString ID_MAINTENANCE;
    QString REFERENCE;
    QString ETAT;
    QString DATE;
    QString ID_REPARATEUR;

};

#endif // MAINTENANCE_H

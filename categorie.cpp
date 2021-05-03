#include "categorie.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSystemTrayIcon>

categorie::categorie()
{
    id="";
    nom="";
    description="";
}

categorie::categorie(QString id , QString nom, QString description)
{
    this->id = id;
    this->nom = nom;
    this->description = description;
}

QString categorie::get_id()
{
    return id;
}
QString categorie::get_nom()
{
    return nom;
}
QString categorie::get_description()
{
    return description;
}


bool categorie::add_categorie()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CATEGORIE (ID,NOM,DESCRIPTION)"
                  "VALUES(:id,:nom,:description)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":description",description);


    return    query.exec();
}
QSqlQueryModel * categorie::show_categorie()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT NOM,DESCRIPTION FROM CATEGORIE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
        return model;
}
bool categorie::remove_categorie(QString nom)
{
QSqlQuery query;
QString toSearch= nom;
query.prepare("DELETE FROM CATEGORIE WHERE NOM = :NOM");
query.bindValue(":NOM", toSearch);
return    query.exec();
}
bool categorie::modify_categorie(){
    QSqlQuery query;
    query.prepare("UPDATE CATEGORIE SET ID= :ID, NOM= :NOM, DESCRIPTION= :DESCRIPTION WHERE ID= :ID");
    query.bindValue(":ID",id);
    query.bindValue(":NOM",nom);
    query.bindValue(":DESCRIPTION",description);
    return query.exec();
}
QSqlQueryModel * categorie::search(const QString &fullname)
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select NOM,DESCRIPTION from categorie where (NOM LIKE '"
                     ""+fullname+"%') ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));
     return model;
}
QSqlQueryModel * categorie::show_Asc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT NOM,DESCRIPTION FROM CATEGORIE ORDER BY NOM ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
        return model;
}
void categorie::show_notification(QString titre,QString text)
{
    this->text=text;
      this->titre=titre;
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->setIcon(QIcon(":/IMG/IMG/logo 2.png"));
    notifyIcon->show();
    notifyIcon->showMessage(titre,text,QSystemTrayIcon::Information,15000);
}

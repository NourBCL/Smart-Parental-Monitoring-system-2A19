#include "ingredient.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSystemTrayIcon>
ingredient::ingredient()
{
    id="";
    nom="";
    quantite="";
    type="";
}

ingredient::ingredient(QString id , QString nom, QString quantite, QString type)
{
    this->id = id;
    this->nom = nom;
    this->quantite = quantite;
    this->type = type;
}

QString ingredient::get_id()
{
    return id;
}
QString ingredient::get_nom()
{
    return nom;
}
QString ingredient::get_quantite()
{
    return quantite;
}

QString ingredient::get_type()
{
    return type;
}

bool ingredient::add_ingredient()
{
    QSqlQuery query;
    query.prepare("INSERT INTO INGREDIENT (ID,NOM,QUANTITE,TYPE)"
                  "VALUES(:id,:nom,:quantite,:type)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":quantite",quantite);
    query.bindValue(":type",type);


    return    query.exec();
}
QSqlQueryModel * ingredient::show_ingredient()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT NOM,QUANTITE,TYPE FROM INGREDIENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
        return model;
}
bool ingredient::remove_ingredient(QString nom)
{
QSqlQuery query;
QString toSearch= nom;
query.prepare("DELETE FROM INGREDIENT WHERE NOM = :NOM");
query.bindValue(":NOM", toSearch);
return    query.exec();
}
bool ingredient::modify_ingredient(){
    QSqlQuery query;
    query.prepare("UPDATE INGREDIENT SET ID= :ID, NOM= :NOM, QUANTITE= :QUANTITE, TYPE= :TYPE WHERE ID= :ID");
    query.bindValue(":ID",id);
    query.bindValue(":NOM",nom);
    query.bindValue(":QUANTITE",quantite);
    query.bindValue(":TYPE",type);
    return query.exec();
}
QSqlQueryModel * ingredient::search(const QString &fullname)
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select NOM,QUANTITE,TYPE from ingredient where (NOM LIKE '"
                     ""+fullname+"%') ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("QUANTITE"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
     return model;
}
QSqlQueryModel * ingredient::show_Asc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT NOM,QUANTITE,TYPE FROM INGREDIENT ORDER BY NOM ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
        return model;
}
void ingredient::show_notification(QString titre,QString text)
{
    this->text=text;
      this->titre=titre;
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->setIcon(QIcon(":/IMG/IMG/logo2.png"));
    notifyIcon->show();
    notifyIcon->showMessage(titre,text,QSystemTrayIcon::Information,15000);
}

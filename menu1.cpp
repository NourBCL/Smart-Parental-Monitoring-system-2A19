#include "menu1.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Menu1::Menu1()
{

}

Menu1::Menu1(int id,QString nom,QString composition,QDate date)
{
    this->id=id;
    this->nom=nom;
    this->composition=composition;
    this->dat=date;}
int Menu1::getid(){return id;}
QString Menu1::getnom(){return nom;}
QString Menu1::getcomposition(){return composition;}
void Menu1::setid(int id){this->id=id;}
void Menu1::setnom(QString nom){this->nom=nom;}
void Menu1::setcomposition(QString composition){this->composition=composition;}
void Menu1::setdat(QDate date){this->dat=date;}


bool Menu1::ajouter( ) {
    QSqlQuery query; //QsqlQuery : Classe QsqlQuery qui admet une instance query qui contient des méthodes prédefinies comme bindValue/prepare
    query.prepare("INSERT INTO MENU1 (id,nom,composition,dat) VALUES(:id, :nom, :composition, :dat)");//initilisation de la requête
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":composition",composition);
    query.bindValue(":dat",dat);
    return query.exec();// keni exec() traja3 false =====> mathmch ajout thama problème sinon raw ajout jawo behi !
}

QSqlQueryModel * Menu1::afficher()
{
   // Création d'une instance lorsque on a parle là des widgets
    QSqlQueryModel * model = new QSqlQueryModel();
    //
    model->setQuery("SELECT * FROM MENU1 ");// Récupération des données men table
    // Pour que l'affichage iji mnathem,les colonnes bahtha bathhom et mnathmin on fait comme ça :
    // Qt::horizontal manha table bel rekda ijiw les colonnes

    model->setHeaderData(0, Qt::Horizontal,"Id");
    model->setHeaderData(1, Qt::Horizontal,"Nom");
    model->setHeaderData(2, Qt::Horizontal,"Composition");
    model->setHeaderData(3, Qt::Horizontal,"Date");

    return model;

}


bool Menu1::supprimer(int i)
{

    QSqlQuery query;
    query.prepare("DELETE FROM MENU1 where id=:id");
    QString res= QString::number(i);// int i bch y7awlha lel qstring,cette méthode,on l'utilise pour éviter les problémes lorsque on a un passage par paramétres
    query.bindValue(":id",res);
    return query.exec();

}
bool Menu1::modifier() {
    QSqlQuery query;
    //query.prepare("UPDATE MENU  SET nomMenu =:nomMenu, cateogrieMenu =:categorie , prixMenu =:prix WHERE idMenu = '"+nomMenu+"'"));

    query.prepare("UPDATE MENU1  SET nom =:nom, composition =:composition, dat =:dat WHERE id = :id");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":composition",composition);
    query.bindValue(":dat",dat);
    return query.exec();

}
int Menu1::total_menu1() {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM MENU1");

     query.exec();
     int rows = 0;
     while(query.next()) {
         rows = query.value(0).toInt();
     }

     return rows ;
}




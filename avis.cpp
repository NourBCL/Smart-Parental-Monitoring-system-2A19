#include "avis.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Avis::Avis()
{

}

Avis::Avis(int id,QString avis,QString composition_avis,QDate date)
{
    this->id=id;
    this->avis=avis;
    this->composition_avis=composition_avis;
    this->data=date;}
int Avis::getid(){return id;}
QString Avis::getavis(){return avis;}
QString Avis::getcomposition_avis(){return composition_avis;}
   QDate Avis::getdata(){return data;}
void Avis::setid(int id){this->id=id;}
void Avis::setavis(QString avis){this->avis=avis;}
void Avis::setcomposition_avis(QString composition_avis){this->composition_avis=composition_avis;}
void Avis::setdata(QDate date){this->data=date;}

bool Avis::ajouter( ) {
    QSqlQuery query; //QsqlQuery : Classe QsqlQuery qui admet une instance query qui contient des méthodes prédefinies comme bindValue/prepare
    query.prepare("INSERT INTO AVIS (id,avis,composition_avis,data) VALUES(:id, :avis, :composition_avis, :data)");//initilisation de la requête
    query.bindValue(":id",id);
    query.bindValue(":avis",avis);
    query.bindValue(":composition_avis",composition_avis);
    query.bindValue(":data",data);
    return query.exec();// keni exec() traja3 false =====> mathmch ajout thama problème sinon raw ajout jawo behi !
}
QSqlQueryModel * Avis::afficher()
{
   // Création d'une instance lorsque on a parle là des widgets
    QSqlQueryModel * model = new QSqlQueryModel();
    //
    model->setQuery("SELECT * FROM AVIS ");// Récupération des données men table
    // Pour que l'affichage iji mnathem,les colonnes bahtha bathhom et mnathmin on fait comme ça :
    // Qt::horizontal manha table bel rekda ijiw les colonnes

    model->setHeaderData(0, Qt::Horizontal,"Id");
    model->setHeaderData(1, Qt::Horizontal,"Avis");
    model->setHeaderData(2, Qt::Horizontal,"Composition_Avis");
    model->setHeaderData(3, Qt::Horizontal,"Date");

    return model;

}


bool Avis::supprimer(int i)
{

    QSqlQuery query;
    query.prepare("DELETE FROM AVIS where id=:id");
    QString res= QString::number(i);// int i bch y7awlha lel qstring,cette méthode,on l'utilise pour éviter les problémes lorsque on a un passage par paramétres
    query.bindValue(":id",res);
    return query.exec();

}

bool Avis::modifier() {
    QSqlQuery query;
    //query.prepare("UPDATE MENU  SET nomMenu =:nomMenu, cateogrieMenu =:categorie , prixMenu =:prix WHERE idMenu = '"+nomMenu+"'"));

    query.prepare("UPDATE AVIS  SET avis =:avis, composition_avis =:composition_avis, data =:data WHERE id = :id");
    query.bindValue(":id",id);
    query.bindValue(":avis",avis);
    query.bindValue(":composition_avis",composition_avis);
    query.bindValue(":data",data);
    return query.exec();

}



QSqlQueryModel * Avis::trie_id_avis(){
   // Création d'une instance lorsque on a parle là des widgets
    QSqlQueryModel * model = new QSqlQueryModel();
    //
    model->setQuery("SELECT * FROM AVIS order by id");// Récupération des données men table
    // Pour que l'affichage iji mnathem,les colonnes bahtha bathhom et mnathmin on fait comme ça :
    // Qt::horizontal manha table bel rekda ijiw les colonnes

    model->setHeaderData(0, Qt::Horizontal,"Id");

    model->setHeaderData(1, Qt::Horizontal,"Avis");
    model->setHeaderData(2, Qt::Horizontal,"Composition_Avis");
    model->setHeaderData(3, Qt::Horizontal,"Date");

    return model;

}

QSqlQueryModel * Avis::recherche_avis(QString avis)
{
   // Création d'une instance lorsque on a parle là des widgets
    QSqlQueryModel * model = new QSqlQueryModel();
    //
    model->setQuery("select * from AVIS WHERE avis = '"+avis+"'");

    // Pour que l'affichage iji mnathem,les colonnes bahtha bathhom et mnathmin on fait comme ça :
    // Qt::horizontal manha table bel rekda ijiw les colonnes
    model->setHeaderData(0, Qt::Horizontal,"Id");
    model->setHeaderData(1, Qt::Horizontal,"Avis");
    model->setHeaderData(2, Qt::Horizontal,"Composition_Avis");
    model->setHeaderData(3, Qt::Horizontal,"Date");

    return model;

}


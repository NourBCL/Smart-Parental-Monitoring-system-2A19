#include "object.h"

Object::Object()
{

}

bool Object::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO OBJET (ID_OBJET, NOM, CATEGORIE, BRAND, REFERENCE, TYPEDECONTROLE) VALUES (:ID_OBJET, :NOM, :CATEGORIE, :BRAND, :REFERENCE, :TYPEDECONTROLE)");
    query.bindValue(":ID_OBJET", ID);
    query.bindValue(":NOM", NOM);
    query.bindValue(":CATEGORIE", CATEGORIE);
    query.bindValue(":BRAND", BRAND);
    query.bindValue(":REFERENCE", REFERENCE);
    query.bindValue(":TYPEDECONTROLE", TYPEDECONTROLE);
    return query.exec();
}

bool Object::supprimerO(QString idobject)
{
    QSqlQuery qury;
    qury.prepare("Delete from OBJET where ID_OBJET = :Idobject");
    qury.bindValue(":Idobject",idobject);
    return qury.exec();
}



QSqlQueryModel *Object::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM Objet");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_Objet"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("CATEGORIE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("BRAND"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("REFERENCE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("TYPEDECONTROLE"));
    return model;
}

QSqlQueryModel * Object::trier(QString critere,QString order)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery *triq= new QSqlQuery();


    triq->prepare("SELECT * FROM Objet ORDER BY "+critere+" "+order);
    triq->exec();
    model->setQuery(*triq);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_Objet"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("CATEGORIE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("BRAND"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("REFERENCE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("TYPEDECONTROLE"));
    return model;
}

QSqlQueryModel *Object::chercher(QString input,int critere)
{
    QSqlQuery q;
    if(critere==0)
    {
        q.prepare("SELECT * FROM OBJET WHERE ID_OBJET = :ID_OBJET");
        q.bindValue(":ID_OBJET",input);
        q.exec();
    }
    else if(critere==1)
    {
        q.prepare("SELECT * FROM Objet WHERE NOM = :NOM");
        q.bindValue(":NOM",input);
        q.exec();
    }
    else if(critere==2)
    {
        q.prepare("SELECT * FROM Objet WHERE CATEGORIE = :CATEGORIE");
        q.bindValue(":CATEGORIE",input);
        q.exec();
    }
    else if(critere==3)
    {
        q.prepare("SELECT * FROM Objet WHERE BRAND = :BRAND");
        q.bindValue(":BRAND",input);
        q.exec();
    }
    else if(critere==4)
    {
        q.prepare("SELECT * FROM Objet WHERE REFERENCE = :REFERENCE");
        q.bindValue(":REFERENCE",input);
        q.exec();
    }
    else if(critere==5)
    {
        q.prepare("SELECT * FROM Objet WHERE TYPEDECONTROLE = :TYPECONTROLE");
        q.bindValue(":TYPECONTROLE",input);
        q.exec();
    }


    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(q);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_OBJET"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATEGORIE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("BRAND"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("TYPEDECONTROLE"));

    QString index;
    QSqlRecord recp;
    recp = model->record(0);
    return model;

}


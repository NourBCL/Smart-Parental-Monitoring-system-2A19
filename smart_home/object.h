#ifndef OBJECT_H
#define OBJECT_H
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


class Object
{
public:
    Object();

    Object(QString i,QString n,QString c,QString b,QString r,QString t):ID(i),NOM(n),CATEGORIE(c),BRAND(b),REFERENCE(r),TYPEDECONTROLE(t) {}

    //getters
    QString getId(){return ID;};
    QString getNom(){return NOM;};
    QString getCategorie(){return CATEGORIE;};
    QString getBrand(){return BRAND;};
    QString getReference(){return REFERENCE;};
    QString getTypeDeControle() {return TYPEDECONTROLE;};

    //setters

    void setId(QString idobject){idobject= ID;};
    void setNom(QString nom){nom = NOM;};
    void setCategorie(QString categorie){categorie= CATEGORIE;};
    void setBrand(QString brand){brand= BRAND;};
    void setReference(QString reference){reference= REFERENCE;};
    void setTypeDeControle(QString typedecontrole) {typedecontrole= TYPEDECONTROLE;};

    //fonctions
    bool ajouter();
    bool supprimerO(QString);
    QSqlQueryModel *afficher();
    QSqlQueryModel * trier(QString ,QString);
    QSqlQueryModel *chercher(QString,int);




private:
    QString ID;
    QString NOM;
    QString CATEGORIE;
    QString BRAND;
    QString REFERENCE;
    QString TYPEDECONTROLE;

};

#endif // OBJECT_H

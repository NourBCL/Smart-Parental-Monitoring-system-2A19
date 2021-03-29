#ifndef CATEGORIE_H
#define CATEGORIE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class categorie
{
public:
    categorie();
    categorie(QString,QString,QString);

    QString get_id();
    QString get_nom();
    QString get_description();

     bool add_categorie();
     QSqlQueryModel * show_categorie();
     bool remove_categorie(QString);
     bool modify_categorie();
     QSqlQueryModel * search(const QString&);
     QSqlQueryModel * show_Asc();
private:
    QString id,nom,description;

};

#endif // CATEGORIE_H


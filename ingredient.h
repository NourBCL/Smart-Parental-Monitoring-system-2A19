#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class ingredient
{
public:
    ingredient();
    ingredient(QString,QString,QString,QString);

    QString get_id();
    QString get_nom();
    QString get_quantite();
    QString get_type();

     bool add_ingredient();
     QSqlQueryModel * show_ingredient();
     bool remove_ingredient(QString);
     bool modify_ingredient();
     QSqlQueryModel * search(const QString&);
     QSqlQueryModel * show_Asc();
     void show_notification(QString, QString);
private:
    QString id,nom,quantite,type,titre,text ;

};

#endif // INGREDIENT_H

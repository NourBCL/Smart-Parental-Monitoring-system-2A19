#ifndef ACTIVITE_H
#define ACTIVITE_H
#include <QString>
#include <QDate>
#include <QTime>
#include <QSqlQuery>
#include <QSqlQueryModel>


class activite
{
public:
    activite();
    activite(QString,QString,QString,QString,QString,QString);

    QString get_id();
    QString get_nom();
    QString get_DAY();
    QString get_STARTTIME();
    QString get_ENDTIME();
    QString get_NOMCAT();

     bool add_activite();
     bool modify();
     QSqlQueryModel * show();
     QSqlQueryModel * show_cat(const QString &);
     bool remove(QString);
     QSqlQueryModel * show_act(const QString & , const QString &);
     QSqlQueryModel * show_asc(const QString & , const QString &);
private:
     QString id;
    QString nom;
    QString day;
    QString starttime,endtime, nomcat;

};


#endif // ACTIVITE_H

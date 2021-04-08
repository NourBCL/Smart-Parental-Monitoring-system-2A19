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
     void show_notification(QString, QString);
     QSqlQuery stat_1(int &);
     QSqlQuery stat_2(int &);
     QSqlQuery stat_3(int &);
     QSqlQuery stat_4(int &);
     QSqlQuery stat_5(int &);
     QSqlQuery stat_6(int &);
     QSqlQuery stat_7(int &);
private:
     QString id;
    QString nom;
    QString day;
    QString starttime,endtime, nomcat;
    QString titre , text ;

};


#endif // ACTIVITE_H

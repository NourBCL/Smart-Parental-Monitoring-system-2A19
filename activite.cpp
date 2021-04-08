#include "activite.h"
#include <QString>
#include <QDate>
#include <QTime>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSystemTrayIcon>
activite::activite()
{
    id="";
    nom="";
    day="";
    starttime="";
    endtime="";
    nomcat="";
}

activite::activite(QString id , QString nom, QString day, QString starttime, QString endtime, QString nomcat)
{
    this->id = id;
    this->nom = nom;
    this->day = day;
    this->starttime=starttime;
    this->endtime=endtime;
    this->nomcat=nomcat;
}

QString activite::get_id()
{
    return id;
}
QString activite::get_nom()
{
    return nom;
}
QString activite::get_DAY()
{
    return day;
}
QString activite::get_STARTTIME()
{
    return starttime;
}
QString activite::get_ENDTIME()
{
    return endtime;
}
QString activite::get_NOMCAT()
{
    return nomcat;
}
bool activite::add_activite()
{
    QSqlQuery query;

    query.prepare("INSERT INTO ACTIVITE (ID,NOM,DAY,STARTTIME,ENDTIME,NOMCAT)"
                  "VALUES(:id,:nom,:day,:starttime,:endtime,:nomcat)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":day",day);
    query.bindValue(":starttime",starttime);
    query.bindValue(":endtime",endtime);
    query.bindValue(":nomcat",nomcat);



    return    query.exec();
}
QSqlQueryModel * activite::show()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT NOM,DAY,STARTTIME,ENDTIME FROM activite");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Day"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Start Time"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("End Time"));
        return model;
}
QSqlQueryModel * activite::show_cat(const QString &nom)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT NOM,DAY,STARTTIME,ENDTIME,NOMCAT FROM activite WHERE (NOMCAT= '"+nom+"')");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Day"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Start Time"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("End Time"));

        return model;
}
bool activite::modify(){
    QSqlQuery query;
    query.prepare("UPDATE ACTIVITE SET ID= :ID, NOM= :NOM, DAY= :DAY, STARTTIME= :STARTTIME, ENDTIME= :ENDTIME, NOMCAT= :NOMCAT WHERE ID= :ID");
    query.bindValue(":ID",id);
    query.bindValue(":NOM",nom);
    query.bindValue(":DAY",day);
    query.bindValue(":STARTTIME",starttime);
    query.bindValue(":ENDTIME",endtime);
    query.bindValue(":NOMCAT",nomcat);
    return query.exec();
}
bool activite::remove(QString id)
{
QSqlQuery query;
QString toSearch= id;
query.prepare("DELETE FROM ACTIVITE WHERE NOM = :NOM");
query.bindValue(":NOM", toSearch);
return    query.exec();
}
QSqlQueryModel * activite::show_act(const QString &day , const QString &nom)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT NOM,DAY,STARTTIME,ENDTIME,NOMCAT FROM activite WHERE (DAY LIKE '"+day+"%')AND (NOMCAT= '"+nom+"')");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Day"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Start Time"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("End Time"));

        return model;
}
QSqlQueryModel * activite::show_asc(const QString &day , const QString &nom)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT NOM,DAY,STARTTIME,ENDTIME,NOMCAT FROM activite WHERE (DAY LIKE '"+day+"%')AND (NOMCAT= '"+nom+"')ORDER BY NOM ASC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Day"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Start Time"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("End Time"));

        return model;
}
void activite::show_notification(QString titre,QString text)
{
    this->text=text;
      this->titre=titre;
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->setIcon(QIcon(":/IMG/IMG/logo 2.png"));
    notifyIcon->show();
    notifyIcon->showMessage(titre,text,QSystemTrayIcon::Information,15000);
}
QSqlQuery activite::stat_1(int &stat1)
{
    stat1=0;
    QSqlQuery query1("SELECT COUNT(*) FROM ACTIVITE WHERE DAY LIKE 'lun%'");
    while(query1.next())
    {
        stat1=query1.value(0).toInt();
    }
    return query1;
}
QSqlQuery activite::stat_2(int &stat2)
{
    stat2=0;
    QSqlQuery query1("SELECT COUNT(*) FROM ACTIVITE WHERE DAY LIKE 'mar%'");
    while(query1.next())
    {
        stat2=query1.value(0).toInt();
    }
    return query1;
}
QSqlQuery activite::stat_3(int &stat3)
{
    stat3=0;
    QSqlQuery query1("SELECT COUNT(*) FROM ACTIVITE WHERE DAY LIKE 'mer%'");
    while(query1.next())
    {
        stat3=query1.value(0).toInt();
    }
    return query1;
}
QSqlQuery activite::stat_4(int &stat4)
{
    stat4=0;
    QSqlQuery query1("SELECT COUNT(*) FROM ACTIVITE WHERE DAY LIKE 'jeu%'");
    while(query1.next())
    {
        stat4=query1.value(0).toInt();
    }
    return query1;
}
QSqlQuery activite::stat_5(int &stat5)
{
    stat5=0;
    QSqlQuery query1("SELECT COUNT(*) FROM ACTIVITE WHERE DAY LIKE 'ven%'");
    while(query1.next())
    {
        stat5=query1.value(0).toInt();
    }
    return query1;
}
QSqlQuery activite::stat_6(int &stat6)
{
    stat6=0;
    QSqlQuery query1("SELECT COUNT(*) FROM ACTIVITE WHERE DAY LIKE 'sam%'");
    while(query1.next())
    {
        stat6=query1.value(0).toInt();
    }
    return query1;
}
QSqlQuery activite::stat_7(int &stat7)
{
    stat7=0;
    QSqlQuery query1("SELECT COUNT(*) FROM ACTIVITE WHERE DAY LIKE 'dim%'");
    while(query1.next())
    {
        stat7=query1.value(0).toInt();
    }
    return query1;
}


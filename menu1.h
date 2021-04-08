#ifndef MENU1_H
#define MENU1_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>

class Menu1
{
public:
    Menu1();
    Menu1(int,QString,QString,QDate);
    int getid();
    QString getnom();
    QString getcomposition();
    QDate getdat();
    void setid(int);
    void setnom(QString);
    void setcomposition(QString);
    void setdat(QDate);
    bool ajouter();
    bool modifier();
  QSqlQueryModel * afficher();
  bool supprimer(int);
private:
    int id ;
    QString nom, composition;
    QDate dat;

};

#endif // MENU1_H

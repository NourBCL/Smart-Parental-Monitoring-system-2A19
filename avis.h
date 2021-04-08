#ifndef AVIS_H
#define AVIS_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>


class Avis
{
public:
    Avis();
    Avis(int,QString,QString,QDate);
    int getid();
    QString getavis();
    QString getcomposition_avis();
    QDate getdata();
    void setid(int);
    void setavis(QString);
    void setcomposition_avis(QString);
    void setdata(QDate);
    bool ajouter();
    bool modifier();
  QSqlQueryModel * afficher();
  QSqlQueryModel * trie_id_avis();
  QSqlQueryModel * recherche_avis(QString avis);
  bool supprimer(int);
private:
    int id ;
    QString avis, composition_avis;
    QDate data;

};
#endif // AVIS_H

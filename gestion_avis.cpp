#include "gestion_avis.h"
#include "ui_gestion_avis.h"
#include "avis.h"
#include <QMessageBox>


gestion_avis::gestion_avis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gestion_avis)
{
    ui->setupUi(this);
    ui->le_id_avis->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
        ui->avis_enfant->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
        ui->la_composition_avis->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
        ui->le_id_avis_modif->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
         ui->avis_enfant_modif->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
        ui->la_composition_avis_modif->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
}

gestion_avis::~gestion_avis()
{
    delete ui;
}

void gestion_avis::on_pb_ajouter_avis_clicked()
{

    int id = ui->le_id_avis->text().toInt();
    QString avis= ui->avis_enfant->text();
    QString composition_avis = ui->la_composition_avis->text();
    QDate dat = ui->le_date_avis->date();
    // Création d'un objet normal,on parle pas de widgets içi :
    Avis a;
    a = Avis(id,avis,composition_avis,dat);
    //
    bool test = a.ajouter();

    if(test) {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                   QObject::tr("Avis ajouté !\n"
                        "click ok to exit"),QMessageBox::Ok);

    }
else{QMessageBox::information(nullptr, QObject::tr("database is open"),
                              QObject::tr("erreur d'ajout !\n"
                   "click ok to exit"),QMessageBox::Ok);}
}

void gestion_avis::on_tabWidget_currentChanged(int index)
{
     ui->tab_avis->setModel(avis->afficher());
}

void gestion_avis::on_pb_supprimer_avis_clicked()
{

    int id = ui->le_id_avis_supp->text().toInt();
    bool test = avis->supprimer(id);


    if(test) {
        QMessageBox::information(nullptr,"Supprimer un avis","l'avis a été supprimé avec succès !");//Qwidget ==> les composants mt3 qt dima initliasation ta3 ay QWidget heya nullptr manha maytpointa ala chay
    }
    else {
        QMessageBox::information(nullptr,"Supprimer un avis ","suppression échouée !");//Qwidget ==> les composants mt3 qt dima initliasation ta3 ay QWidget heya nullptr;

    }
}

void gestion_avis::on_pushButton_clicked()
{
    int id = ui->le_id_avis_modif->text().toInt();
         QString avis= ui->avis_enfant_modif->text();
         QString composition_avis = ui->la_composition_avis_modif->text();
         QDate dat = ui->le_date_modif2->date();
         Avis a ;
         a =Avis(id,avis,composition_avis,dat);
         bool  test = a.modifier();

         if(test) {
             QMessageBox::information(nullptr,"Modifier un avis","l'avis a été modifié avec succès !");
         }
         else {
             QMessageBox::information(nullptr,"Modifier un avis ","Modification échouée !");

         }
}

void gestion_avis::on_check_box_id_avis_clicked()
{
    ui->tab_avis->setModel(avis->afficher());

    if(ui->check_box_id_avis->isChecked() == true)
         ui->tab_avis->setModel(avis->trie_id_avis());
   else
        ui->tab_avis->setModel(avis->afficher());
}

void gestion_avis::on_pushButton_2_clicked()
{
    ui->tab_avis->setModel(avis->afficher());

    QString text_a_rechercher = ui->searchtxt->text();

    ui->tab_avis->setModel(avis->recherche_avis(text_a_rechercher));
}

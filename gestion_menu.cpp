#include "gestion_menu.h"
#include "ui_gestion_menu.h"
#include "menu1.h"
#include<QMessageBox>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include<QPixmap>
#include<QSqlQuery>

gestion_menu::gestion_menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gestion_menu)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
        ui->le_nom->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
        ui->le_composition->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
        ui->le_id_modif->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
         ui->le_nom_modif->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
        ui->la_composition_modif->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));



}

gestion_menu::~gestion_menu()
{
    delete ui;
}

void gestion_menu::on_pb_ajouter_clicked()
{
    int id = ui->le_id->text().toInt();
    QString nom = ui->le_nom->text();
    QString composition = ui->le_composition->text();
    QDate dat = ui->le_date->date();
    // Création d'un objet normal,on parle pas de widgets içi :
    Menu1 m;
    m = Menu1(id,nom,composition,dat);
    //
    bool test = m.ajouter();

    if(test) {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                   QObject::tr("Menu ajouté !\n"
                        "click ok to exit"),QMessageBox::Ok);

    }
else{QMessageBox::information(nullptr, QObject::tr("database is open"),
                              QObject::tr("erreur d'ajout !\n"
                   "click ok to exit"),QMessageBox::Ok);}
}

void gestion_menu::on_tabWidget_currentChanged(int index)
{
    ui->tab_menu1->setModel(menu1->afficher());

}

void gestion_menu::on_pb_supprimer_clicked()
{
        int id = ui->le_id_supp->text().toInt();
        bool test = menu1->supprimer(id);


        if(test) {
            QMessageBox::information(nullptr,"Supprimer un menu","le menu a été supprimé avec succès !");//Qwidget ==> les composants mt3 qt dima initliasation ta3 ay QWidget heya nullptr manha maytpointa ala chay
        }
        else {
            QMessageBox::information(nullptr,"Supprimer un menu ","suppression échouée !");//Qwidget ==> les composants mt3 qt dima initliasation ta3 ay QWidget heya nullptr;

        }
}

void gestion_menu::on_pushButton_clicked()
{
   int id = ui->le_id_modif->text().toInt();
        QString nom = ui->le_nom_modif->text();
        QString composition = ui->la_composition_modif->text();
        QDate dat = ui->le_date_modif->date();
        Menu1 m ;
        m =Menu1(id,nom,composition,dat);
        bool  test = m.modifier();

        if(test) {
            QMessageBox::information(nullptr,"Modifier un menu","le menu a été modifié avec succès !");
        }
        else {
            QMessageBox::information(nullptr,"Modifier un menu ","Modification échouée !");

        }
}


void gestion_menu::on_pb_pdf_menu_clicked()
{
    QPdfWriter pdf("C:/Users/ASUS/Desktop/Code_source_Atelier_Connexion/Menu.pdf");

                          QPainter painter(&pdf);
                         int i = 4000;
                              painter.setPen(Qt::red);
                              painter.setFont(QFont("Arial", 30));
                              painter.drawText(2300,1200,"Liste Des Menus");
                              painter.setPen(Qt::black);
                              painter.setFont(QFont("Arial", 50));
                             // painter.drawText(1100,2000,afficheDC);
                              painter.drawRect(1500,200,7300,2600);
                             // painter.drawPixmap(QRect(100,700,600,600),QPixmap("C:/Users/ASUS/Desktop/cuisine/150123410_1102641506814079_4892972152459660250_n.png"));
                              painter.drawRect(0,3000,9600,500);
                              painter.setFont(QFont("Arial", 9));
                              painter.drawText(300,3300,"ID_MENU");
                              painter.drawText(2300,3300,"NOM_MENU");
                              painter.drawText(4300,3300,"COMPOSITION_MENU");
                              painter.drawText(6300,3300,"DATE_MENU");




                              QSqlQuery query;
                              query.prepare("select * from MENU1");
                              query.exec();
                              while (query.next())
                              {
                                  painter.drawText(300,i,query.value(0).toString());
                                  painter.drawText(2300,i,query.value(1).toString());
                                  painter.drawText(4300,i,query.value(2).toString());
                                  painter.drawText(6300,i,query.value(3).toString());




                                 i = i +500;
                              }
                              int reponse = QMessageBox::question(this, "Génération PDF", "<PDF Enregistré>...Voudrez vous Afficher Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                                  if (reponse == QMessageBox::Yes)
                                  {
                                      QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/ASUS/Desktop/Code_source_Atelier_Connexion/Menu.pdf"));

                                      painter.end();
                                  }
                                  if (reponse == QMessageBox::No)
                                  {
                                       painter.end();
                                  }
}

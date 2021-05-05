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
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include <QDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>

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

void gestion_menu::on_pushButton_2_clicked()
{  QString strStream;
    QTextStream out(&strStream);



    const int rowCount = ui->tab_menu1->model()->rowCount();
    const int columnCount = ui->tab_menu1->model()->columnCount();

    out <<  "<html>\n"
        "<head>\n"

        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%60 les postes</title>\n").arg("poste")
        <<  "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<table border=1 cellspacing=0 cellpadding=2>\n";
    out << "<thead><tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
        if (! ui->tab_menu1->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tab_menu1->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tab_menu1->isColumnHidden(column)) {
                QString data = ui->tab_menu1->model()->data(ui->tab_menu1->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);

    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
    if (dialog->exec() == QDialog::Accepted) {
        document->print(&printer);
    }

    delete document;

}

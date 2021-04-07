#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableViewMaintenance->setModel(tmp_maintenance.afficher());
    ui->tableViewObjet->setModel(tmp_object.afficher());
    ui->tableViewObjet->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewObjet->setSelectionMode(QAbstractItemView::SingleSelection);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButtonAjouterObjet_clicked()
{
    QString ID=ui->lineEditIdObjet->text();
    QString NOM=ui->lineEditNom->text();
    QString CATEGORIE=ui->lineEditCategorie->text();
    QString BRAND=ui->lineEditBrand->text();
    QString REFERENCE=ui->lineEditReference->text();
    QString TYPECONTROLE=ui->lineEditTypeDeControle->text();

    Object Object(ID, NOM, CATEGORIE, BRAND, REFERENCE, TYPECONTROLE);
    if(Object.ajouter())
    {
        ui->tableViewObjet->setModel(tmp_object.afficher());
        ui->statusbar->showMessage("AJOUT : SUCCESS");
        ui->lineEditIdObjet->setText("");
        ui->lineEditNom->setText("");
        ui->lineEditCategorie->setText("");
        ui->lineEditBrand->setText("");
        ui->lineEditReference->setText("");
        ui->lineEditTypeDeControle->setText("");

    }
}

void MainWindow::on_pushButtonAjouterMaintenance_clicked()
{

    QString ID=ui->lineEditId_Maintenance->text();
    QString REFERENCE=ui->lineEditReferenceM->text();
    QString ETAT=ui->lineEditEtat->text();
    QString ID_REPARATEUR=ui->lineEditIdReperateur->text();
    QString DATE=ui->lineEditDate->text();

    maintenance maintenance(ID, REFERENCE, ETAT, DATE, ID_REPARATEUR);
    if(maintenance.ajouter())
    {
        ui->tableViewMaintenance->setModel(tmp_maintenance.afficher());
        ui->statusbar->showMessage("AJOUT : SUCCESS");
        ui->lineEditId_Maintenance->setText("");
        ui->lineEditReferenceM->setText("");
        ui->lineEditEtat->setText("");
        ui->lineEditDate->setText("");
        ui->lineEditIdReperateur->setText("");
    }
}


void MainWindow::on_SupprimerMaintenance_clicked()
{
    QItemSelectionModel *select = ui->tableViewMaintenance->selectionModel();
    QString ID_maintenance =select->selectedRows(0).value(0).data().toString();

    bool test=tmp_maintenance.supprimer(ID_maintenance);
    if(test)
    {ui->tableViewMaintenance->setModel(tmp_maintenance.afficher());//refresh
    }

}

void MainWindow::on_pushButtonM_clicked()
{
    ui->pushButtonM->setText("Modifier");
    if(ui->pushButtonM->isChecked())
    {
        QSqlTableModel *tableModel= new QSqlTableModel();
        tableModel->setTable("MAINTENANCE");
        tableModel->select();
        ui->tableViewMaintenance->setModel(tableModel);
        ui->pushButtonM->setText("Tableau Modifiable");
    }
}

void MainWindow::on_pushButtonSupprimerO_clicked()
{
    QItemSelectionModel *select = ui->tableViewObjet->selectionModel();
    QString ID_Objet =select->selectedRows(0).value(0).data().toString();

    bool test=tmp_object.supprimerO(ID_Objet);
    if(test)
    {
        ui->tableViewObjet->setModel(tmp_object.afficher());//refresh
    }
}

void MainWindow::on_pushButtonModifierO_clicked()
{
    ui->pushButtonModifierO->setText("Modifier");
    if(ui->pushButtonModifierO->isChecked())
    {
        QSqlTableModel *tableModel= new QSqlTableModel();
        tableModel->setTable("OBJET");
        tableModel->select();
        ui->tableViewObjet->setModel(tableModel);
        ui->pushButtonModifierO->setText("Tableau Modifiable");
    }

}

void MainWindow::on_pushButton_Sort_clicked()
{

}

void MainWindow::on_pushButton_SortObject_clicked()
{
    ui->tableViewObjet->setModel(tmp_object.afficher());
    QString critere;
    //tri simple
    if(ui->checkBox_IdObjet->isChecked() && !ui->checkBox_Nom->isChecked() && !ui->checkBox_Categorie->isChecked() && !ui->checkBox_Brand->isChecked() && !ui->checkBox_Reference->isChecked() && !ui->checkBox_TypeDeControle->isChecked())
    {
        critere="ID_OBJET";
    }
    else if(!ui->checkBox_IdObjet->isChecked() && ui->checkBox_Nom->isChecked() && !ui->checkBox_Categorie->isChecked() && !ui->checkBox_Brand->isChecked() && !ui->checkBox_Reference->isChecked() && !ui->checkBox_TypeDeControle->isChecked())
    {
        critere="NOM";
    }
    else if(!ui->checkBox_IdObjet->isChecked() && !ui->checkBox_Nom->isChecked() && ui->checkBox_Categorie->isChecked() && !ui->checkBox_Brand->isChecked() && !ui->checkBox_Reference->isChecked() && !ui->checkBox_TypeDeControle->isChecked())
    {
        critere="CATEGORIE";
    }
    else if(!ui->checkBox_IdObjet->isChecked() && !ui->checkBox_Nom->isChecked() && !ui->checkBox_Categorie->isChecked() && ui->checkBox_Brand->isChecked() && !ui->checkBox_Reference->isChecked() && !ui->checkBox_TypeDeControle->isChecked())
    {
        critere="BRAND";
    }
    else if(!ui->checkBox_IdObjet->isChecked() && !ui->checkBox_Nom->isChecked() && !ui->checkBox_Categorie->isChecked() && !ui->checkBox_Brand->isChecked() && ui->checkBox_Reference->isChecked() && !ui->checkBox_TypeDeControle->isChecked())
    {
        critere="REFERENCE";
    }
    else if(!ui->checkBox_IdObjet->isChecked() && !ui->checkBox_Nom->isChecked() && !ui->checkBox_Categorie->isChecked() && !ui->checkBox_Brand->isChecked() && !ui->checkBox_Reference->isChecked() && ui->checkBox_TypeDeControle->isChecked())
    {
        critere="TYPECONTROLE";
    }
    //tri 2 critere
    else if(ui->checkBox_IdObjet->isChecked() && ui->checkBox_Nom->isChecked() && !ui->checkBox_Categorie->isChecked() && !ui->checkBox_Brand->isChecked() && !ui->checkBox_Reference->isChecked() && !ui->checkBox_TypeDeControle->isChecked())
    {
        critere="ID_OBJET, NOM";
    }
    else if(ui->checkBox_IdObjet->isChecked() && !ui->checkBox_Nom->isChecked() && ui->checkBox_Categorie->isChecked() && !ui->checkBox_Brand->isChecked() && !ui->checkBox_Reference->isChecked() && !ui->checkBox_TypeDeControle->isChecked())
    {
        critere="ID_OBJET,CATEGORIE";
    }
    else if(ui->checkBox_IdObjet->isChecked() && !ui->checkBox_Nom->isChecked() && !ui->checkBox_Categorie->isChecked() && ui->checkBox_Brand->isChecked() && !ui->checkBox_Reference->isChecked() && !ui->checkBox_TypeDeControle->isChecked())
    {
        critere="ID_OBJET,BRAND";
    }
    else if(ui->checkBox_IdObjet->isChecked() && !ui->checkBox_Nom->isChecked() && !ui->checkBox_Categorie->isChecked() && !ui->checkBox_Brand->isChecked() && ui->checkBox_Reference->isChecked() && !ui->checkBox_TypeDeControle->isChecked())
    {
        critere="ID_OBJET,REFERENCE";
    }
    else if(ui->checkBox_IdObjet->isChecked() && !ui->checkBox_Nom->isChecked() && !ui->checkBox_Categorie->isChecked() && !ui->checkBox_Brand->isChecked() && !ui->checkBox_Reference->isChecked() && ui->checkBox_TypeDeControle->isChecked())
    {
        critere="ID_OBJET,TYPECONTROLE";
    }


    //tri 3 critere
    else if(ui->checkBox_IdObjet->isChecked() && ui->checkBox_Nom->isChecked() && ui->checkBox_Categorie->isChecked() && !ui->checkBox_Brand->isChecked() && !ui->checkBox_Reference->isChecked() && !ui->checkBox_TypeDeControle->isChecked())
    {
        critere="ID_OBJET,NOM,CATEGORIE";
    }
    else if(ui->checkBox_IdObjet->isChecked() && ui->checkBox_Nom->isChecked() && !ui->checkBox_Categorie->isChecked() && ui->checkBox_Brand->isChecked() && !ui->checkBox_Reference->isChecked() && !ui->checkBox_TypeDeControle->isChecked())
    {
        critere="ID_OBJET,NOM,BRAND";
    }


    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Aucun critere"),
                              QObject::tr("Veuillez choisir un critere.\n"), QMessageBox::Cancel);

    }

    QString order = ui->comboBoxObjet->currentText();
    ui->tableViewObjet->setModel(tmp_object.trier(critere,order));

}

void MainWindow::on_pushButtonRechercheO_clicked()
{
    int critere=0;
    if(ui->checkBox_IdObjet->isChecked())
        critere=0;
    else if(ui->checkBox_Nom->isChecked())
        critere=1;
    else if(ui->checkBox_Categorie->isChecked())
        critere=2;
    else if(ui->checkBox_Brand->isChecked())
        critere=3;
    else if(ui->checkBox_Reference->isChecked())
        critere=4;
    else if(ui->checkBox_TypeDeControle->isChecked())
        critere=5;

    QString input = ui->lineEditRechercheO->text();

    QSqlQueryModel *test=tmp_object.chercher(input,critere);


    if(test != nullptr)
    {
        ui->tableViewObjet->setModel(test);
    }
    else
    {
        ui->tableViewObjet->setModel(test);
    }

}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"categorie.h"
#include "activite.h"
#include <QDateEdit>
#include <QDate>
#include <QModelIndex>
#include"connexion.h"
#include <QTabWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_toolButton_clicked()
{
    ui->stackedWidget ->setCurrentIndex(1);
}

void MainWindow::on_toolButton_4_clicked()
{
    ui->stackedWidget ->setCurrentIndex(0);
}

void MainWindow::on_toolButton_2_clicked()
{
    ui->stackedWidget ->setCurrentIndex(2);
    ui->tabCat->setModel(tabCat.show_categorie());
}

void MainWindow::on_toolButton_7_clicked()
{
    ui->stackedWidget ->setCurrentIndex(0);
}

void MainWindow::on_toolButton_9_clicked()
{
    ui->stackedWidget ->setCurrentIndex(3);
}

void MainWindow::on_toolButton_11_clicked()
{
    ui->stackedWidget ->setCurrentIndex(0);
}


void MainWindow::on_tabCat_clicked(const QModelIndex &index)
{
    QString val=ui->tabCat->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("SELECT * FROM CATEGORIE WHERE NOM = '"+val+"'");
        if(query.exec())
        {
            while (query.next())
            {
                ui->lineEdit_toChange->setText(query.value(1).toString());
            }
        }
}

void MainWindow::on_toolButton_16_clicked()
{
    QString nom = ui->lineEdit_toChange->text();
        tabCat.remove_categorie(nom);
        ui->tabCat->setModel(tabCat.show_categorie());
        ui->lineEdit_toChange->clear();
}

void MainWindow::on_toolButton_15_clicked()
{
    QString val=ui->lineEdit_toChange->text();
        QSqlQuery query;
        query.prepare("SELECT * FROM CATEGORIE WHERE NOM = '"+val+"'");
        if(query.exec())
        {
            while (query.next())
            {
                ui->stackedWidget->setCurrentIndex(7);
                ui->id_2->setText(query.value(0).toString());
                ui->nom_2->setText(query.value(1).toString());
                ui->description_2->setText(query.value(2).toString());
            }
        }
}

void MainWindow::on_toolButton_18_clicked()
{

    QString id= ui->id_2->text();
    QString nom= ui->nom_2->text();
    QString description= ui->description_2->text();



    int x=0;
    if (x==0)
    {
        categorie c(id,nom,description);
        c.modify_categorie();
    }
    ui->stackedWidget->setCurrentIndex(2);
    ui->tabCat->setModel(tabCat.show_categorie());
}

//**************************************************************************************************************************


void MainWindow::on_toolButton_12_clicked()

{
    QString id= ui->lineEdit_Id->text();
    QString nom= ui->lineEdit_name->text();
    QString currentTabName= ui->calendarWidget->selectedDate().toString();
    QString starttime= ui->timeEdit_starttime->time().toString();
    QString endtime= ui->timeEdit_endtime->time().toString();
    QString nomcat=ui->comboBox->currentText();
    activite s(id,nom,currentTabName,starttime,endtime,nomcat);
    s.add_activite();
    ui->stackedWidget ->setCurrentIndex(4);
    ui->lineEdit_2->setText(nomcat);
    if(currentTabName=="lun")
    {
    ui->tableView->setModel(actTable.show_act(currentTabName , nomcat));
    }
    else if(currentTabName=="mar")
    {
    ui->tableView_3->setModel(actTable.show_act(currentTabName , nomcat));
    }
    else if(currentTabName=="mer")
    {
    ui->tableView_4->setModel(actTable.show_act(currentTabName , nomcat));
    }
    else if(currentTabName=="jeu")
    {
    ui->tableView_5->setModel(actTable.show_act(currentTabName , nomcat));
    }
    else if(currentTabName=="ven")
    {
    ui->tableView_6->setModel(actTable.show_act(currentTabName , nomcat));
    }
    else if(currentTabName=="sam")
    {
    ui->tableView_7->setModel(actTable.show_act(currentTabName , nomcat));
    }
    else
    {
    ui->tableView_8->setModel(actTable.show_act(currentTabName , nomcat));
    }

}

void MainWindow::on_toolButton_5_clicked()
{
    ui->stackedWidget ->setCurrentIndex(0);
}

void MainWindow::on_toolButton_10_clicked()
{
    ui->stackedWidget ->setCurrentIndex(5);
    QSqlQueryModel *mod= new QSqlQueryModel();
        mod->setQuery(("select NOM from CATEGORIE"));
        ui->comboBox->setModel(mod);
}

void MainWindow::on_toolButton_13_clicked()
{
    ui->stackedWidget ->setCurrentIndex(0);
}

void MainWindow::on_toolButton_14_clicked()
{

    QString id= ui->id->text();
    QString nom= ui->nom->text();
    QString description= ui->description->text();



    int x=0;
    if (x==0)
    {
        categorie c(id,nom,description);
        c.add_categorie();
    }
    ui->stackedWidget ->setCurrentIndex(2);
    ui->tabCat->setModel(tabCat.show_categorie());
}

void MainWindow::on_toolButton_8_clicked()
{
    ui->stackedWidget ->setCurrentIndex(0);
    ui->tableView->setModel(actTable.show());
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("SELECT * FROM ACTIVITE WHERE ID = '"+val+"'");
        if(query.exec())
        {
            while (query.next())
            {
                ui->stackedWidget->setCurrentIndex(6);
                ui->lineEdit_Id_3->setText(query.value(0).toString());
                ui->lineEdit_name_3->setText(query.value(1).toString());
                ui->calendarWidget_3->setSelectedDate(query.value(2).toDate());
                ui->timeEdit_starttime_3->setTime(query.value(3).toTime());
                ui->timeEdit_endtime_3->setTime(query.value(4).toTime());
            }
        }
}

void MainWindow::on_toolButton_29_clicked()
{
    QString id= ui->lineEdit_Id_3->text();
    QString nom= ui->lineEdit_name_3->text();
    QString currentTabName= ui->calendarWidget_3->selectedDate().toString();
    QString starttime= ui->timeEdit_starttime_3->time().toString();
    QString endtime= ui->timeEdit_endtime_3->time().toString();
    QString nomcat= ui->lineEdit_3->text();
    activite s(id,nom,currentTabName,starttime,endtime,nomcat);

    s.modify();
    ui->lineEdit_2->setText(nomcat);


    if(currentTabName=="lun")
    {
    ui->tableView->setModel(actTable.show_act(currentTabName , nomcat));
    }
    else if(currentTabName=="mar")
    {
    ui->tableView_3->setModel(actTable.show_act(currentTabName , nomcat));
    }
    else if(currentTabName=="mer")
    {
    ui->tableView_4->setModel(actTable.show_act(currentTabName , nomcat));
    }
    else if(currentTabName=="jeu")
    {
    ui->tableView_5->setModel(actTable.show_act(currentTabName , nomcat));
    }
    else if(currentTabName=="ven")
    {
    ui->tableView_6->setModel(actTable.show_act(currentTabName , nomcat));
    }
    else if(currentTabName=="sam")
    {
    ui->tableView_7->setModel(actTable.show_act(currentTabName , nomcat));
    }
    else
    {
    ui->tableView_8->setModel(actTable.show_act(currentTabName , nomcat));
    }
    ui->stackedWidget ->setCurrentIndex(4);
}

void MainWindow::on_tabCat_activated(const QModelIndex &index)
{
    QString act=ui->tabCat->model()->data(index).toString();
    ui->stackedWidget ->setCurrentIndex(4);
        ui->tableView->setModel(actTable.show_cat(act));
        ui->lineEdit_2->setText(act);
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("SELECT * FROM ACTIVITE WHERE NOM = '"+val+"'");
        if(query.exec())
        {
            while (query.next())
            {
                ui->lineEdit_5->setText(query.value(1).toString());
            }
        }
}

void MainWindow::on_toolButton_19_clicked()
{
    QString currentTabName = ui->tabWidget->currentWidget()->objectName();
    QString id = ui->lineEdit_5->text();
    QString nomcat = ui->lineEdit_2->text();
    actTable.remove(id);

    if(currentTabName=="lun")
    {
    ui->tableView->setModel(actTable.show_act(currentTabName , nomcat));
    }
    else if(currentTabName=="mar")
    {
    ui->tableView_3->setModel(actTable.show_act(currentTabName , nomcat));
    }
    else if(currentTabName=="mer")
    {
    ui->tableView_4->setModel(actTable.show_act(currentTabName , nomcat));
    }
    else if(currentTabName=="jeu")
    {
    ui->tableView_5->setModel(actTable.show_act(currentTabName , nomcat));
    }
    else if(currentTabName=="ven")
    {
    ui->tableView_6->setModel(actTable.show_act(currentTabName , nomcat));
    }
    else if(currentTabName=="sam")
    {
    ui->tableView_7->setModel(actTable.show_act(currentTabName , nomcat));
    }
    else
    {
    ui->tableView_8->setModel(actTable.show_act(currentTabName , nomcat));
    }

}

void MainWindow::on_toolButton_20_clicked()
{
    QString val=ui->lineEdit_5->text();
        QSqlQuery query;
        query.prepare("SELECT * FROM ACTIVITE WHERE NOM = '"+val+"'");
        if(query.exec())
        {
            while (query.next())
            {
                ui->stackedWidget->setCurrentIndex(6);
                ui->lineEdit_Id_3->setText(query.value(0).toString());
                ui->lineEdit_name_3->setText(query.value(1).toString());
                ui->calendarWidget_3->setSelectedDate(query.value(2).toDate());
                ui->timeEdit_starttime_3->setTime(query.value(3).toTime());
                ui->timeEdit_endtime_3->setTime(query.value(4).toTime());
                ui->lineEdit_3->setText(query.value(5).toString());
            }
        }
}

void MainWindow::on_toolButton_21_clicked()
{
    ui->stackedWidget ->setCurrentIndex(1);
}

void MainWindow::on_toolButton_45_clicked()
{
    ui->stackedWidget ->setCurrentIndex(2);
}

void MainWindow::on_toolButton_46_clicked()
{
    ui->stackedWidget ->setCurrentIndex(3);
}

void MainWindow::on_toolButton_47_clicked()
{
     ui->stackedWidget ->setCurrentIndex(4);
}

void MainWindow::on_toolButton_48_clicked()
{
    ui->stackedWidget ->setCurrentIndex(5);
}

void MainWindow::on_toolButton_49_clicked()
{
    ui->stackedWidget ->setCurrentIndex(6);
}

void MainWindow::on_toolButton_22_clicked()
{
    QString name=ui->lineEdit_2->text();
      //  ui->tableView->setModel(actTable.search(name));
}

void MainWindow::on_toolButton_53_clicked()
{
    QString name=ui->lineEdit_toChange->text();
        ui->tabCat->setModel(tabCat.search(name));
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    QString currentTabName = ui->tabWidget->currentWidget()->objectName();
    QString nom = ui->lineEdit_2->text();
    if(currentTabName=="lun")
    {
    ui->tableView->setModel(actTable.show_act(currentTabName , nom));
    }
    else if(currentTabName=="mar")
    {
    ui->tableView_3->setModel(actTable.show_act(currentTabName , nom));
    }
    else if(currentTabName=="mer")
    {
    ui->tableView_4->setModel(actTable.show_act(currentTabName , nom));
    }
    else if(currentTabName=="jeu")
    {
    ui->tableView_5->setModel(actTable.show_act(currentTabName , nom));
    }
    else if(currentTabName=="ven")
    {
    ui->tableView_6->setModel(actTable.show_act(currentTabName , nom));
    }
    else if(currentTabName=="sam")
    {
    ui->tableView_7->setModel(actTable.show_act(currentTabName , nom));
    }
    else
    {
    ui->tableView_8->setModel(actTable.show_act(currentTabName , nom));
    }
}

void MainWindow::on_toolButton_51_clicked()
{
    ui->tabCat->setModel(tabCat.show_Asc());
}

void MainWindow::on_tableView_3_clicked(const QModelIndex &index)
{
    QString val=ui->tableView_3->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("SELECT * FROM ACTIVITE WHERE NOM = '"+val+"'");
        if(query.exec())
        {
            while (query.next())
            {
                ui->lineEdit_5->setText(query.value(1).toString());
            }
        }
}

void MainWindow::on_tableView_4_clicked(const QModelIndex &index)
{
    QString val=ui->tableView_4->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("SELECT * FROM ACTIVITE WHERE NOM = '"+val+"'");
        if(query.exec())
        {
            while (query.next())
            {
                ui->lineEdit_5->setText(query.value(1).toString());
            }
        }
}

void MainWindow::on_tableView_5_clicked(const QModelIndex &index)
{
    QString val=ui->tableView_5->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("SELECT * FROM ACTIVITE WHERE NOM = '"+val+"'");
        if(query.exec())
        {
            while (query.next())
            {
                ui->lineEdit_5->setText(query.value(1).toString());
            }
        }
}

void MainWindow::on_tableView_6_clicked(const QModelIndex &index)
{
    QString val=ui->tableView_6->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("SELECT * FROM ACTIVITE WHERE NOM = '"+val+"'");
        if(query.exec())
        {
            while (query.next())
            {
                ui->lineEdit_5->setText(query.value(1).toString());
            }
        }
}

void MainWindow::on_tableView_7_clicked(const QModelIndex &index)
{
    QString val=ui->tableView_7->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("SELECT * FROM ACTIVITE WHERE NOM = '"+val+"'");
        if(query.exec())
        {
            while (query.next())
            {
                ui->lineEdit_5->setText(query.value(1).toString());
            }
        }
}

void MainWindow::on_tableView_8_clicked(const QModelIndex &index)
{
    QString val=ui->tableView_8->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("SELECT * FROM ACTIVITE WHERE NOM = '"+val+"'");
        if(query.exec())
        {
            while (query.next())
            {
                ui->lineEdit_5->setText(query.value(1).toString());
            }
        }
}

void MainWindow::on_toolButton_52_clicked()
{
    QString currentTabName = ui->tabWidget->currentWidget()->objectName();
    QString nom = ui->lineEdit_2->text();
    if(currentTabName=="lun")
    {
    ui->tableView->setModel(actTable.show_asc(currentTabName , nom));
    }
    else if(currentTabName=="mar")
    {
    ui->tableView_3->setModel(actTable.show_asc(currentTabName , nom));
    }
    else if(currentTabName=="mer")
    {
    ui->tableView_4->setModel(actTable.show_asc(currentTabName , nom));
    }
    else if(currentTabName=="jeu")
    {
    ui->tableView_5->setModel(actTable.show_asc(currentTabName , nom));
    }
    else if(currentTabName=="ven")
    {
    ui->tableView_6->setModel(actTable.show_asc(currentTabName , nom));
    }
    else if(currentTabName=="sam")
    {
    ui->tableView_7->setModel(actTable.show_asc(currentTabName , nom));
    }
    else
    {
    ui->tableView_8->setModel(actTable.show_asc(currentTabName , nom));
    }
}

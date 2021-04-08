#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menu1.h"
#include "gestion_menu.h"
#include"gestion_avis.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 this->setWindowTitle("GESTION DES REPAS");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    gestion_menu *g = new gestion_menu(this);
    g->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    gestion_avis *g1 = new gestion_avis(this);
    g1->show();
}

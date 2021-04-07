#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "object.h"
#include <QSqlQueryModel>
#include "maintenance.h"
#include <QStatusBar>
#include <QSound>
#include <QFileDialog>
#include <QTableView>
#include <QItemSelectionModel>
#include <QStandardItemModel>
#include <QStatusBar>
#include <QTextStream>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonAjouterObjet_clicked();

    void on_pushButtonAjouterMaintenance_clicked();

    void on_SupprimerMaintenance_clicked(int);


    void on_SupprimerMaintenance_clicked();

    void on_pushButton_2_clicked();

    void on_pushButtonM_clicked();

    void on_pushButtonSupprimerO_clicked();

    void on_pushButtonModifierO_clicked();

    void on_pushButton_Sort_clicked();

    void on_pushButton_SortObject_clicked();

    void on_pushButtonRechercheO_clicked();

private:
    Ui::MainWindow *ui;
    Object tmp_object;
    maintenance tmp_maintenance;
    QSqlQueryModel *model = new QSqlQueryModel ;

};
#endif // MAINWINDOW_H

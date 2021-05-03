#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "activite.h"
#include "categorie.h"
#include "ingredient.h"
#include "arduino.h"
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>

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
    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
        // ce slot est lancé à chaque réception d'un message de Arduino
    void on_toolButton_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_7_clicked();

    void on_toolButton_9_clicked();

    void on_toolButton_11_clicked();

    void on_toolButton_12_clicked();

    void on_toolButton_5_clicked();

    void on_toolButton_10_clicked();

    void on_toolButton_13_clicked();

    void on_toolButton_14_clicked();

    void on_toolButton_8_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_toolButton_29_clicked();



    void on_tabCat_clicked(const QModelIndex &index);

    void on_toolButton_16_clicked();

    void on_toolButton_15_clicked();



    void on_toolButton_18_clicked();

    void on_tabCat_activated(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_toolButton_19_clicked();

    void on_toolButton_20_clicked();

    void on_toolButton_21_clicked();

    void on_toolButton_45_clicked();

    void on_toolButton_46_clicked();

    void on_toolButton_47_clicked();

    void on_toolButton_48_clicked();

    void on_toolButton_49_clicked();

    void on_toolButton_22_clicked();

    void on_toolButton_53_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_toolButton_51_clicked();

    void on_tableView_3_clicked(const QModelIndex &index);

    void on_tableView_4_clicked(const QModelIndex &index);

    void on_tableView_5_clicked(const QModelIndex &index);

    void on_tableView_6_clicked(const QModelIndex &index);

    void on_tableView_7_clicked(const QModelIndex &index);

    void on_tableView_8_clicked(const QModelIndex &index);

    void on_toolButton_52_clicked();
    void pdf();
    void pdf_ing();

    void on_toolButton_6_clicked();

    void on_toolButton_23_clicked();

    void on_toolButton_24_clicked();

    void on_toolButton_17_clicked();

    void on_toolButton_26_clicked();

    void on_toolButton_25_clicked();

    void on_toolButton_27_clicked();

    void on_toolButton_30_clicked();

    void on_toolButton_28_clicked();

    void on_toolButton_79_clicked();

    void on_toolButton_130_clicked();

    void on_toolButton_77_clicked();

    void on_toolButton_78_clicked();

    void on_toolButton_81_clicked();

    void on_toolButton_129_clicked();

    void on_toolButton_83_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_82_clicked();

    void on_ingTab_activated(const QModelIndex &index);

    void on_toolButton_32_clicked();

private:
    Ui::MainWindow *ui;
    activite actTable;
    categorie tabCat;
    ingredient ingTab;
    QByteArray data; // variable contenant les données reçues

        Arduino A; // objet temporaire
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "activite.h"
#include "categorie.h"
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

private:
    Ui::MainWindow *ui;
    activite actTable;
    categorie tabCat;
};
#endif // MAINWINDOW_H

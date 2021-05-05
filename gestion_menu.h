#ifndef GESTION_MENU_H
#define GESTION_MENU_H

#include <QWidget>
#include"menu1.h"

namespace Ui {
class gestion_menu;
}

class gestion_menu : public QWidget
{
    Q_OBJECT

public:
    explicit gestion_menu(QWidget *parent = nullptr);
    ~gestion_menu();

private slots:
    void on_pb_ajouter_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pb_supprimer_clicked();

    void on_pushButton_clicked();



    void on_pb_pdf_menu_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::gestion_menu *ui;
    Menu1 * menu1;
};

#endif // GESTION_MENU_H

#ifndef GESTION_AVIS_H
#define GESTION_AVIS_H

#include <QWidget>
#include "avis.h"

namespace Ui {
class gestion_avis;
}

class gestion_avis : public QWidget
{
    Q_OBJECT

public:
    explicit gestion_avis(QWidget *parent = nullptr);
    ~gestion_avis();

private slots:
    void on_pb_ajouter_avis_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pb_supprimer_avis_clicked();

    void on_pushButton_clicked();

    void on_check_box_id_avis_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::gestion_avis *ui;
    Avis * avis;
};

#endif // GESTION_AVIS_H

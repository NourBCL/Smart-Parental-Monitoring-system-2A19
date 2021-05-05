#include "statistics.h"
#include "ui_statistics.h"
#include "avis.h"
#include "menu1.h"

statistics::statistics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistics)
{
    {
        ui->setupUi(this);
        this->setWindowTitle("STATISTIQUES");
        QPieSeries *series = new QPieSeries();

        Avis c ;
        Menu1 m;
        int  total = c.total_avis()+m.total_menu1()/c.total_avis();

        series->append("Avis",c.total_avis());
        series->append("Total des Menus par rapport au Avis ",total);
        series->append("Menus",m.total_menu1());
        series->setHoleSize(0.2);
        QPieSlice *slice = series->slices().at(0);
        slice->setLabelVisible();

        QPieSlice *slice1 = series->slices().at(1);
        slice1->setExploded();
        slice1->setLabelVisible();

        QPieSlice *slice2 = series->slices().at(2);
        slice2->setLabelVisible();

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle(" Total des Menu / Avis :");
        chart->legend()->hide();
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QChartView *chartview = new QChartView(chart);
        chartview->setRenderHint(QPainter::Antialiasing);
        chartview->setParent(ui->horizontalFrame);
    }
}
statistics::~statistics()
{


    delete ui;

}

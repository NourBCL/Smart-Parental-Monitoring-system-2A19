
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"categorie.h"
#include "activite.h"
#include <QDateEdit>
#include <QDate>
#include <QModelIndex>
#include"connexion.h"
#include <QTabWidget>
#include <QMessageBox>
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QTextStream>
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

void MainWindow::on_toolButton_13_clicked()
{
    ui->stackedWidget ->setCurrentIndex(0);
}

//Add categorie

void MainWindow::on_toolButton_14_clicked()
{

    QString id= ui->id->text();
    QString nom= ui->nom->text();
    QString description= ui->description->text();



    int x=0;
    if(id=="")
    {
    QMessageBox::critical(nullptr, QObject::tr("WARNING"),
    QObject::tr("ID can't be empty"), QMessageBox::Ok);
    x++;
    }
    else if(nom=="")
    {
    QMessageBox::critical(nullptr, QObject::tr("WARNING"),
    QObject::tr("Name cant' be empty"), QMessageBox::Ok);
    x++;
    }
    else if(description=="")
    {
    QMessageBox::critical(nullptr, QObject::tr("WARNING"),
    QObject::tr("Description can't be empty"), QMessageBox::Ok);
    x++;
    }
    for (int i =0;i<id.size();i++)
    {
        if (id[i].isLetter())
    {
    QMessageBox::critical(nullptr, QObject::tr("WARNING"),
    QObject::tr("ID must contain only numbers"), QMessageBox::Ok);
    x++;
    }
        else if (id[i].isDigit())
    {
    qDebug("true");
    }
    }
    for (int i =0;i<nom.size();i++)
    {
        if (nom[i].isDigit())
    {
    QMessageBox::critical(nullptr, QObject::tr("WARNING"),
    QObject::tr("Name must contain only letters"), QMessageBox::Ok);
    x++;
    }
        else if (nom[i].isLetter())
    {
    qDebug("true");
    nom.replace(0, 1, nom[0].toUpper());
    }
    }
    if (x==0)
    {
        description.replace(0, 1, description[0].toUpper());
        categorie c(id,nom,description);

        bool test = c.add_categorie();
        if(test)
            {
                categorie().show_notification("Add category","category added successfully");
            }
        ui->id->clear();
        ui->nom->clear();
        ui->description->clear();
        ui->stackedWidget ->setCurrentIndex(2);
        ui->tabCat->setModel(tabCat.show_categorie());
    }

}

//Affichage categorie

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

//Delete categorie

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

// Modification categorie
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
    if(description=="")
        {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
        QObject::tr("Description can't be empty"), QMessageBox::Ok);
        x++;
        }
    if (x==0)
    {
        categorie c(id,nom,description);
        bool test=c.modify_categorie();
        if(test)
            {
                categorie().show_notification("Modify category","category modified successfully");
            }
         ui->id->clear();
         ui->nom->clear();
         ui->description->clear();
         ui->stackedWidget->setCurrentIndex(2);
         ui->tabCat->setModel(tabCat.show_categorie());
    }

}

void MainWindow::on_toolButton_51_clicked()
{
    ui->tabCat->setModel(tabCat.show_Asc());
}

void MainWindow::on_toolButton_53_clicked()
{
    QString name=ui->lineEdit_toChange->text();
        ui->tabCat->setModel(tabCat.search(name));
}
//**************************************************************************************************************************

// Add activity

void MainWindow::on_toolButton_10_clicked()
{
    ui->stackedWidget ->setCurrentIndex(5);
    QSqlQueryModel *mod= new QSqlQueryModel();
        mod->setQuery(("select NOM from CATEGORIE"));
        ui->comboBox->setModel(mod);
}

void MainWindow::on_toolButton_12_clicked()

{
    QString id= ui->lineEdit_Id->text();
    QString nom= ui->lineEdit_name->text();
    QString currentTabName= ui->calendarWidget->selectedDate().toString();
    QString starttime= ui->timeEdit_starttime->time().toString();
    QString endtime= ui->timeEdit_endtime->time().toString();
    QString nomcat=ui->comboBox->currentText();
    int x = 0;
    if(id=="")
    {
    QMessageBox::critical(nullptr, QObject::tr("WARNING"),
    QObject::tr("ID can't be empty"), QMessageBox::Ok);
    x++;
    }
    else if(nom=="")
    {
    QMessageBox::critical(nullptr, QObject::tr("WARNING"),
    QObject::tr("Name can't be empty"), QMessageBox::Ok);
    x++;
    }
    else if(ui->calendarWidget->selectedDate()<QDate().currentDate())
    {
    QMessageBox::critical(nullptr, QObject::tr("WARNING"),
    QObject::tr("selected date in unavailable"), QMessageBox::Ok);
    x++;
    }
    else if(starttime<"08:00:00")
    {
    QMessageBox::critical(nullptr, QObject::tr("WARNING"),
    QObject::tr("activities start at 8am"), QMessageBox::Ok);
    x++;
    }
    else if(endtime<starttime)
    {
    QMessageBox::critical(nullptr, QObject::tr("WARNING"),
    QObject::tr("Check the endtime"), QMessageBox::Ok);
    x++;
    }
    if (x==0)
    {
    activite s(id,nom,currentTabName,starttime,endtime,nomcat);
    bool test = s.add_activite();
    if(test)
        {
            activite().show_notification("Add activity","Activity added successfully");
        }
     ui->lineEdit_Id->clear();
     ui->lineEdit_name->clear();
     ui->timeEdit_starttime->clear();
     ui->timeEdit_endtime->clear();
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
}

void MainWindow::on_toolButton_5_clicked()
{
    ui->stackedWidget ->setCurrentIndex(0);
}




void MainWindow::on_toolButton_8_clicked()
{
    ui->stackedWidget ->setCurrentIndex(0);
    ui->tableView->setModel(actTable.show());
}

//Modification Act
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
    int x=0;

    if(nom=="")
    {
    QMessageBox::critical(nullptr, QObject::tr("WARNING"),
    QObject::tr("Name can't be empty"), QMessageBox::Ok);
    x++;
    }
    else if(ui->calendarWidget_3->selectedDate()<QDate().currentDate())
    {
    QMessageBox::critical(nullptr, QObject::tr("WARNING"),
    QObject::tr("selected date in unavailable"), QMessageBox::Ok);
    x++;
    }
    else if(starttime<"08:00:00")
    {
    QMessageBox::critical(nullptr, QObject::tr("WARNING"),
    QObject::tr("activities start at 8am"), QMessageBox::Ok);
    x++;
    }
    else if(endtime<starttime)
    {
    QMessageBox::critical(nullptr, QObject::tr("WARNING"),
    QObject::tr("Check the endtime"), QMessageBox::Ok);
    x++;
    }
    if (x==0){

    activite s(id,nom,currentTabName,starttime,endtime,nomcat);

    bool test = s.modify();
    if(test)
        {
            activite().show_notification("Modify activity","Activity modified successfully");
        }

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
}

void MainWindow::on_tabCat_activated(const QModelIndex &index)
{
    QString act=ui->tabCat->model()->data(index).toString();
    ui->stackedWidget ->setCurrentIndex(4);
        ui->tableView->setModel(actTable.show_cat(act));
        ui->tableView_9->setModel(actTable.show());
        ui->lineEdit_2->setText(act);
}

//Suppression Act
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



//Affichage Act
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
void MainWindow::pdf()
{
    QString strStream;
    QString currentDate = QDateTime().currentDateTime().toString();
    QTextStream out(&strStream);
    const int rowCount = ui->tableView_9->model()->rowCount();
    const int columnCount = ui->tableView_9->model()->columnCount();
    out <<
     "<html>\n"
    "<head>\n"
    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
    <<QString("<title>%1</title>\n").arg("strTitle")
    <<"</head>\n"
    "<body bgcolor=#ffffff link=#5000A0>\n"
     <<QString(currentDate)
    <<//"<align='right'> " << datefich << "</align>"
    "<center> <img src="":/IMG/IMG/logo2.png"" width=""100"" height=""100"" > <br> <br><H1>LIST OF ACTIVITIES</H1> <br> <br><table border=1 cellspacing=0 cellpadding=2>\n";
    // headers
    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++)
    if (!ui->tableView_9->isColumnHidden(column))
    out << QString("<th>%1</th>").arg(ui->tableView_9->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";
    // data table
    for (int row = 0; row < rowCount; row++)
    {
    out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
    for (int column = 0; column < columnCount; column++)
    {
    if (!ui->tableView_9->isColumnHidden(column))
    {
    QString data = ui->tableView_9->model()->data(ui->tableView_9->model()->index(row, column)).toString().simplified();
    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
    }
    }
    out << "</tr>\n";
    }
    out <<  "</table> </center>\n"
         "<br> <br> <br> <br>"
    "</body>\n"
    "<footer>\n"
            "<div class = ""container"">"
                "<div class = ""row"">"
                    "<div>"
                        "<div><img src="":/IMG/IMG/icons8-facebook-30.png""> <span>Control Patrol TN </div>\n"
                        "<br>"
                        "<div><img src="":/IMG/IMG/icons8-instagram-30.png""> <span>@controlpatrol.tn </div>\n"
                        "<p>Generated from : Control Patrol.exe "
                    "</div>"
                "</div>"
            "</div>"
    "</footer>\n"
    "</html>\n";
    QString filter = "pdf (*.pdf) ";
    QString fileName = QFileDialog::getSaveFileName(this, "save in", QDir::homePath(),filter);
    if(fileName.isEmpty()&&fileName.isNull())
    {
        activite().show_notification("error","exporting is cancelled");
    }
    else
    {
    QPrinter printer (QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    QTextDocument doc;
    doc.setHtml(strStream);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
    activite().show_notification("PDF creation","File created successfully");
    }
}

void MainWindow::on_toolButton_6_clicked()
{
    if(ui->tableView_9->verticalHeader()->count()==0)
            {
                activite().show_notification("error","no data to export");
            }
            else
            {
                pdf();
            }
}

void MainWindow::on_toolButton_23_clicked()
{
    int stat1,stat2,stat3,stat4,stat5,stat6,stat7;

        activite().stat_1(stat1);
        activite().stat_2(stat2);
        activite().stat_3(stat3);
        activite().stat_4(stat4);
        activite().stat_5(stat5);
        activite().stat_6(stat6);
        activite().stat_7(stat7);
        QPieSeries *series = new QPieSeries();

        series->append("monday",stat1);
        series->append("tuesday",stat2);
        series->append("wednesday",stat3);
        series->append("thursday",stat4);
        series->append("friday",stat5);
        series->append("saturday",stat6);
        series->append("sunday",stat7);
        series->setHoleSize(0.5);
        series->setPieSize(0.8);

        QPieSlice *first = series->slices().at(0);
        QPieSlice *second = series->slices().at(1);
        QPieSlice *third = series->slices().at(2);
        QPieSlice *fourth = series->slices().at(3);
        QPieSlice *fifth = series->slices().at(4);
        QPieSlice *sixth = series->slices().at(5);
        QPieSlice *seventh = series->slices().at(6);
        first->setLabelVisible(true);
        second->setLabelVisible(true);
        third->setLabelVisible(true);
        fourth->setLabelVisible(true);
        fifth->setLabelVisible(true);
        sixth->setLabelVisible(true);
        seventh->setLabelVisible(true);
        first->setBrush(QColor::fromRgb(252,109,109));
        second->setBrush(QColor::fromRgb(91,227,93));
        third->setBrush(QColor::fromRgb(255,182,87));
        fourth->setBrush(QColor::fromRgb(255,150,229));
        fifth->setBrush(QColor::fromRgb(238,242,126));
        sixth->setBrush(Qt::lightGray);
        seventh->setBrush(QColor::fromRgb(119,117,255));
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
        chart->setAnimationOptions(QChart::AllAnimations);

        QChartView * chartview = new QChartView(chart);
        chartview->setParent(ui->frame);
        ui->stackedWidget->setCurrentIndex(8);

}

void MainWindow::on_toolButton_24_clicked()
{
    ui->stackedWidget ->setCurrentIndex(4);
}

void MainWindow::on_toolButton_25_clicked()
{
    ui->stackedWidget ->setCurrentIndex(0);
}

void MainWindow::on_toolButton_17_clicked()
{
    ui->stackedWidget ->setCurrentIndex(0);
}

void MainWindow::on_toolButton_27_clicked()
{
    ui->stackedWidget ->setCurrentIndex(0);
}

void MainWindow::on_toolButton_26_clicked()
{
    ui->stackedWidget ->setCurrentIndex(0);
}

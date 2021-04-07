#include "mainwindow.h"
#include "connexion.h"
#include <QApplication>
#include <QDebug>
#include <QTranslator>
#include <QSplashScreen>
#include <QTimer>
#include <qmovie.h>
#include <QWidget>
#include <QLayout>
#include <QDesktopWidget>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    connexion c;
    bool test=c.createConnexion();
    MainWindow w;

    if (test)
        qDebug() << "connexion successful";
    else
        qDebug() << "connexion failed";

    w.show();

   return app.exec();

}

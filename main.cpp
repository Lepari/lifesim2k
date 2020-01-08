#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setSizePolicy(QSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum));
    w.show();


    return a.exec();
}

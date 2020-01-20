#include "headers/mainwindow.h"

#include <QApplication>

/*!
    \module lifesim2k
    \inmodule lifesim2k
    \title Game of life
    \inmodule lifesim2k
    \brief This is simple Qt application for the Conway's Game of Life

    This game is created for author's programming demonstration purposes.

*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum));
    w.show();
    return a.exec();
}

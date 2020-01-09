#include "mainwindow.h"
#include "definitions.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_central = new CentralWidget();
    setCentralWidget(m_central);
}

MainWindow::~MainWindow()
{
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "centralwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:

private:
    CentralWidget* m_central;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H

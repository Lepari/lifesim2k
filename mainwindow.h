#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QLabel>

#include "lifegrid.h"
#include "lifebutton.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void sizeChanged(int size);
private:
    QWidget* m_central;
    void populateLifeButtons();
    QVBoxLayout *m_top_layout;
    QHBoxLayout *m_button_layout;
    LifeGrid *m_grid_widget;
    QSpacerItem *m_button_pacer;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H

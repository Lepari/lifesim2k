#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QLabel>
#include <QTimer>
#include <QSlider>

#include "lifegrid.h"
#include "lifebutton.h"
#include "life.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void sizeChanged(int size);
    void speedChanged(int refresh_rate);
private:
    QWidget* m_central;
    void populateLifeButtons();
    QVBoxLayout *m_top_layout;
    QHBoxLayout *m_button_layout;
    LifeGrid *m_grid_widget;
    QSpacerItem *m_button_pacer;
    QTimer *m_tick_timer;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H

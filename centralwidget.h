#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>
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

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QWidget *parent = nullptr);
private:
    QVBoxLayout *m_top_layout;
    QHBoxLayout *m_button_layout;
    LifeGrid *m_grid_widget;
    QSpacerItem *m_button_pacer;
    QTimer *m_tick_timer;
    QPushButton *m_start_button;
    QPushButton *m_stop_button;
public slots:
    void sizeChanged(int size);
    void speedChanged(int refresh_rate);
    void start();
    void stop();
    void clear();
    void resizeLife(int size);
signals:

};

#endif // CENTRALWIDGET_H

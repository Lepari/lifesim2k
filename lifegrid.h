#ifndef LIFEGRID_H
#define LIFEGRID_H

#include <QWidget>
#include <QGridLayout>
#include "lifebutton.h"
#include "life.h"


class LifeGrid : public QWidget
{
    Q_OBJECT
public slots:
    void sizeChanged(int value);
    void buttonChanged(bool alive, int x, int y);
    void lifeChanged();
public:
    explicit LifeGrid(QWidget *parent = nullptr);
private:
    int m_size;
    QVector<QVector<LifeButton*> > m_buttons;
    void populateLifeButtons();
    QGridLayout *m_grid_layout;
    Life * m_life;
signals:

};

#endif // LIFEGRID_H

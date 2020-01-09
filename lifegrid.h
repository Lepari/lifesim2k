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
    void changeLifeSize(int value);
    void buttonChanged(bool alive, int x, int y);
    void life_changed();
    void randomize();
    void tick();
public:
    int getSize(){return m_size;};
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

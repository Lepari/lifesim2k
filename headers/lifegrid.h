#ifndef LIFEGRID_H
#define LIFEGRID_H

#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "lifebutton.h"
#include "life.h"


class LifeGrid : public QWidget
{
    Q_OBJECT
public slots:
    void changeLifeSize(int value);
    void buttonChanged(bool alive, int x, int y);
    void lifeChanged();
    void randomize();
    void tick();
public:
    int getSize();
    explicit LifeGrid(QWidget *parent = nullptr);
private:
    int m_size;
    QVector<QVector<LifeButton*> > m_buttons;
    void populateLifeButtons();
    QGridLayout *m_gridLayout = nullptr;
    QHBoxLayout *m_topLayout= nullptr;
    QVBoxLayout *m_middleLayout= nullptr;
    Life * m_life;
signals:

};

#endif // LIFEGRID_H

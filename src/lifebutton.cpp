#include "headers/lifebutton.h"
/*!
    \class LifeButton
    \inherits QToolButton
    \brief LifeButton is a derivate of QToolbutton a dedicated widget for representing single cell in the game of life


*/
LifeButton::LifeButton(int x, int y, QWidget *parent) : QToolButton(parent)
{
    m_x = x;
    m_y = y;
    connect(this, SIGNAL(toggled(bool)), this, SLOT(setAlive(bool)));
    this->setCheckable(true);
    this->setAlive(false);
}

void LifeButton::setAlive(bool status)
{
    bool changed = status != m_alive;
    m_alive = status;
    if(status){
        QPixmap pix = QPixmap(15,15);
        pix.fill(Qt::black);
        this->setIcon(pix);
    }
    else{
        QPixmap pix = QPixmap(15,15);
        pix.fill(Qt::white);
        this->setIcon(pix);
    }
    if (changed){
        emit alive_changed(m_alive, m_x, m_y);
    }
}

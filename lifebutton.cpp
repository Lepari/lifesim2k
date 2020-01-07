#include "lifebutton.h"

LifeButton::LifeButton(QWidget *parent) : QToolButton(parent)
{
    connect(this, SIGNAL(toggled(bool)), this, SLOT(setAlive(bool)));
    this->setCheckable(true);
    this->setAlive(false);
}

void LifeButton::setAlive(bool status)
{
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
}

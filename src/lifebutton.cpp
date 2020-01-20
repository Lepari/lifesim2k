#include "headers/lifebutton.h"
/*!
    \class LifeButton
    \inherits QToolButton
    \brief LifeButton is a dedicated widget for representing single cell in the game of life
    \inmodule lifesim2k

    emits alive_changed(bool alive, x, y) when button changes state.
*/

/*!
 * \brief Constructs a LifeButton wit \a x and \a y specifies the coordinates of which this button represents
 * \a parent points widget
 */
LifeButton::LifeButton(int x, int y, QWidget *parent) : QToolButton(parent)
{
    m_x = x;
    m_y = y;
    connect(this, SIGNAL(toggled(bool)), this, SLOT(setAlive(bool)));
    this->setCheckable(true);
    this->setAlive(false);
}


/*!
 * \brief sets LifeButton alive status to \a status. emits alice_changed() if state changes
 */
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

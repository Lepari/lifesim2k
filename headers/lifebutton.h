#ifndef LIFEBUTTON_H
#define LIFEBUTTON_H

#include <QWidget>
#include <QToolButton>

class LifeButton : public QToolButton
{
    Q_OBJECT
public:
    explicit LifeButton( int x, int y, QWidget *parent = nullptr);
public slots:
    void setAlive(bool status);
private:
    bool m_alive;
    int m_x;
    int m_y;

signals:
    /*!
     * \brief alive_changed
     * \a alive is the state of button after chence
     * \a x and  \a y are the coordinates of this button
     */
    void aliveChanged(bool alive, int x , int y);
};

#endif // LIFEBUTTON_H

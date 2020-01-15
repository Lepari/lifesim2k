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
    void alive_changed(bool alive, int x ,int y);
};

#endif // LIFEBUTTON_H

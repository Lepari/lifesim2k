#ifndef LIFEBUTTON_H
#define LIFEBUTTON_H

#include <QWidget>
#include <QToolButton>

class LifeButton : public QToolButton
{
    Q_OBJECT
public:
    explicit LifeButton(QWidget *parent = nullptr);
public slots:
    void setAlive(bool status);
private:
    bool m_alive;

signals:

};

#endif // LIFEBUTTON_H

#ifndef LIFE_H
#define LIFE_H

#include <QObject>
#include <QVector>

class Life: public QObject
{
    Q_OBJECT
public:
    Life(int size);
    bool getStatus(int x, int y);
    int getsize();
    void setAlive(int x , int y);
    void setDead(int x, int y);
    void randomize();
public slots:
    void tick();
private:
   QVector<QVector<bool>> m_life;
   int m_size;
signals:
   void lifeChanged();
};

#endif // LIFE_H

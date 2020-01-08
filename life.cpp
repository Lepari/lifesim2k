#include "life.h"

Life::Life(int size)
{
    m_size = size;
    QVector<bool> rowVector(m_size, false);
    m_life = QVector<QVector<bool>> (m_size, rowVector);
}

void Life::tick(){

}

void Life::setAlive(int x, int y){
    if (x<m_size && y < m_size && x >= 0 && y >= 0){
        //within table sizes
        m_life[x][y] = true;
    }
}

void Life::setDead(int x, int y){
    if (x<m_size && y < m_size && x >= 0 && y >= 0){
        //within table sizes
        m_life[x][y] = false;
    }
}

bool Life::getStatus(int x, int y){
    //border cases: if x or y points outside of array
    //slide them towards array in steps of m_size
    //This makes the cyclical behaviour of life array
    while(x > m_size-1)
        x = x-m_size;
    while(x < 0)
        x = x+m_size;
    while(y > m_size-1)
        y = y-m_size;
    while(y < 0)
        y = y+m_size;
    return m_life[x][y];
}

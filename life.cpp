#include "life.h"

Life::Life(int size)
{
    m_size = size;
    QVector<bool> rowVector(m_size, false);
    m_life = QVector<QVector<bool>> (m_size, rowVector);
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

void Life::randomize(){
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            m_life[i][j] = rand()%2;
        }
    }
    emit life_changed();
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

void Life::tick(){
    QVector<bool> rowVector(m_size, false);
    QVector<QVector<bool>> next_life = QVector<QVector<bool>> (m_size, rowVector);
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            //count alive neighbours
            int alive_neighbours = 0;
            if(this->getStatus(i-1,j-1))
                alive_neighbours++;
            if(this->getStatus(i-1,j))
                alive_neighbours++;
            if(this->getStatus(i-1,j+1))
                alive_neighbours++;
            if(this->getStatus(i+1,j-1))
                alive_neighbours++;
            if(this->getStatus(i+1,j))
                alive_neighbours++;
            if(this->getStatus(i+1,j+1))
                alive_neighbours++;
            if(this->getStatus(i,j+1))
                alive_neighbours++;
            if(this->getStatus(i,j-1))
                alive_neighbours++;
            //branch acording to current life status
            if(this->getStatus(i,j)){
                //if cell i j is alive
                if(alive_neighbours <= 1 || alive_neighbours >= 4){
                    next_life[i][j] = false;
                }
                else{
                    next_life[i][j] = true;
                }
            }else{
                //if the cell is dead
                if(alive_neighbours==3){
                    next_life[i][j] = true;
                }else{
                    next_life[i][j] = false;
                }
            }
        }
    }
    m_life = next_life;
    emit life_changed();
}

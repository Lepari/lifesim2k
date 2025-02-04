#include "headers/life.h"


/*!
    \class Life
    \brief The Life class represents state of the life and contains methods for modifying it
    \inmodule lifesim2k

    Only NxN size lifes are supported without resizing.
    Borders of grid are treated periodic boundary conditions.
    emits signal life_changed() when state of the life is changed using tick() or randomize().
*/

/*!
 Constructs a Life with square \a size given
 */
Life::Life(int size)
{
    m_size = size;
    QVector<bool> rowVector(m_size, false);
    m_life = QVector<QVector<bool>> (m_size, rowVector);
}

/*!
 Returns the \c size of life grid as integer
*/
int Life::getsize(){
    return m_size;
}

/*!
Sets cell with coordinates \a x, \a y to be alive
*/
void Life::setAlive(int x, int y){
    if (x<m_size && y < m_size && x >= 0 && y >= 0){
        //within table sizes
        m_life[x][y] = true;
    }
}

/*!
Sets cell with coordinates \a x, \a y to be dead
*/
void Life::setDead(int x, int y){
    if (x<m_size && y < m_size && x >= 0 && y >= 0){
        //within table sizes
        m_life[x][y] = false;
    }
}

/*!
Randomly sets all cells in life to be either alive or dead with 50/50 % propability
*/
void Life::randomize(){
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            m_life[i][j] = rand()%2;
        }
    }
    emit lifeChanged();
}

/*!
Returns \c true if cell in coordinates \a x, \a y is alive
If x or y point outside of table they are shifted towards table in steps of life size.
This makes life grid behave in cyclic manner at the borders
*/
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

/*!
Makes the life state progress one step foward
*/
void Life::tick(){
    //Create empty life state
    QVector<bool> rowVector(m_size, false);
    QVector<QVector<bool>> nextLife = QVector<QVector<bool>> (m_size, rowVector);
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            //count alive neighbours
            int alive_neighbours = 0;
            if (this ->getStatus(i-1, j-1))
                alive_neighbours++;
            if (this ->getStatus(i-1, j))
                alive_neighbours++;
            if (this ->getStatus(i-1, j+1))
                alive_neighbours++;
            if (this ->getStatus(i+1, j-1))
                alive_neighbours++;
            if (this ->getStatus(i+1, j))
                alive_neighbours++;
            if (this ->getStatus(i+1, j+1))
                alive_neighbours++;
            if (this ->getStatus(i, j+1))
                alive_neighbours++;
            if (this ->getStatus(i, j-1))
                alive_neighbours++;
            //branch acording to current life status
            if (this ->getStatus(i, j)) {
                //if cell i j is alive
                if (alive_neighbours <= 1 || alive_neighbours >= 4)
                    nextLife[i][j] = false;
                else
                    nextLife[i][j] = true;
            } else {
                //if the cell is dead
                if (alive_neighbours==3){
                    nextLife[i][j] = true;
                } else
                    nextLife[i][j] = false;
            }
        }
    }
    m_life = nextLife;
    emit lifeChanged();
}

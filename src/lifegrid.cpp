#include "headers/lifegrid.h"
#include "definitions.h"
/*!
    \class LifeGrid
    \inherits QWidget
    \brief LifeGrid a collection of libebuttons that represents a state of life and provides means to modify it
    \inmodule lifesim2k
*/


/*!
 Constructs a LifeGrid widget with \a parent
 */
LifeGrid::LifeGrid(QWidget *parent) : QWidget(parent)
{
    m_size = LIFE_GRID_INITIAL_SIZE;
    m_grid_layout = nullptr;
    m_life = new Life(LIFE_GRID_INITIAL_SIZE);
    populateLifeButtons();
    setSizePolicy(QSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum));
    connect(m_life, SIGNAL(life_changed()), this, SLOT(life_changed()));
}

/*!
 Creates layout for the widget and populates it with instances of LifeButton
 */
void LifeGrid::populateLifeButtons()
{
    const QVector<LifeButton *> initVector(m_size, nullptr);
    m_buttons = QVector<QVector<LifeButton *> >(m_size, initVector);

    //remove all widgets from grid before adding new ones
    if(m_grid_layout){
        while(m_grid_layout->count() > 0){
            delete m_grid_layout->itemAt(0)->widget();
        }
    }
    if(m_top_layout) delete m_top_layout;

    //Create layout
    m_top_layout = new QHBoxLayout;
    m_middle_layout = new QVBoxLayout;
    m_grid_layout = new QGridLayout;
    m_grid_layout->setSpacing(0);
    m_top_layout->addStretch();
    m_top_layout->addItem(m_middle_layout);
    m_top_layout->addStretch();
    m_middle_layout->addStretch();
    m_middle_layout->addItem(m_grid_layout);
    m_middle_layout->addStretch();

    //Create buttons and populate layout
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            LifeButton *button = new LifeButton(i, j, this);
            connect(button, SIGNAL(alive_changed(bool,int,int)), this, SLOT(buttonChanged(bool,int,int)));
            button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            button->setEnabled(true);
            m_buttons[i][j] = button;
            m_grid_layout->addWidget(button, i, j );
        }
    }
    setLayout(m_top_layout);
}

/*!
 Resizes Grid to size of \a value
 */
void LifeGrid::changeLifeSize(int value){
    m_size = value;
    populateLifeButtons();
    delete m_life;
    m_life = new Life(m_size);
    connect(m_life, SIGNAL(life_changed()), this, SLOT(life_changed()));
    adjustSize();
}

/*!
Slot fot LifeButtons to connect
\a alive is the new state of button
\a x and \a y define button coordinates
 */
void LifeGrid::buttonChanged(bool alive, int x, int y){
    if(alive){
        m_life->setAlive(x,y);
    }else{
        m_life->setDead(x,y);
    }
}

/*!
 Updates ui LifeButtons to correspond Life status
 */
void LifeGrid::life_changed(){
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            bool lifestatus_at = m_life->getStatus(i,j);
            LifeButton* button = m_buttons[i][j];
            if(lifestatus_at != button->isChecked()){
                button->setChecked(lifestatus_at);
            }
        }
    }
}

/*!
 Randomizes life grid status
 */
void LifeGrid::randomize(){
    m_life->randomize();
}

/*!
  Advances the life by one step.
*/
void LifeGrid::tick(){
    m_life->tick();
}


/*!
 * \brief LifeGrid::getSize
 * Returns \c size of Life
 */
int LifeGrid::getSize()
{
    return m_size;
}

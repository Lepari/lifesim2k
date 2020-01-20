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
    m_gridLayout = nullptr;
    m_life = new Life(LIFE_GRID_INITIAL_SIZE);
    populateLifeButtons();
    setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum));
    connect(m_life, SIGNAL(lifeChanged()), this, SLOT(lifeChanged()));
}

/*!
 Creates layout for the widget and populates it with instances of LifeButton
 */
void LifeGrid::populateLifeButtons()
{
    const QVector<LifeButton *> initVector(m_size, nullptr);
    m_buttons = QVector<QVector<LifeButton *> >(m_size, initVector);

    //remove all widgets from grid before adding new ones
    if(m_gridLayout){
        while(m_gridLayout->count() > 0){
            delete m_gridLayout->itemAt(0)->widget();
        }
    }
    if(m_topLayout) delete m_topLayout;

    //Create layout
    m_topLayout = new QHBoxLayout;
    m_middleLayout = new QVBoxLayout;
    m_gridLayout = new QGridLayout;
    m_gridLayout->setSpacing(0);
    m_topLayout->addStretch();
    m_topLayout->addItem(m_middleLayout);
    m_topLayout->addStretch();
    m_middleLayout->addStretch();
    m_middleLayout->addItem(m_gridLayout);
    m_middleLayout->addStretch();

    //Create buttons and populate layout
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            LifeButton *button = new LifeButton(i, j, this);
            connect(button, SIGNAL(alive_changed(bool, int, int)), this, SLOT(buttonChanged(bool, int, int)));
            button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            button->setEnabled(true);
            m_buttons[i][j] = button;
            m_gridLayout->addWidget(button, i, j );
        }
    }
    setLayout(m_topLayout);
}

/*!
 Resizes Grid to size of \a value
 */
void LifeGrid::changeLifeSize(int value){
    m_size = value;
    populateLifeButtons();
    delete m_life;
    m_life = new Life(m_size);
    connect(m_life, SIGNAL(lifeChanged()), this, SLOT(lifeChanged()));
    adjustSize();
}

/*!
Slot fot LifeButtons to connect
\a alive is the new state of button
\a x and \a y define button coordinates
 */
void LifeGrid::buttonChanged(bool alive, int x, int y){
    if(alive){
        m_life->setAlive(x, y);
    }else{
        m_life->setDead(x, y);
    }
}

/*!
 Updates ui LifeButtons to correspond Life status
 */
void LifeGrid::lifeChanged(){
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            bool lifestatusAt = m_life->getStatus(i, j);
            LifeButton* button = m_buttons[i][j];
            if(lifestatusAt != button->isChecked()){
                button->setChecked(lifestatusAt);
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

#include "lifegrid.h"
#include "definitions.h"

LifeGrid::LifeGrid(QWidget *parent) : QWidget(parent)
{
    m_size = LIFE_GRID_INITIAL_SIZE;
    m_grid_layout = nullptr;
    m_life = new Life(LIFE_GRID_INITIAL_SIZE);
    populateLifeButtons();
    setSizePolicy(QSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum));
    connect(m_life, SIGNAL(life_changed()), this, SLOT(life_changed()));
}

void LifeGrid::populateLifeButtons()
{
    const QVector<LifeButton *> initVector(m_size, nullptr);
    m_buttons = QVector<QVector<LifeButton *> >(m_size, initVector);

    //remove all widgets from grid before adding new ones
    if(m_grid_layout){
        while(m_grid_layout->count() > 0){
            delete m_grid_layout->itemAt(0)->widget();
        }
        delete m_grid_layout;
    }
    m_grid_layout = new QGridLayout(this);
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
    m_grid_layout->setSpacing(0);
    setLayout(m_grid_layout);
}

void LifeGrid::sizeChanged(int value){
    m_size = value;
    populateLifeButtons();
}

void LifeGrid::buttonChanged(bool alive, int x, int y){
    if(alive){
        m_life->setAlive(x,y);
    }else{
        m_life->setDead(x,y);
    }
}

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

void LifeGrid::randomize(){
    m_life->randomize();
}

void LifeGrid::tick(){
    m_life->tick();
}

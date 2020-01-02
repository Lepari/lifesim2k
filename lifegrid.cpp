#include "lifegrid.h"

LifeGrid::LifeGrid(QWidget *parent) : QWidget(parent)
{
    m_size = 9;
    m_grid_layout = nullptr;
    populateLifeButtons();
    setSizePolicy(QSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum));
}

void LifeGrid::populateLifeButtons()
{
    const QVector<QToolButton *> initVector(m_size, nullptr);
    m_buttons = QVector<QVector<QToolButton *> >(m_size, initVector);

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
            QToolButton *button = new QToolButton(this);
            button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            m_grid_layout->addWidget(button, i, j );
            m_buttons[i][j] = button;
            m_buttons[i][j]->setText("a");
            m_buttons[i][j]->setEnabled(true);
        }
    }
    setLayout(m_grid_layout);
}

void LifeGrid::sizeChanged(int value){
    m_size = value;
    populateLifeButtons();
}

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_size = 9;
    m_central = new QWidget(0,0);
    m_top_layout = new QVBoxLayout(this);
    m_grid_layout = new QGridLayout(this);
    m_button_layout = new QHBoxLayout(this);
    m_top_layout->addItem(m_grid_layout);
    m_top_layout->addItem(m_button_layout);

    //Lower row control buttons setup
    QPushButton *tick_button = new QPushButton("Tick",this);
    QPushButton *start_stop_button = new QPushButton("Start");
    QLabel *size_label = new QLabel("size", this);
    QSpinBox *size_spinbox = new QSpinBox(this);



    size_spinbox->setValue(9);
    size_spinbox->setMinimum(1);
    size_spinbox->setMaximum(200);
    m_button_layout->addWidget(tick_button);
    m_button_layout->addWidget(start_stop_button);
    m_button_layout->addWidget(size_label);
    m_button_layout->addWidget(size_spinbox);

    populateLifeButtons();
    setCentralWidget(m_central);


    m_central->setLayout(m_top_layout);
    connect(size_spinbox, SIGNAL(valueChanged(int)), this, SLOT(sizeChanged(int)));
}

MainWindow::~MainWindow()
{
}

void MainWindow::populateLifeButtons()
{
    const QVector<QToolButton *> initVector(m_size, nullptr);
    m_buttons = QVector<QVector<QToolButton *> >(m_size, initVector);

//TODO remove all widgets from grid before adding new ones

    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            QToolButton *button = new QToolButton(this);
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            m_grid_layout->addWidget(button, i, j );
            m_buttons[i][j] = button;
            m_buttons[i][j]->setText("a");
            m_buttons[i][j]->setEnabled(true);
        }
    }


}

void MainWindow::sizeChanged(int value)
{
    m_size = value;
    populateLifeButtons();
    m_central->repaint();

}

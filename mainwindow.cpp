#include "mainwindow.h"
#include "definitions.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_central = new QWidget(0,0);
    m_top_layout = new QVBoxLayout(this);
    m_button_layout = new QHBoxLayout(this);
    m_grid_widget = new LifeGrid();
    m_tick_timer = new QTimer();
    m_tick_timer->setInterval(500);
    m_top_layout->addItem(m_button_layout);
    m_top_layout->addWidget(m_grid_widget);

    //Lower row control buttons setup
    QPushButton *random_button = new QPushButton("Randomize");
    QPushButton *tick_button = new QPushButton("Next State",this);
    QPushButton *start_button = new QPushButton("Start");
    QPushButton *stop_button = new QPushButton("Stop");
    QLabel *size_label = new QLabel("size", this);
    QSpinBox *size_spinbox = new QSpinBox(this);

    size_spinbox->setValue(LIFE_GRID_INITIAL_SIZE);
    size_spinbox->setMinimum(LIFE_GRID_MIN_SIZE);
    size_spinbox->setMaximum(LIFE_GRID_MAX_SIZE);
    m_button_layout->addWidget(size_label);
    m_button_layout->addWidget(size_spinbox);
    m_button_layout->addStretch();
    m_button_layout->addWidget(random_button);
    m_button_layout->addWidget(tick_button);
    m_button_layout->addWidget(start_button);
    m_button_layout->addWidget(stop_button);
    populateLifeButtons();
    setCentralWidget(m_central);
    m_central->setLayout(m_top_layout);
    setSizePolicy(QSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum));
    connect(start_button, SIGNAL(pressed()), m_tick_timer, SLOT(start()));
    connect(stop_button, SIGNAL(pressed()), m_tick_timer, SLOT(stop()));
    connect(m_tick_timer, SIGNAL(timeout()), m_grid_widget, SLOT(tick()));
    connect(size_spinbox, SIGNAL(valueChanged(int)), this, SLOT(sizeChanged(int)));
    connect(random_button, SIGNAL(pressed()), m_grid_widget, SLOT(randomize()));
    connect(tick_button, SIGNAL(pressed()), m_grid_widget, SLOT(tick()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::sizeChanged(int size){
    m_grid_widget->sizeChanged(size);
    adjustSize();
}

void MainWindow::populateLifeButtons()
{


}


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
    m_tick_timer->setInterval(333);
    m_top_layout->addItem(m_button_layout);
    m_top_layout->addWidget(m_grid_widget);

    //Upper row control buttons setup
    QSlider *speed_slider = new QSlider(Qt::Horizontal);
    speed_slider->setMinimum(1);
    speed_slider->setMaximum(25);
    speed_slider->setValue(3);
    speed_slider->setTickPosition(QSlider::TicksBelow);
    speed_slider->setTickInterval(1);
    speed_slider->setMinimumSize(QSize(100,10));
    QPushButton *random_button = new QPushButton("Randomize");
    QPushButton *tick_button = new QPushButton("Next State",this);
    QPushButton *clear_button = new QPushButton("Clear",this);
    m_start_button = new QPushButton("Start");
    m_stop_button = new QPushButton("Stop");
    m_stop_button->setEnabled(false);
    QLabel *size_label = new QLabel("size", this);
    QLabel *speed_label = new QLabel("speed(Hz)", this);
    QSpinBox *size_spinbox = new QSpinBox(this);

    size_spinbox->setValue(LIFE_GRID_INITIAL_SIZE);
    size_spinbox->setMinimum(LIFE_GRID_MIN_SIZE);
    size_spinbox->setMaximum(LIFE_GRID_MAX_SIZE);
    m_button_layout->addWidget(size_label);
    m_button_layout->addWidget(size_spinbox);
    m_button_layout->addStretch();
    m_button_layout->addWidget(random_button);
    m_button_layout->addWidget(clear_button);
    m_button_layout->addWidget(tick_button);
    m_button_layout->addSpacing(5);
    m_button_layout->addWidget(speed_label);
    m_button_layout->addWidget(speed_slider);
    m_button_layout->addSpacing(5);
    m_button_layout->addWidget(m_start_button);
    m_button_layout->addWidget(m_stop_button);
    setCentralWidget(m_central);
    m_central->setLayout(m_top_layout);
    setSizePolicy(QSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum));
    connect(m_start_button, SIGNAL(pressed()), this, SLOT(start()));
    connect(m_stop_button, SIGNAL(pressed()), this, SLOT(stop()));
    connect(m_tick_timer, SIGNAL(timeout()), m_grid_widget, SLOT(tick()));
    connect(size_spinbox, SIGNAL(valueChanged(int)), this, SLOT(sizeChanged(int)));
    connect(random_button, SIGNAL(pressed()), m_grid_widget, SLOT(randomize()));
    connect(tick_button, SIGNAL(pressed()), m_grid_widget, SLOT(tick()));
    connect(speed_slider, SIGNAL(sliderMoved(int)), this, SLOT(speedChanged(int)));
    connect(size_spinbox, SIGNAL(valueChanged(int)), this, SLOT(stop()));
    connect(clear_button, SIGNAL(pressed()), this, SLOT(clear()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::sizeChanged(int size){
    m_grid_widget->changeLifeSize(size);
    adjustSize();
}

void MainWindow::speedChanged(int refresh_rate){
    int mills = 1000/refresh_rate;
    m_tick_timer->setInterval(mills);
}

void MainWindow::stop(){
    m_tick_timer->stop();
    m_stop_button->setEnabled(false);
    m_start_button->setEnabled(true);
}

void MainWindow::start(){
    m_tick_timer->start();
    m_start_button->setEnabled(false);
    m_stop_button->setEnabled(true);
}

void MainWindow::resizeLife(int size){
    m_grid_widget->changeLifeSize(size);
}

void MainWindow::clear(){
    m_grid_widget->changeLifeSize(m_grid_widget->getSize());
}

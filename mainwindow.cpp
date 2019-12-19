#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_size = 9;
    const QVector<QToolButton *> initVector(m_size, nullptr);
    m_buttons = QVector<QVector<QToolButton *> >(m_size, initVector);
    QGridLayout *grid_layout = new QGridLayout(this);
    QVBoxLayout *top_layout = new QVBoxLayout(this);
    QHBoxLayout *button_layout = new QHBoxLayout(this);
    top_layout->addItem(grid_layout);
    top_layout->addItem(button_layout);

    //Lower row control buttons setup
    QPushButton *tick_button = new QPushButton("Tick",this);
    QPushButton *start_stop_button = new QPushButton("Start");
    QLabel *size_label = new QLabel("size", this);
    QSpinBox *size_spinbox = new QSpinBox(this);
    size_spinbox->setValue(9);
    size_spinbox->setMinimum(1);
    size_spinbox->setMaximum(200);
    button_layout->addWidget(tick_button);
    button_layout->addWidget(start_stop_button);
    button_layout->addWidget(size_label);
    button_layout->addWidget(size_spinbox);


    //Populate the grid of buttons that represent life
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            QToolButton *button = new QToolButton(this);
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            grid_layout->addWidget(button, i, j );
            m_buttons[i][j] = button;
            m_buttons[i][j]->setText("a");
            m_buttons[i][j]->setEnabled(true);
        }
    }

    QWidget *central = new QWidget(0,0);
    central->setLayout(top_layout);
    setCentralWidget(central);
}

MainWindow::~MainWindow()
{
}

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_size = 9;
    const QVector<QToolButton *> initVector(m_size, nullptr);
    m_buttons = QVector<QVector<QToolButton *> >(m_size, initVector);
    QGridLayout *layout = new QGridLayout(this);

    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            QToolButton *button = new QToolButton(this);
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            layout->addWidget(button, i, j );
            m_buttons[i][j] = button;
            m_buttons[i][j]->setText("a");
            m_buttons[i][j]->setEnabled(true);
        }
    }
    QWidget *central = new QWidget(0,0);
    central->setLayout(layout);
    setCentralWidget(central);
}

MainWindow::~MainWindow()
{
}


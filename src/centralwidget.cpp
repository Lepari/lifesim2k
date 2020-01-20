#include "headers/centralwidget.h"
#include "definitions.h"


/*!
    \class CentralWidget
    \brief Central Widget of lifesim2k project main window.
    \inmodule lifesim2k

    Contains all widgets and top level functionality of this software.
*/

/*!
 * \brief Constructs CentralWidget with parent widget \a parent
 */
CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent)
{
    m_gridWidget = new LifeGrid(this);
    m_tickTimer = new QTimer();
    m_tickTimer->setInterval(333);
    //Upper row control buttons setup
    QSlider *speedSlider = new QSlider(Qt::Horizontal);
    speedSlider->setMinimum(1);
    speedSlider->setMaximum(25);
    speedSlider->setValue(3);
    speedSlider->setTickPosition(QSlider::TicksBelow);
    speedSlider->setTickInterval(1);
    speedSlider->setMinimumSize(QSize(100, 10));

    QPushButton *randomButton = new QPushButton("Randomize");
    QPushButton *tickButton = new QPushButton("Next State", this);
    QPushButton *clearButton = new QPushButton("Clear", this);
    m_startButton = new QPushButton("Start");
    m_stopButton = new QPushButton("Stop");
    m_stopButton->setEnabled(false);
    QLabel *sizeLabel = new QLabel("Size", this);
    QLabel *speedLabel = new QLabel("Speed(Hz)", this);
    QSpinBox *sizeSpinbox = new QSpinBox(this);
    sizeSpinbox->setValue(LIFE_GRID_INITIAL_SIZE);
    sizeSpinbox->setMinimum(LIFE_GRID_MIN_SIZE);
    sizeSpinbox->setMaximum(LIFE_GRID_MAX_SIZE);

    //Create layouts
    m_buttonLayout = new QHBoxLayout();
    m_buttonLayout->addWidget(sizeLabel);
    m_buttonLayout->addWidget(sizeSpinbox);
    m_buttonLayout->addStretch();
    m_buttonLayout->addWidget(randomButton);
    m_buttonLayout->addWidget(clearButton);
    m_buttonLayout->addWidget(tickButton);
    m_buttonLayout->addSpacing(5);
    m_buttonLayout->addWidget(speedLabel);
    m_buttonLayout->addWidget(speedSlider);
    m_buttonLayout->addSpacing(5);
    m_buttonLayout->addWidget(m_startButton);
    m_buttonLayout->addWidget(m_stopButton);

    m_topLayout = new QVBoxLayout();
    m_topLayout->addItem(m_buttonLayout);
    m_topLayout->addWidget(m_gridWidget);

    setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum));
    connect(m_startButton, SIGNAL(pressed()), this, SLOT(start()));
    connect(m_stopButton, SIGNAL(pressed()), this, SLOT(stop()));
    connect(m_tickTimer, SIGNAL(timeout()), m_gridWidget, SLOT(tick()));
    connect(sizeSpinbox, SIGNAL(valueChanged(int)), this, SLOT(sizeChanged(int)));
    connect(randomButton, SIGNAL(pressed()), m_gridWidget, SLOT(randomize()));
    connect(tickButton, SIGNAL(pressed()), m_gridWidget, SLOT(tick()));
    connect(speedSlider, SIGNAL(sliderMoved(int)), this, SLOT(speedChanged(int)));
    connect(sizeSpinbox, SIGNAL(valueChanged(int)), this, SLOT(stop()));
    connect(clearButton, SIGNAL(pressed()), this, SLOT(clear()));

    this ->setLayout(m_topLayout);
    this ->show();

}

/*!
 * \brief Slot which resizes the life size and updates widget to
 *  \a size
 */
void CentralWidget::sizeChanged(int size) {
    m_gridWidget->changeLifeSize(size);
    adjustSize();
}

/*!
 * \brief Changes the refresh speed of game of life as
 * \a refresh_rate in herz
 */
void CentralWidget::speedChanged(int refresh_rate) {
    int mills = 1000/refresh_rate;
    m_tickTimer->setInterval(mills);
}

/*!
 * \brief Stops the game of life from progressing
 */
void CentralWidget::stop() {
    m_tickTimer->stop();
    m_stopButton->setEnabled(false);
    m_startButton->setEnabled(true);
}
/*!
 * \brief Starts the game of life from progressing at speed set by speedChanged
 */
void CentralWidget::start() {
    m_tickTimer->start();
    m_startButton->setEnabled(false);
    m_stopButton->setEnabled(true);
}

/*!
 * Resizes the life to
 * \a size
 */
void CentralWidget::resizeLife(int size) {
    m_gridWidget->changeLifeSize(size);
}

/*!
 * \brief Sets all life cells to "dead" state
 */
void CentralWidget::clear() {
    m_gridWidget->changeLifeSize(m_gridWidget->getSize());
}

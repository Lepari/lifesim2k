#ifndef LIFEGRID_H
#define LIFEGRID_H

#include <QWidget>
#include <QGridLayout>
#include <QToolButton>


class LifeGrid : public QWidget
{
    Q_OBJECT
public slots:
    void sizeChanged(int value);
public:
    explicit LifeGrid(QWidget *parent = nullptr);
private:
    int m_size;
    QVector<QVector<QToolButton *> > m_buttons;
    void populateLifeButtons();
    QGridLayout *m_grid_layout;
signals:

};

#endif // LIFEGRID_H

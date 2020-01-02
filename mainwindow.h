#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QLabel>


class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void sizeChanged(int value);

private:
    QVector<QVector<QToolButton *> > m_buttons;
    QWidget* m_central;
    int m_size;
    void populateLifeButtons();
    QGridLayout *m_grid_layout;
    QVBoxLayout *m_top_layout;
    QHBoxLayout *m_button_layout;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H

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
private:
    QVector<QVector<QToolButton *> > m_buttons;
    int m_size;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H

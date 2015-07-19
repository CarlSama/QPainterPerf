#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QScrollBar>
#include <stdio.h>

namespace Ui{
    class MainWindow;
    class TestWidget;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setBackMain();
public slots:
    void runButtonPressed();
    void resetButtonPressed();

private:
    Ui::MainWindow *ui;
    void runTest(int testnum);
};

#endif // MAINWINDOW_H

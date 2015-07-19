#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <stdio.h>
#include<sys/time.h>
#include"mainwindow.h"

class TestWidget : public QWidget
{
    Q_OBJECT

public:
    typedef enum {        TEST_POINTS,        TEST_LINES,        TEST_CONVEXPOLYGON,        TEST_ELLIPSE,
        TEST_IMAGE,        TEST_PATH,        TEST_PICTURE,        TEST_PIE,
        TEST_PIXMAP,        TEST_ARC,        TEST_CHORD,        TEST_POLYGON,
        TEST_POLYLINE,        TEST_RECT,        TEST_ROUNDEDRECT,        TEST_TEXT,
        TEST_STATICTEXT,        TEST_TILEDPIXMAP,        TEST_DRAWGLYPHRUN,        TEST_FILLPATH,
        TEST_ERASE,        TEST_FILLRECT,        TEST_IDLE } TestType;

    TestType type;
    explicit TestWidget(QWidget *parent = 0);
    ~TestWidget();

    void set(TestType newtype,int lo);

    double getDuration(){
        return duration;
    }

protected:
    void paintEvent(QPaintEvent *);

private:
    struct timeval tvs,tve;
    double duration;

    int loops;
    double waitTime;

    Ui::TestWidget *ui;
};

#endif // TESTWIDGET_H

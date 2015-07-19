#include "testwidget.h"
#include "ui_testwidget.h"
#include<QtGui/QtGui>
#include<QDebug>
#include<QRegion>
//#include<QRawFont>
//#include<QGlyphRun>
#include<sys/time.h>

#define MAX_RANDOM_SIZ 1000.0

TestWidget::TestWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestWidget)
{
    ui->setupUi(this);
    type = TEST_IDLE;
    this->setAttribute(Qt::WA_NoBackground);
    this->setAttribute(Qt::WA_NoSystemBackground);
}

TestWidget::~TestWidget()
{
    delete ui;
}

void TestWidget::paintEvent(QPaintEvent *) {
    QPainter painter;
    painter.begin(this);
    QColor color(QColor::colorNames().at(qrand() % QColor::colorNames().count()));
    painter.setPen(color);
    painter.setBrush(QBrush(color));
    painter.setFont(QFont("Arial",16,QFont::Bold));
    painter.setRenderHint(QPainter::Antialiasing);

    this->duration = 0.0;

    switch(type) {
        case TEST_POINTS:
            //Points
            gettimeofday(&tvs,NULL);
            for(int i=0; i<loops; i++)
            {
                int s1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int e1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);

                painter.setPen((int)(random()*20));
                painter.drawPoint(s1, e1);
            }
            gettimeofday(&tve,NULL);
            break;

        case TEST_LINES:
            //Line
            gettimeofday(&tvs,NULL);
            for(int i=0; i<loops; i++)
            {
                int s1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int e1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int s2 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int e2 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);

                painter.setPen((int)(random()*20));
                painter.drawLine(s1, e1, s2, e2);
            }
            gettimeofday(&tve,NULL);
            break;

        case TEST_CONVEXPOLYGON:
            //ConvexPolygon
            gettimeofday(&tvs,NULL);
            for(int i=0; i<loops / 10; i++)
            {
                double c1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c2 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c3 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c4 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c5 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c6 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c7 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c8 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);

                painter.setPen((int)(random()*20));
                const QPointF points[4] = {
                    QPointF(c1,c8),
                    QPointF(c2,c3),
                    QPointF(c4,c5),
                    QPointF(c6,c7)
                };
                painter.drawConvexPolygon(points,4);
            }
            gettimeofday(&tve,NULL);
            break;

        case TEST_ELLIPSE:
            //Ellipse
            gettimeofday(&tvs,NULL);
            for(int i=0; i<loops; i++)
            {
                double c1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c2 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c3 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c4 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);

                painter.setPen((int)(random()*20));
                QRectF rectangle(c1,c2,c3,c4);
                painter.drawEllipse(rectangle);
            }
            gettimeofday(&tve,NULL);
            //qDebug()<<"The Ellipse cost : "<<duration<<endl;
            break;

        case TEST_IMAGE:
            //Image
            gettimeofday(&tvs,NULL);
            for(int i=0; i<loops; i++)
            {
                double c1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c2 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c3 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c4 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);

                double cc1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double cc2 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double cc3 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double cc4 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                QRectF target(c1,c2,c3,c4);
                QRectF source(cc1,cc2,cc3,cc4);
                QImage image("./image-for-test.png");
                painter.setPen((int)(random()*20));
                painter.drawImage(target,image,source);
            }
            gettimeofday(&tve,NULL);
            //qDebug()<<"The Image cost : "<<duration<<endl;
            break;

       case TEST_PATH:
            //Path
            gettimeofday(&tvs,NULL);
            for(int i=0; i<loops; i++)
            {
                int c1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int c2 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int c3 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int c4 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);

                QPainterPath path;
                path.moveTo(c1,c2);
                path.lineTo(c1,c3);
                path.cubicTo(c2,0,c4,c4,c2,c2);
                painter.drawPath(path);
            }
            gettimeofday(&tve,NULL);
            //qDebug()<<"The Path cost : "<<duration<<endl;
            break;

      case TEST_PICTURE:
            //Picture
            gettimeofday(&tvs,NULL);
            for(int i=0; i<loops; i++)
            {
                double x1 = (double)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double x2 = (double)(MAX_RANDOM_SIZ*random()/RAND_MAX);

                painter.setPen((int)(random()*20));
                QPicture picture;
                QPointF point(x1,x2);

                painter.drawPicture(point,picture);
            }
            gettimeofday(&tve,NULL);
           // qDebug()<<"The Picture cost : "<<duration<<endl;
            break;

    case TEST_PIE:
            //Pie
            gettimeofday(&tvs,NULL);
            for(int i=0; i<loops; i++)
            {
                double x1 = (double)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double x2 = (double)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double x3 = (double)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double x4 = (double)(MAX_RANDOM_SIZ*random()/RAND_MAX);

                QRectF rectangle(x1,x2,x3,x4);
                int start = (int)(360 * random()/RAND_MAX);
                int end = (int)(360 * random()/RAND_MAX);
                painter.setPen((int)(random()*20));
                painter.drawPie(rectangle,start,end);
            }
            gettimeofday(&tve,NULL);
           // qDebug()<<"The Pie cost : "<<duration<<endl;
            break;

     case TEST_PIXMAP:
            //Pixmap
            gettimeofday(&tvs,NULL);
            for(int i=0; i<loops; i++)
            {
                double x1 = (double)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double x2 = (double)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double x3 = (double)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double x4 = (double)(MAX_RANDOM_SIZ*random()/RAND_MAX);

                QRectF target(x1,x2,x3,x4);
                QRectF source(0,0,70,40);
                QPixmap pixmap("image-for-test.png");
                painter.drawPixmap(target,pixmap,source);
            }
            gettimeofday(&tve,NULL);
          //  qDebug()<<"The Pixmap cost : "<<duration<<endl;
            break;

    case TEST_ARC:
            //Arc
            gettimeofday(&tvs,NULL);
            for(int i=0;i<loops;i++){
                int x1 = (double)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int y1 = (double)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int x2 = (double)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int y2 = (double)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int start = (int)(360*random()/RAND_MAX);
                int end = (int)(360*random()/RAND_MAX);

                QRectF rectangle(x1,y1,x2,y2);
                int startAngle = start * 16;
                int spanAngle = end * 16;
                painter.drawArc(rectangle,startAngle,spanAngle);
            }
            gettimeofday(&tve,NULL);
         //   qDebug()<<"The drawArc cost : "<<duration<<endl;
             break;

    case TEST_CHORD:
            //Chord
            gettimeofday(&tvs,NULL);
            for(int i=0;i<loops;i++){
                int x1 = (double)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int y1 = (double)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int x2 = (double)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int y2 = (double)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int start = (int)(360*random()/RAND_MAX);
                int end = (int)(360*random()/RAND_MAX);

                QRectF rectangle(x1,y1,x2,y2);
                int startAngle = start * 16;
                int spanAngle = end * 16;
                painter.drawChord(rectangle,startAngle,spanAngle);
            }
            gettimeofday(&tve,NULL);
            //qDebug()<<"The drawChord cost : "<<duration<<endl;
            break;


    case TEST_POLYGON:
            //Polygon
            gettimeofday(&tvs,NULL);
            for(int i=0; i<loops / 10; i++)
            {
                double c1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c2 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c3 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c4 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c5 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c6 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c7 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);

                painter.setPen((int)(random()*20));
                const QPointF points[4] = {
                    QPointF(c1,c2),
                    QPointF(c2,c3),
                    QPointF(c4,c5),
                    QPointF(c6,c7)
                };
                painter.drawPolygon(points,4);
            }
            gettimeofday(&tve,NULL);
            //qDebug()<<"The Polygon cost : "<<duration<<endl;
            break;

    case TEST_POLYLINE:
            //Polyline
            gettimeofday(&tvs,NULL);
            for(int i=0; i<loops; i++)
            {
                double c1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c2 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c3 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c4 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c5 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                double c6 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);

                painter.setPen((int)(random()*20));
                const QPointF points[3] = {
                    QPointF(c1,c2),
                    QPointF(c3,c4),
                    QPointF(c5,c6)
                };
                painter.drawPolyline(points,3);
            }
            gettimeofday(&tve,NULL);
//            qDebug()<<"The Polyline cost : "<<duration<<endl;
            break;

        case TEST_RECT:
            //Rect
            gettimeofday(&tvs,NULL);
            for(int i=0; i<loops; i++)
            {
                int s1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int e1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int s2 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int e2 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);

                painter.setPen((int)(random()*20));
                QRectF rectangle(s1,e1,s2,e2);
                painter.drawRect(rectangle);
            }
            gettimeofday(&tve,NULL);
  //          qDebug()<<"The Rect cost : "<<duration<<endl;
            break;

        case TEST_ROUNDEDRECT:
            //RoundedRect
            gettimeofday(&tvs,NULL);
            for(int i=0; i<loops; i++)
            {
                int s1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int e1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int s2 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int e2 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);

                painter.setPen((int)(random()*20));
                QRectF rectangle(s1,e1,s2,e2);
                painter.drawRoundedRect(rectangle,20.0,15.0);
            }
            gettimeofday(&tve,NULL);
            //qDebug()<<"The RoundedRect cost : "<<duration<<endl;
            break;

        case TEST_TEXT:
            //Text
            gettimeofday(&tvs,NULL);
            for(int i=0; i<loops; i++)
            {
                int s1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int e1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int s2 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int e2 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);

                painter.setPen((int)(random()*20));
                QRectF rectangle(s1,e1,s2,e2);
                painter.drawText(rectangle,Qt::AlignCenter,tr("CarlSama !"));
            }
            gettimeofday(&tve,NULL);
            //qDebug()<<"The drawText cost : "<<duration<<endl;
            break;

        case TEST_STATICTEXT:
            //StaticText
            gettimeofday(&tvs,NULL);
            for(int i=0; i<loops; i++)
            {
                int x = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int y = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);

                painter.setPen((int)(random()*20));
                painter.drawStaticText(x, y, QStaticText("CarlSama !"));
            }
            gettimeofday(&tve,NULL);
            //qDebug()<<"The drawStaticText cost : "<<duration<<endl;
            break;

        case TEST_TILEDPIXMAP:
            //TiledPixmap
            gettimeofday(&tvs,NULL);
            for(int i=0; i<loops; i++)
            {
                int s1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int e1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int s2 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int e2 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int w1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int w2 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);

                painter.setPen((int)(random()*20));
                QRectF rectangle(s1,e1,s2,e2);
                QPixmap pixmap("image-for-test.png");
                QPointF position(w1,w2);
                painter.drawTiledPixmap(rectangle, pixmap, position);
            }
            gettimeofday(&tve,NULL);
            //qDebug()<<"The TiledPixmap cost : "<<duration<<endl;
            break;

        case TEST_DRAWGLYPHRUN:
            //drawGlyphRun
            gettimeofday(&tvs,NULL);
            for(int i=0; i<loops; i++)
            {
                double x = (MAX_RANDOM_SIZ*random()/RAND_MAX);
                int w1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int w2 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);

                QString str = "wby";
                QRawFont qrawfont(str,x);
                QGlyphRun qp;
                qp.setRawFont(qrawfont);
                QPointF position(w1,w2);
                painter.drawGlyphRun( position,qp);
            }
            gettimeofday(&tve,NULL);
            //qDebug()<<"The GlyphRun cost : "<<duration<<endl;
            break;

        case TEST_FILLPATH:
            //fillPath
            gettimeofday(&tvs,NULL);
            for(int i=0; i<loops; i++)
            {
                int c1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int c2 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int c3 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int c4 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);

                QPainterPath path;
                path.moveTo(c1,c2);
                path.lineTo(c1,c3);
                path.cubicTo(c2,0,c4,c4,c2,c2);

                painter.fillPath(path, QBrush((int)(random()*20)));
            }
            gettimeofday(&tve,NULL);
            //qDebug()<<"The fillPath cost : "<<duration<<endl;
            break;

       case TEST_ERASE:
            //erase
            gettimeofday(&tvs,NULL);
            for(int i=0; i<loops; i++)
            {
                int c1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int c2 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int c3 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int c4 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);

                QRect r(c1, c2, c3, c4);
                painter.eraseRect(r);
            }
            gettimeofday(&tve,NULL);
            break;

        case TEST_FILLRECT:
            //fillRect
            gettimeofday(&tvs,NULL);
            for(int i=0; i<loops; i++)
            {
                int c1 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int c2 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int c3 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);
                int c4 = (int)(MAX_RANDOM_SIZ*random()/RAND_MAX);

                QRect r(c1, c2, c3, c4);
                painter.fillRect(r, QBrush((int)(random()*20)));
            }
            gettimeofday(&tve,NULL);
            break;

        default :
            gettimeofday(&tvs,NULL);
            gettimeofday(&tve,NULL);
            break;
    }
    this->duration = tve.tv_sec - tvs.tv_sec + (tve.tv_usec - tvs.tv_usec)/1000000.0;
}

void TestWidget::set(TestType newtype,int lo) {
    loops = lo;
    type = newtype;
    repaint();
    type = TEST_IDLE;
    loops = 1;
}

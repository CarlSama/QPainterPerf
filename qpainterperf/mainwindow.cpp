#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->buttonReset,SIGNAL(clicked()),this,SLOT(resetButtonPressed()));
    connect(ui->buttonRun,SIGNAL(clicked()),this,SLOT(runButtonPressed()));
    ui->tabMain->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resetButtonPressed() {
    ui->spinRounds->setValue(100);
    ui->comboTests->setCurrentIndex(0);
    ui->textConsole->clear();
}

void MainWindow::runButtonPressed() {
    ui->tabMain->setCurrentIndex(1);
    int index = ui->comboTests->currentIndex();
	ui->textConsole->append("****************** Begin *****************");
	QString line = QString("This time tests %1").arg(ui->spinRounds->value() * 1000);
	ui->textConsole->append(line);
    if (index)
        runTest(index);
    else {
        for (int i=1; i<=22; ++i)
             runTest(i);
    }
    ui->progressBar->setValue(100);
	ui->textConsole->append("****************** Finish *****************");
	ui->textConsole->append("");
    ui->labelQPainter->setText("Finish.  Please check time info on tab 1.");
}

void MainWindow::runTest(int type) {
    ui->progressBar->setValue(0);
    ui->labelQPainter->setText("Ready to launch.");
    int count = ui->spinRounds->value() * 1000;
    QString line;

    switch (type) {
        case 1:
            ui->testDrawWidget->set(TestWidget::TEST_POINTS, count);
            line = QString("QPainter Points - %1 s").arg(ui->testDrawWidget->getDuration());
            break;

        case 2:
            ui->testDrawWidget->set(TestWidget::TEST_LINES, count);
            line = QString("QPainter Lines - %1 s").arg(ui->testDrawWidget->getDuration());
            break;

        case 3:
            ui->testDrawWidget->set(TestWidget::TEST_CONVEXPOLYGON, count);
            line = QString("QPainter ConvexPolygons - %1 s").arg(ui->testDrawWidget->getDuration());
            break;

        case 4:
            ui->testDrawWidget->set(TestWidget::TEST_ELLIPSE, count);
            line = QString("QPainter Ellipses - %1 s").arg(ui->testDrawWidget->getDuration());
            break;

        case 5:
            ui->testDrawWidget->set(TestWidget::TEST_IMAGE, count);
            line = QString("QPainter Images - %1 s").arg(ui->testDrawWidget->getDuration());
            break;

        case 6:
            ui->testDrawWidget->set(TestWidget::TEST_PATH, count);
            line = QString("QPainter Pathes - %1 s").arg(ui->testDrawWidget->getDuration());
            break;

        case 7:
            ui->testDrawWidget->set(TestWidget::TEST_PICTURE, count);
            line = QString("QPainter Pictures - %1 s").arg(ui->testDrawWidget->getDuration());
            break;

        case 8:
            ui->testDrawWidget->set(TestWidget::TEST_PIE, count);
            line = QString("QPainter Pies - %1 s").arg(ui->testDrawWidget->getDuration());
            break;

        case 9:
            ui->testDrawWidget->set(TestWidget::TEST_PIXMAP, count);
            line = QString("QPainter Pixmaps - %1 s").arg(ui->testDrawWidget->getDuration());
            break;

        case 10:
            ui->testDrawWidget->set(TestWidget::TEST_ARC, count);
            line = QString("QPainter Arcs - %1 s").arg(ui->testDrawWidget->getDuration());
            break;

        case 11:
            ui->testDrawWidget->set(TestWidget::TEST_CHORD, count);
            line = QString("QPainter Chords - %1 s").arg(ui->testDrawWidget->getDuration());
            break;

        case 12:
            ui->testDrawWidget->set(TestWidget::TEST_POLYGON, count);
            line = QString("QPainter Polygons - %1 s").arg(ui->testDrawWidget->getDuration());
            break;

        case 13:
            ui->testDrawWidget->set(TestWidget::TEST_POLYLINE, count);
            line = QString("QPainter Polylines - %1 s").arg(ui->testDrawWidget->getDuration());
            break;

        case 14:
            ui->testDrawWidget->set(TestWidget::TEST_RECT, count);
            line = QString("QPainter Rects - %1 s").arg(ui->testDrawWidget->getDuration());
            break;

        case 15:
            ui->testDrawWidget->set(TestWidget::TEST_ROUNDEDRECT, count);
            line = QString("QPainter RoundedRects - %1 s").arg(ui->testDrawWidget->getDuration());
            break;

        case 16:
            ui->testDrawWidget->set(TestWidget::TEST_TEXT, count);
            line = QString("QPainter Texts - %1 s").arg(ui->testDrawWidget->getDuration());
            break;

        case 17:
            ui->testDrawWidget->set(TestWidget::TEST_STATICTEXT, count);
            line = QString("QPainter StaticTexts - %1 s").arg(ui->testDrawWidget->getDuration());
            break;

        case 18:
            ui->testDrawWidget->set(TestWidget::TEST_TILEDPIXMAP, count);
            line = QString("QPainter TiledPixmaps - %1 s").arg(ui->testDrawWidget->getDuration());
            break;

        case 19:
            ui->testDrawWidget->set(TestWidget::TEST_DRAWGLYPHRUN, count);
            line = QString("QPainter DrawGlyPhruns - %1 s").arg(ui->testDrawWidget->getDuration());
            break;

        case 20:
            ui->testDrawWidget->set(TestWidget::TEST_FILLPATH, count);
            line = QString("QPainter FillPaths - %1 s").arg(ui->testDrawWidget->getDuration());
            break;

	case 21:
	    ui->testDrawWidget->set(TestWidget::TEST_ERASE, count);
	    line = QString("QPainter Erases - %1 s").arg(ui->testDrawWidget->getDuration());
	    break;

    	case 22:
	    ui->testDrawWidget->set(TestWidget::TEST_FILLRECT, count);
	    line = QString("QPainter FillRect - %1 s").arg(ui->testDrawWidget->getDuration());
	    break;

	default:
	    break;
	}

	ui->textConsole->append(line);
}

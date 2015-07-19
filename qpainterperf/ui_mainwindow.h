/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>
#include "testwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabMain;
    QWidget *tabInfo;
    QGridLayout *gridLayout_3;
    QPushButton *buttonReset;
    QLabel *labelRounds;
    QSpinBox *spinRounds;
    QComboBox *comboTests;
    QPushButton *buttonRun;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QTextEdit *textConsole;
    QWidget *tabDrawing;
    QGridLayout *gridLayout_6;
    QLabel *labelQPainter;
    TestWidget *testDrawWidget;
    QProgressBar *progressBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1175, 721);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/image/image-for-test.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabMain = new QTabWidget(centralWidget);
        tabMain->setObjectName(QString::fromUtf8("tabMain"));
        tabInfo = new QWidget();
        tabInfo->setObjectName(QString::fromUtf8("tabInfo"));
        gridLayout_3 = new QGridLayout(tabInfo);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        buttonReset = new QPushButton(tabInfo);
        buttonReset->setObjectName(QString::fromUtf8("buttonReset"));
        buttonReset->setMaximumSize(QSize(70, 16777215));

        gridLayout_3->addWidget(buttonReset, 0, 0, 1, 1);

        labelRounds = new QLabel(tabInfo);
        labelRounds->setObjectName(QString::fromUtf8("labelRounds"));
        labelRounds->setMaximumSize(QSize(70, 16777215));

        gridLayout_3->addWidget(labelRounds, 0, 1, 1, 1);

        spinRounds = new QSpinBox(tabInfo);
        spinRounds->setObjectName(QString::fromUtf8("spinRounds"));
        spinRounds->setMaximumSize(QSize(100, 16777215));
        spinRounds->setMinimum(1);
        spinRounds->setMaximum(10000);
        spinRounds->setValue(100);

        gridLayout_3->addWidget(spinRounds, 0, 2, 1, 1);

        comboTests = new QComboBox(tabInfo);
        comboTests->setObjectName(QString::fromUtf8("comboTests"));

        gridLayout_3->addWidget(comboTests, 0, 3, 1, 1);

        buttonRun = new QPushButton(tabInfo);
        buttonRun->setObjectName(QString::fromUtf8("buttonRun"));
        buttonRun->setMaximumSize(QSize(70, 16777215));

        gridLayout_3->addWidget(buttonRun, 0, 4, 1, 1);

        frame = new QFrame(tabInfo);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        textConsole = new QTextEdit(frame);
        textConsole->setObjectName(QString::fromUtf8("textConsole"));

        gridLayout_2->addWidget(textConsole, 0, 0, 1, 1);


        gridLayout_3->addWidget(frame, 1, 0, 1, 5);

        tabMain->addTab(tabInfo, QString());
        tabDrawing = new QWidget();
        tabDrawing->setObjectName(QString::fromUtf8("tabDrawing"));
        gridLayout_6 = new QGridLayout(tabDrawing);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(20, 6, 20, 20);
        labelQPainter = new QLabel(tabDrawing);
        labelQPainter->setObjectName(QString::fromUtf8("labelQPainter"));
        labelQPainter->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelQPainter->setFont(font);
        labelQPainter->setTextFormat(Qt::PlainText);

        gridLayout_6->addWidget(labelQPainter, 0, 0, 1, 1);

        testDrawWidget = new TestWidget(tabDrawing);
        testDrawWidget->setObjectName(QString::fromUtf8("testDrawWidget"));

        gridLayout_6->addWidget(testDrawWidget, 3, 0, 1, 1);

        progressBar = new QProgressBar(tabDrawing);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        gridLayout_6->addWidget(progressBar, 1, 0, 1, 1);

        tabMain->addTab(tabDrawing, QString());

        gridLayout->addWidget(tabMain, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabMain->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QPainterPerf", 0, QApplication::UnicodeUTF8));
        buttonReset->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        labelRounds->setText(QApplication::translate("MainWindow", "Test rounds:", 0, QApplication::UnicodeUTF8));
        comboTests->clear();
        comboTests->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "(0)All", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "(1)QPainter - Points", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "(2)QPainter - Lines", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "(3)QPainter - CONVEXPOLYGON", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "(4)QPainter - ELLIPSE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "(5)QPainter - IMAGE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "(6)QPainter - PATH", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "(7)QPainter - PICTURE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "(8)QPainter - PIE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "(9)QPainter - PIXMAP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "(10)QPainter - ARC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "(11)QPainter - CHORD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "(12)QPainter - POLYGON", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "(13)QPainter - POLYLINE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "(14)QPainter - RECT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "(15)QPainter - ROUNDEDRECT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "(16)QPainter - TEXT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "(17)QPainter - STATICTEXT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "(18)QPainter - TILEDPIXMAP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "(19)QPainter - DRAWGLYPHRUN", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "(20)QPainter - FILLPATH", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "(21)QPainter - ERASE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "(22)QPainter - FILLRECT", 0, QApplication::UnicodeUTF8)
        );
        buttonRun->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        tabMain->setTabText(tabMain->indexOf(tabInfo), QApplication::translate("MainWindow", "Info", 0, QApplication::UnicodeUTF8));
        labelQPainter->setText(QApplication::translate("MainWindow", "QPainter", 0, QApplication::UnicodeUTF8));
        tabMain->setTabText(tabMain->indexOf(tabDrawing), QApplication::translate("MainWindow", "Drawing", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

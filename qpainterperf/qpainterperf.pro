QT       += core gui

TARGET = qpainterperf
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    testwidget.cpp

HEADERS  += mainwindow.h \
    testwidget.h

FORMS    += mainwindow.ui \
    testwidget.ui

OTHER_FILES +=

RESOURCES += \
    Source.qrc


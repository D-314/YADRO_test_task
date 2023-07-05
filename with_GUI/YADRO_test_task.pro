QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../QAM_lib/src/awgn.cpp \
    ../QAM_lib/src/qamdemodulator.cpp \
    ../QAM_lib/src/qammodulator.cpp \
    QCustomPlot/qcustomplot.cpp \
    main.cpp \
    mainwindow.cpp \

HEADERS += \
    ../QAM_lib/inc/QAM.h \
    ../QAM_lib/inc/awgn.h \
    ../QAM_lib/inc/qamdemodulator.h \
    ../QAM_lib/inc/qammodulator.h \
    QCustomPlot/qcustomplot.h \
    mainwindow.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

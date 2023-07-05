TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../QAM_lib/src/awgn.cpp \
    ../QAM_lib/src/qamdemodulator.cpp \
    ../QAM_lib/src/qammodulator.cpp \
    main.cpp \

HEADERS += \
    ../QAM_lib/inc/QAM.h \
    ../QAM_lib/inc/awgn.h \
    ../QAM_lib/inc/qamdemodulator.h \
    ../QAM_lib/inc/qammodulator.h \
    mainwindow.h \

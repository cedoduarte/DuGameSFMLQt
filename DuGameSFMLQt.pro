#-------------------------------------------------
#
# Project created by QtCreator 2015-06-16T17:12:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DuGameSFMLQt
TEMPLATE = app

INCLUDEPATH += $$PWD/3rdParty/SFML-2.3/include

LIBS += -L$$PWD/3rdParty/SFML-2.3/lib

LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

QMAKE_CXXFLAGS += -std=gnu++14

SOURCES += main.cpp\
        MainWindow.cpp \
    QSFMLCanvas.cpp \
    DuCanvas.cpp

HEADERS  += MainWindow.h \
    QSFMLCanvas.h \
    DuCanvas.h

FORMS    += MainWindow.ui

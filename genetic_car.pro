QT += core
QT -= gui
QT += widgets

CONFIG += c++11

TARGET = genetic_car
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app



SOURCES += main.cpp \
    car.cpp \
    windows.cpp

HEADERS += \
    car.h \
    windows.h

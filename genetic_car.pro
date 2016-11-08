QT += core
QT -= gui

CONFIG += c++11

TARGET = genetic_car
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    car.cpp \
    preprocessing.cpp

HEADERS += \
    car.h \
    preprocessing.h \
    car.h

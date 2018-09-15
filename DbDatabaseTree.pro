QT += core sql gui widgets

DBLIBS +=

TARGET = databasetree

PROJECT_ROOT = ..

SOURCES += main.cpp \
    mymodel.cpp

HEADERS += \
    mymodel.h

FORMS +=

RESOURCES +=

TRANSLATIONS +=

DISTFILES += install.sql

include($${PROJECT_ROOT}/app.pri)

QT       += core gui
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += wasm

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alcool.cpp \
    clickablelabel.cpp \
    cocktails.cpp \
    dilluant.cpp \
    main.cpp \
    mainwindow.cpp \
    recipe.cpp

HEADERS += \
    alcool.h \
    clickablelabel.h \
    dilluant.h \
    mainwindow.h \
    recipe.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    alcools.csv \
    dilluants.csv

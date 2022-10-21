QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller/viewController.cpp \
    main.cpp \
    model/itemmodel.cpp \
    thirdpart/facade.cpp \
    thirdpart/hellper.cpp \
    thirdpart/parserTxt.cpp

HEADERS += \
    controller/viewController.h \
    model/itemmodel.h \
    thirdpart/facade.h \
    thirdpart/hellper.h \
    thirdpart/parser.h \
    thirdpart/parserTxt.h \
    model/dvfdfg.h

FORMS += \
    view/viewController.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

Release:RCC_DIR = release/.rcc

DISTFILES += \
    database/mt_5_can/firmware/пайка.txt \
    database/mt_5_can/firmware/проверка.txt \
    database/mt_5_can/firmware/проектирование.txt \
    database/mt_5_can/firmware/упаковка.txt \
    database/mt_5_can/info.txt \
    database/mt_5_can/instruction/пайка.txt \
    database/mt_5_can/instruction/проверка.txt \
    database/mt_5_can/instruction/проектирование.txt \
    database/mt_5_can/instruction/упаковка.txt

RESOURCES +=

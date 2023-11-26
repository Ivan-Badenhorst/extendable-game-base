QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    HealthPackCpp/healthpackcontroller.cpp \
    HealthPackCpp/healthpackmodel.cpp \
    HealthPackCpp/healthpackviewgraphical.cpp \
    TileCpp/tilecontroller.cpp \
    TileCpp/tilemodel.cpp \
    TileCpp/tileviewgraphical.cpp \
    easylevel.cpp \
    easylevelfactory.cpp \
    enemycontroller.cpp \
    gamecontroller.cpp \
    levelfactory.cpp \
    main.cpp \
    protagonistcontroller.cpp \
    protagonistmodel.cpp \
    protagonistviewgraphical.cpp \
    mainwindow.cpp



HEADERS += \
    HealthPackH/healthpackcontroller.h \
    HealthPackH/healthpackmodel.h \
    HealthPackH/healthpackview.h \
    HealthPackH/healthpackviewgraphical.h \
    IEnemyView.h \
    TileH/tileviewgraphical.h \
    TileH/tilecontroller.h \
    TileH/tilemodel.h \
    TileH/tileview.h \
    TileH/tileviewgraphical.h \
    easylevel.h \
    easylevelfactory.h \
    enemycontroller.h \
    gamecontroller.h \
    level.h \
    levelfactory.h \
    mainwindow.h \
    protagonistcontroller.h \
    protagonistmodel.h \
    protagonistview.h \
    protagonistviewgraphical.h \
    constants.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    Maps.qrc \
    Protagonist.qrc \
    HealthPack.qrc \
    Enemies.qrc




win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../CompiledLib/ -lworl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../CompiledLib/ -lworld

INCLUDEPATH += $$PWD/../CompiledLib/inc
DEPENDPATH += $$PWD/../CompiledLib/inc



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../APT_fp_resources/worldsource/release/ -lworld
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../APT_fp_resources/worldsource/debug/ -lworld
else:unix: LIBS += -L$$PWD/../APT_fp_resources/worldsource/ -lworld

INCLUDEPATH += $$PWD/../APT_fp_resources/worldsource/debug
DEPENDPATH += $$PWD/../APT_fp_resources/worldsource/debug

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../APT_fp_resources/worldsource/release/ -lworld
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../APT_fp_resources/worldsource/debug/ -lworld
else:unix: LIBS += -L$$PWD/../APT_fp_resources/worldsource/ -lworld

INCLUDEPATH += $$PWD/../APT_fp_resources/worldsource
DEPENDPATH += $$PWD/../APT_fp_resources/worldsource

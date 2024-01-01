QT       += core gui
QT       += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += $$files(src/enemy/*.cpp) \
           $$files(src/game/*.cpp) \
           $$files(src/gameview/*.cpp) \
           $$files(src/healthpack/*.cpp) \
           $$files(src/level/*.cpp) \
           $$files(src/mainwindow/*.cpp) \
           $$files(src/protagonist/*.cpp) \
           $$files(src/tile/*.cpp) \
           $$files(src/trie/*.cpp) \
           src/main.cpp
           
           
HEADERS += $$files(include/enemy/*.h) \
           $$files(include/game/*.h) \
           $$files(include/gameview/*.h) \
           $$files(include/healthpack/*.h) \
           $$files(include/level/*.h) \
           $$files(include/mainwindow/*.h) \
           $$files(include/protagonist/*.h) \
           $$files(include/tile/*.h) \
           $$files(include/trie/*.h) 


INCLUDEPATH += $$PWD/include \
               $$PWD/include/CompiledWorld \
               $$PWD/include/enemy \
               $$PWD/include/game \
               $$PWD/include/gameview \
               $$PWD/include/healthpack \
               $$PWD/include/level \
               $$PWD/include/mainwindow \
               $$PWD/include/protagonist \
               $$PWD/include/tile \
               $$PWD/include/trie \

               

FORMS += \
    ui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    resources/Maps.qrc \
    resources/Protagonist.qrc \
    resources/HealthPack.qrc \
    resources/Enemies.qrc \
    resources/tiles.qrc




win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../include/CompiledLib/ -lworl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../include/CompiledLib/ -lworld

INCLUDEPATH += $$PWD/../include/CompiledLib/inc
DEPENDPATH += $$PWD/../include/CompiledLib/inc

unix:!macx: LIBS += -L$$PWD/../worldlib/ -lworld




INCLUDEPATH += $$PWD/../APT_fp_resources/worldsource
DEPENDPATH += $$PWD/../APT_fp_resources/worldsource


INCLUDEPATH += $$PWD/../worldlib
DEPENDPATH += $$PWD/../worldlib

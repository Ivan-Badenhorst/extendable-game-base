QT += testlib
QT += gui
QT += widgets
CONFIG += qt warn_on depend_includepath testcase

CONFIG += c++20
TEMPLATE = app

SOURCES +=  tst_testtilemodel.cpp \
            ../../src/tile/tileModel.cpp\
            ../../src/tile/node.cpp\
            ../../src/enemy/xenemymodel.cpp


INCLUDEPATH += $$PWD/../../include \
               $$PWD/../../include/CompiledWorld \
               $$PWD/../../include/enemy \
               $$PWD/../../include/game \
               $$PWD/../../include/gameview \
               $$PWD/../../include/healthpack \
               $$PWD/../../include/level \
               $$PWD/../../include/mainwindow \
               $$PWD/../../include/protagonist \
               $$PWD/../../include/tile \
               $$PWD/../../include/trie \

RESOURCES += \
    ../../resources/Maps.qrc \
    ../../resources/Protagonist.qrc \
    ../../resources/HealthPack.qrc \
    ../../resources/Enemies.qrc \
    ../../resources/tiles.qrc


INCLUDEPATH += $$PWD/../../../worldlib
DEPENDPATH += $$PWD/../../../worldlib


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../CompiledLib/ -lworl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../CompiledLib/ -lworld

INCLUDEPATH += $$PWD/../../../CompiledLib/inc
DEPENDPATH += $$PWD/../../../CompiledLib/inc

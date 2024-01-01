QT += testlib
QT += gui
QT += widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_testenemymodel.cpp \
            ../../src/enemy/EnemyModel.cpp

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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../worldlib/release/ -lworld
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../worldlib/debug/ -lworld
else:unix: LIBS += -L$$PWD/../../../worldlib/ -lworld

INCLUDEPATH += $$PWD/../../../worldlib
DEPENDPATH += $$PWD/../../../worldlib

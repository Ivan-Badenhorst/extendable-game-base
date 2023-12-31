QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_testenemymodel.cpp

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

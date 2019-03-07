include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread


HEADERS += \
        tst_x.h \
    tst_testvehicule.h \
    tst_testvehiculerouler.h

SOURCES += \
        main.cpp

include(../VoitureAppli/voiture.pri)
INCLUDEPATH += ../VoitureAppli

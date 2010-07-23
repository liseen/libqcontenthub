TEMPLATE=lib
SOURCES += libqcontenthub.cpp
HEADERS += libqcontenthub.h qcontenthub/qcontenthub.h

INCLUDEPATH  = /opt/qcrawler-thirdparty/include ../qlibvdom/
LIBS = -L /opt/qcrawler-thirdparty/lib -lmsgpack-rpc

QT -= gui

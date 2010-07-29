TEMPLATE=lib
TARGET=qcontenthub
SOURCES += libqcontenthub.cpp libqcontentqueue.cpp
HEADERS += libqcontenthub.h libqcontentqueue.h qcontenthub/qcontenthub.h

INCLUDEPATH  = /opt/qcrawler-thirdparty/include ../qlibvdom/
LIBS = -L /opt/qcrawler-thirdparty/lib -lmsgpack-rpc

QT -= gui

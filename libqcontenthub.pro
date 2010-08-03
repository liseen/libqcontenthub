TEMPLATE=lib
TARGET=qcontenthub
SOURCES += libqcontenthub.cpp libqcontentqueue.cpp liburlqueue.cpp
HEADERS += libqcontenthub.h libqcontentqueue.h liburlqueue.h qcontenthub/qcontenthub.h

INCLUDEPATH  = /opt/qcrawler-thirdparty/include ../qlibvdom/
LIBS = -L /opt/qcrawler-thirdparty/lib -lmsgpack-rpc

QT -= gui

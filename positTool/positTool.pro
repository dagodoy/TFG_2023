QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    additiongraph.cpp \
    conversiongraph.cpp \
    divisiongraph.cpp \
    glossary.cpp \
    graph.cpp \
    main.cpp \
    mainwindow.cpp \
    multiplicationgraph.cpp

HEADERS += \
    additiongraph.h \
    conversiongraph.h \
    divisiongraph.h \
    explanations.h \
    glossary.h \
    graph.h \
    mainwindow.h \
    multiplicationgraph.h \
    operation.h

FORMS += \
    additiongraph.ui \
    conversiongraph.ui \
    divisiongraph.ui \
    glossary.ui \
    mainwindow.ui \
    multiplicationgraph.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../build-positTool-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/debug/glossary.json \
    images/addition.png \
    images/conversion.png \
    images/info.png \
    images/multiplication.png \
    images/positTool.ico \
    images/prueba conversion.png \
    images/prueba info.png \
    images/prueba info.png \
    images/prueba multiplicacion.png \
    images/prueba suma.png

unix|win32: LIBS += -L$$PWD/universal/lib/ -lposit_c_api_pure

INCLUDEPATH += $$PWD/universal/include
DEPENDPATH += $$PWD/universal/include

win32:RC_ICONS += ./images/positTool.ico

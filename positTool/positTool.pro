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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../../../../../Program Files (x86)/universal/lib/' -lposit_c_api_pure
else:unix: LIBS += -L$$PWD/'../../../../../Program Files (x86)/universal/lib/' -lposit_c_api_pure

INCLUDEPATH += $$PWD/'../../../../../Program Files (x86)/universal/Include'
DEPENDPATH += $$PWD/'../../../../../Program Files (x86)/universal/Include'

DISTFILES += \
    ../build-untitled1-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/debug/glossary.json

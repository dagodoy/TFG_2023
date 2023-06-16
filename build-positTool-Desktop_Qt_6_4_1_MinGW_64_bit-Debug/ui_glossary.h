/********************************************************************************
** Form generated from reading UI file 'glossary.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLOSSARY_H
#define UI_GLOSSARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Glossary
{
public:
    QWidget *centralwidget;
    QScrollArea *scrollArea;
    QWidget *scrollContents;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Glossary)
    {
        if (Glossary->objectName().isEmpty())
            Glossary->setObjectName("Glossary");
        Glossary->setEnabled(true);
        Glossary->resize(297, 600);
        centralwidget = new QWidget(Glossary);
        centralwidget->setObjectName("centralwidget");
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 10, 281, 541));
        scrollArea->setWidgetResizable(true);
        scrollContents = new QWidget();
        scrollContents->setObjectName("scrollContents");
        scrollContents->setGeometry(QRect(0, 0, 279, 539));
        scrollArea->setWidget(scrollContents);
        Glossary->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Glossary);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 297, 22));
        Glossary->setMenuBar(menubar);
        statusbar = new QStatusBar(Glossary);
        statusbar->setObjectName("statusbar");
        Glossary->setStatusBar(statusbar);

        retranslateUi(Glossary);

        QMetaObject::connectSlotsByName(Glossary);
    } // setupUi

    void retranslateUi(QMainWindow *Glossary)
    {
        Glossary->setWindowTitle(QCoreApplication::translate("Glossary", "Glossary", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Glossary: public Ui_Glossary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLOSSARY_H

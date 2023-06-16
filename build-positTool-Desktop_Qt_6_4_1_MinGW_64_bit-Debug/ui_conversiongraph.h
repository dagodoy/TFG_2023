/********************************************************************************
** Form generated from reading UI file 'conversiongraph.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERSIONGRAPH_H
#define UI_CONVERSIONGRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConversionGraph
{
public:
    QWidget *centralwidget;
    QTextEdit *textEdit_4;
    QFrame *line_11;
    QTextEdit *textEdit_5;
    QTextEdit *textEdit_7;
    QLabel *label_16;
    QFrame *line_17;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QLabel *label_17;
    QLabel *label_15;
    QTextEdit *textEdit_6;
    QFrame *line_15;
    QLabel *label_12;
    QLabel *label_11;
    QFrame *line_8;
    QLabel *label_14;
    QFrame *line_2;
    QFrame *line;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ConversionGraph)
    {
        if (ConversionGraph->objectName().isEmpty())
            ConversionGraph->setObjectName("ConversionGraph");
        ConversionGraph->resize(323, 474);
        centralwidget = new QWidget(ConversionGraph);
        centralwidget->setObjectName("centralwidget");
        textEdit_4 = new QTextEdit(centralwidget);
        textEdit_4->setObjectName("textEdit_4");
        textEdit_4->setGeometry(QRect(110, 176, 101, 30));
        line_11 = new QFrame(centralwidget);
        line_11->setObjectName("line_11");
        line_11->setGeometry(QRect(150, 206, 20, 13));
        line_11->setFrameShape(QFrame::VLine);
        line_11->setFrameShadow(QFrame::Sunken);
        textEdit_5 = new QTextEdit(centralwidget);
        textEdit_5->setObjectName("textEdit_5");
        textEdit_5->setGeometry(QRect(110, 226, 100, 31));
        textEdit_7 = new QTextEdit(centralwidget);
        textEdit_7->setObjectName("textEdit_7");
        textEdit_7->setGeometry(QRect(110, 334, 100, 31));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(152, 257, 20, 20));
        line_17 = new QFrame(centralwidget);
        line_17->setObjectName("line_17");
        line_17->setGeometry(QRect(150, 314, 20, 21));
        line_17->setFrameShape(QFrame::VLine);
        line_17->setFrameShadow(QFrame::Sunken);
        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setEnabled(true);
        textEdit_2->setGeometry(QRect(100, 70, 121, 31));
        textEdit_2->setReadOnly(false);
        textEdit_3 = new QTextEdit(centralwidget);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(90, 126, 141, 31));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(152, 318, 20, 20));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(152, 209, 20, 20));
        textEdit_6 = new QTextEdit(centralwidget);
        textEdit_6->setObjectName("textEdit_6");
        textEdit_6->setGeometry(QRect(94, 273, 141, 42));
        line_15 = new QFrame(centralwidget);
        line_15->setObjectName("line_15");
        line_15->setGeometry(QRect(150, 256, 20, 12));
        line_15->setFrameShape(QFrame::VLine);
        line_15->setFrameShadow(QFrame::Sunken);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(152, 110, 20, 20));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(152, 54, 20, 20));
        line_8 = new QFrame(centralwidget);
        line_8->setObjectName("line_8");
        line_8->setGeometry(QRect(150, 156, 20, 16));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(152, 160, 20, 20));
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(150, 100, 20, 21));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(150, 50, 20, 14));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(110, 20, 100, 31));
        ConversionGraph->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ConversionGraph);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 323, 22));
        ConversionGraph->setMenuBar(menubar);
        statusbar = new QStatusBar(ConversionGraph);
        statusbar->setObjectName("statusbar");
        ConversionGraph->setStatusBar(statusbar);

        retranslateUi(ConversionGraph);

        QMetaObject::connectSlotsByName(ConversionGraph);
    } // setupUi

    void retranslateUi(QMainWindow *ConversionGraph)
    {
        ConversionGraph->setWindowTitle(QCoreApplication::translate("ConversionGraph", "Conversion", nullptr));
        textEdit_4->setHtml(QCoreApplication::translate("ConversionGraph", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Exponent</p></body></html>", nullptr));
        textEdit_5->setHtml(QCoreApplication::translate("ConversionGraph", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Join together</p></body></html>", nullptr));
        textEdit_7->setHtml(QCoreApplication::translate("ConversionGraph", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Finish</p></body></html>", nullptr));
        label_16->setText(QCoreApplication::translate("ConversionGraph", "<html><head/><body><p><span style=\" font-size:12pt;\">\342\256\237</span></p></body></html>", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("ConversionGraph", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Fraction</p></body></html>", nullptr));
        textEdit_3->setHtml(QCoreApplication::translate("ConversionGraph", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Regime</p></body></html>", nullptr));
        label_17->setText(QCoreApplication::translate("ConversionGraph", "<html><head/><body><p><span style=\" font-size:12pt;\">\342\256\237</span></p></body></html>", nullptr));
        label_15->setText(QCoreApplication::translate("ConversionGraph", "<html><head/><body><p><span style=\" font-size:12pt;\">\342\256\237</span></p></body></html>", nullptr));
        textEdit_6->setHtml(QCoreApplication::translate("ConversionGraph", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Truncate, round and 2's complement</p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("ConversionGraph", "<html><head/><body><p><span style=\" font-size:12pt;\">\342\256\237</span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("ConversionGraph", "<html><head/><body><p><span style=\" font-size:12pt;\">\342\256\237</span></p></body></html>", nullptr));
        label_14->setText(QCoreApplication::translate("ConversionGraph", "<html><head/><body><p><span style=\" font-size:12pt;\">\342\256\237</span></p></body></html>", nullptr));
        textEdit->setHtml(QCoreApplication::translate("ConversionGraph", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Start</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConversionGraph: public Ui_ConversionGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERSIONGRAPH_H

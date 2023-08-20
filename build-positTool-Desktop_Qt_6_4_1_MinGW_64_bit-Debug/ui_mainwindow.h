/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *conversionButton;
    QPushButton *infoButton;
    QPushButton *multDivButton;
    QPushButton *additionButton;
    QPushButton *glossaryButton;
    QWidget *page_2;
    QPushButton *startButton;
    QLineEdit *lineEdit;
    QPushButton *backButton;
    QPushButton *nextButton;
    QScrollArea *scrollArea;
    QWidget *scrollContents;
    QLabel *titleLabel;
    QLineEdit *lineEdit_2;
    QComboBox *comboBox;
    QPushButton *glossaryButton_2;
    QComboBox *nBitsBox;
    QComboBox *esBox;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setEnabled(true);
        stackedWidget->setGeometry(QRect(0, 0, 801, 581));
        page = new QWidget();
        page->setObjectName("page");
        page->setEnabled(true);
        conversionButton = new QPushButton(page);
        conversionButton->setObjectName("conversionButton");
        conversionButton->setGeometry(QRect(430, 140, 151, 24));
        infoButton = new QPushButton(page);
        infoButton->setObjectName("infoButton");
        infoButton->setGeometry(QRect(210, 140, 151, 24));
        multDivButton = new QPushButton(page);
        multDivButton->setObjectName("multDivButton");
        multDivButton->setGeometry(QRect(430, 260, 151, 24));
        additionButton = new QPushButton(page);
        additionButton->setObjectName("additionButton");
        additionButton->setGeometry(QRect(200, 260, 151, 24));
        glossaryButton = new QPushButton(page);
        glossaryButton->setObjectName("glossaryButton");
        glossaryButton->setGeometry(QRect(780, 0, 16, 24));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        startButton = new QPushButton(page_2);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(440, 70, 75, 24));
        lineEdit = new QLineEdit(page_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(280, 70, 113, 22));
        lineEdit->setFrame(true);
        lineEdit->setClearButtonEnabled(false);
        backButton = new QPushButton(page_2);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(0, 0, 75, 24));
        nextButton = new QPushButton(page_2);
        nextButton->setObjectName("nextButton");
        nextButton->setEnabled(false);
        nextButton->setGeometry(QRect(690, 520, 75, 24));
        scrollArea = new QScrollArea(page_2);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(90, 160, 571, 371));
        scrollArea->setWidgetResizable(true);
        scrollContents = new QWidget();
        scrollContents->setObjectName("scrollContents");
        scrollContents->setGeometry(QRect(0, 0, 569, 369));
        scrollArea->setWidget(scrollContents);
        titleLabel = new QLabel(page_2);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setEnabled(true);
        titleLabel->setGeometry(QRect(90, 120, 571, 31));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);
        lineEdit_2 = new QLineEdit(page_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(90, 70, 113, 22));
        comboBox = new QComboBox(page_2);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(220, 70, 51, 22));
        glossaryButton_2 = new QPushButton(page_2);
        glossaryButton_2->setObjectName("glossaryButton_2");
        glossaryButton_2->setGeometry(QRect(780, 0, 16, 24));
        nBitsBox = new QComboBox(page_2);
        nBitsBox->setObjectName("nBitsBox");
        nBitsBox->setGeometry(QRect(40, 30, 41, 22));
        esBox = new QComboBox(page_2);
        esBox->setObjectName("esBox");
        esBox->setGeometry(QRect(120, 30, 41, 22));
        label = new QLabel(page_2);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 21, 16));
        label_2 = new QLabel(page_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 30, 21, 16));
        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Posit Tool", nullptr));
        conversionButton->setText(QCoreApplication::translate("MainWindow", "Conversion to Posit", nullptr));
        infoButton->setText(QCoreApplication::translate("MainWindow", "Posit Info", nullptr));
        multDivButton->setText(QCoreApplication::translate("MainWindow", "Multiplication/Division", nullptr));
        additionButton->setText(QCoreApplication::translate("MainWindow", "Addition/Subtraction", nullptr));
        glossaryButton->setText(QCoreApplication::translate("MainWindow", "i", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "GO", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        backButton->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        nextButton->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        glossaryButton_2->setText(QCoreApplication::translate("MainWindow", "i", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "n =", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "es =", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

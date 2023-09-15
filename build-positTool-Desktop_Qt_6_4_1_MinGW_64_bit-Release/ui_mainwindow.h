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
#include <QtGui/QIcon>
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
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QToolButton *conversionButton;
    QToolButton *infoButton;
    QToolButton *multDivButton;
    QToolButton *additionButton;
    QPushButton *glossaryButton;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
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
    QLabel *operationTitle;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../TFG/iconos/positTool.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setEnabled(true);
        stackedWidget->setGeometry(QRect(0, 0, 801, 581));
        page = new QWidget();
        page->setObjectName("page");
        page->setEnabled(true);
        conversionButton = new QToolButton(page);
        conversionButton->setObjectName("conversionButton");
        conversionButton->setGeometry(QRect(450, 110, 121, 118));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../TFG/iconos/prueba conversion.png"), QSize(), QIcon::Normal, QIcon::Off);
        conversionButton->setIcon(icon1);
        conversionButton->setIconSize(QSize(128, 128));
        infoButton = new QToolButton(page);
        infoButton->setObjectName("infoButton");
        infoButton->setGeometry(QRect(210, 110, 121, 111));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("images/prueba info.png"), QSize(), QIcon::Normal, QIcon::Off);
        infoButton->setIcon(icon2);
        infoButton->setIconSize(QSize(128, 128));
        infoButton->setCheckable(false);
        multDivButton = new QToolButton(page);
        multDivButton->setObjectName("multDivButton");
        multDivButton->setGeometry(QRect(450, 270, 121, 88));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../../TFG/iconos/prueba multiplicacion.png"), QSize(), QIcon::Normal, QIcon::Off);
        multDivButton->setIcon(icon3);
        multDivButton->setIconSize(QSize(128, 128));
        additionButton = new QToolButton(page);
        additionButton->setObjectName("additionButton");
        additionButton->setGeometry(QRect(210, 270, 121, 88));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../../../TFG/iconos/prueba suma.png"), QSize(), QIcon::Normal, QIcon::Off);
        additionButton->setIcon(icon4);
        additionButton->setIconSize(QSize(128, 128));
        glossaryButton = new QPushButton(page);
        glossaryButton->setObjectName("glossaryButton");
        glossaryButton->setGeometry(QRect(780, 0, 16, 24));
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(240, 230, 49, 20));
        label_4 = new QLabel(page);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(460, 230, 111, 20));
        label_5 = new QLabel(page);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(220, 370, 131, 20));
        label_6 = new QLabel(page);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(450, 370, 161, 20));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        startButton = new QPushButton(page_2);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(440, 90, 75, 24));
        lineEdit = new QLineEdit(page_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(280, 90, 113, 22));
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
        lineEdit_2->setGeometry(QRect(90, 90, 113, 22));
        comboBox = new QComboBox(page_2);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(220, 90, 51, 22));
        glossaryButton_2 = new QPushButton(page_2);
        glossaryButton_2->setObjectName("glossaryButton_2");
        glossaryButton_2->setGeometry(QRect(780, 0, 16, 24));
        nBitsBox = new QComboBox(page_2);
        nBitsBox->setObjectName("nBitsBox");
        nBitsBox->setGeometry(QRect(40, 50, 41, 22));
        esBox = new QComboBox(page_2);
        esBox->setObjectName("esBox");
        esBox->setGeometry(QRect(120, 50, 41, 22));
        label = new QLabel(page_2);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 50, 21, 16));
        label_2 = new QLabel(page_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 50, 21, 16));
        operationTitle = new QLabel(page_2);
        operationTitle->setObjectName("operationTitle");
        operationTitle->setEnabled(true);
        operationTitle->setGeometry(QRect(90, 10, 571, 31));
        operationTitle->setFont(font);
        operationTitle->setAlignment(Qt::AlignCenter);
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

        stackedWidget->setCurrentIndex(0);


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
        label_3->setText(QCoreApplication::translate("MainWindow", "Posit Info", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Conversion to Posit", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Addition/Subtraction", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Multiplication/Division", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "GO", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        backButton->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        nextButton->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        glossaryButton_2->setText(QCoreApplication::translate("MainWindow", "i", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "n =", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "es =", nullptr));
        operationTitle->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

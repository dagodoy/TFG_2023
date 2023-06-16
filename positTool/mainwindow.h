#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QQueue>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QValidator>
#include "operation.h"
#include "graph.h"
#include "conversiongraph.h"
#include "additiongraph.h"
#include "multiplicationgraph.h"
#include "divisiongraph.h"
#include "glossary.h"
#include <universal/number/posit/posit.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QLabel;
class QGroupBox;
class QGridLayout;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_backButton_clicked();

    void on_nextButton_clicked();

    void on_scrollBar_rangeChange(int min, int max);

    void on_infoButton_clicked();
    void on_conversionButton_clicked();
    void on_additionButton_clicked();
    void on_multDivButton_clicked();

    void on_operationInfoButton_clicked();
    void on_operationConversionButton_clicked();
    void on_operationAdditionButton_clicked();
    void on_operationMultiplicationButton_clicked();


    void on_glossaryButton_clicked();
private:
    QGridLayout *boxLayout;
    QGroupBox *groupBox;
    QLabel *basicLabel;
    std::vector<QTextEdit*> textEdits;
    QHBoxLayout * lay;
    QDoubleValidator* validator;

    Glossary* glossary;
    Graph* graph;

    ConversionGraph * conversionGraph;
    AdditionGraph * additionGraph;
    MultiplicationGraph * multiplicationGraph;
    DivisionGraph * divisionGraph;

    Ui::MainWindow *ui;
    double num = 0;
    //operation<long double> op;
    //operation<sw::universal::posit<8,1>> op;
    std::vector<step> steps;
    std::string title;
    int currentStep = 0;

    void updateText();
    void nextStep();
    void showOperation(std::string opTitle, std::vector<step> opSteps);
    void clearOperation();
};
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDoubleValidator>
#include "explanations.h"

#include <QtWidgets>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->titleLabel->hide();
    ui->lineEdit_2->hide();
    ui->comboBox->hide();

    //Initialize all extra windows
    glossary = new Glossary(this);
    conversionGraph = new ConversionGraph(this);
    additionGraph = new AdditionGraph(this);
    multiplicationGraph = new MultiplicationGraph(this);
    divisionGraph = new DivisionGraph(this);
    graph = nullptr;

    lay = new QHBoxLayout();
    ui->scrollContents->setLayout(lay);

    connect(ui->scrollArea->horizontalScrollBar(), SIGNAL(rangeChanged(int,int)), this, SLOT(on_scrollBar_rangeChange(int, int)));
    connect(ui->glossaryButton_2, SIGNAL(clicked()), this, SLOT(on_glossaryButton_clicked()));

    //Number input format
    validator = new QDoubleValidator(this);
    validator->setNotation(QDoubleValidator::StandardNotation);
    validator->setLocale(QLocale::C);
    validator->setDecimals(20);
    ui->lineEdit->setValidator( validator );

    ui->lineEdit->setText(QString::number(num));
}

MainWindow::~MainWindow()
{
    delete validator;
    delete glossary;
    delete ui;
}


void MainWindow::showOperation(std::string opTitle, std::vector<step> opSteps)
{
    title = opTitle;
    steps = opSteps;
    if (graph)
    {
        graph->show();
        graph->move(pos().x() - graph->width() - 10, pos().y());
    }

    QString txt = QString::fromStdString(title);
    ui->nextButton->setEnabled(true);
    ui->titleLabel->show();
    ui->titleLabel->setText(txt);

    for (int i = 0; i < textEdits.size(); i++)
    {
        delete(textEdits[i]);
    }
    textEdits.clear();

    currentStep = 0;
    nextStep();
}

//Reads the operation steps and shows them onscreen up to the current step
void MainWindow::nextStep()
{
    if (graph) graph->highlightNextStep(steps[currentStep].highlights);

    QTextCharFormat stepFormat, substepFormat, textFormat;
    stepFormat.setFontPointSize(20);
    substepFormat.setFontPointSize(15);
    textFormat.setFontPointSize(9);

    QTextEdit* textEdit = new QTextEdit();
    textEdit->setMinimumSize(ui->scrollArea->width() - 100, ui->scrollArea->height() - 100);
    textEdit->setReadOnly(true);
    textEdits.push_back(textEdit);
    lay->addWidget(textEdit);

    textEdit->setCurrentCharFormat(stepFormat);
    textEdit->setAlignment(Qt::AlignCenter);
    QString qtxt = QString::fromStdString(/*"Step " + std::to_string(currentStep+1) + ": " + */steps[currentStep].title);
    textEdit->append(qtxt);


    for (int j = 0; j < steps[currentStep].substeps.size(); j++)
    {

        textEdit->setCurrentCharFormat(substepFormat);
        qtxt = QString::fromStdString(steps[currentStep].substeps[j].title);
        textEdit->append(qtxt);
        textEdit->setAlignment(Qt::AlignLeft);
        std::vector<std::string> txt = steps[currentStep].substeps[j].text;

        textEdit->setCurrentCharFormat(textFormat);
        for (int k = 0; k < txt.size(); k++)
        {
            qtxt = QString::fromStdString(txt[k]);
            textEdit->append(qtxt);
            textEdit->setAlignment(Qt::AlignLeft);
        }
        textEdit->setCurrentCharFormat(stepFormat);
    }
    textEdit->moveCursor(QTextCursor::Start);
}


void MainWindow::on_backButton_clicked()
{
    if (graph && graph->isVisible())
    {
        graph->close();
        graph = nullptr;
    }
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_nextButton_clicked()
{
    if (currentStep < steps.size()-1)
    {
        currentStep++;
        nextStep();
    }
    if (currentStep == steps.size() -1)
    {
         ui->nextButton->setEnabled(false);
    }

}

void MainWindow::on_scrollBar_rangeChange(int min, int max)
{
    ui->scrollArea->horizontalScrollBar()->setValue(max);
}


void MainWindow::clearOperation()
{
    ui->startButton->disconnect();
    ui->nextButton->setEnabled(false);
    ui->titleLabel->hide();
    ui->lineEdit_2->hide();
    for (int i = 0; i < textEdits.size(); i++)
    {
        delete(textEdits[i]);
    }
    textEdits.clear();
    //ui->lineEdit->setText("0");
    //ui->lineEdit_2->setText("0");
    ui->comboBox->clear();
    ui->comboBox->hide();
    currentStep = 0;
}


void MainWindow::on_infoButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    clearOperation();
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(on_operationInfoButton_clicked()));
}

void MainWindow::on_conversionButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    clearOperation();
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(on_operationConversionButton_clicked()));
}



void MainWindow::on_additionButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    clearOperation();
    ui->lineEdit_2->show();
    ui->comboBox->show();
    ui->comboBox->addItem("+");
    ui->comboBox->addItem("-");
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(on_operationAdditionButton_clicked()));
}


void MainWindow::on_multDivButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    clearOperation();
    ui->lineEdit_2->show();
    ui->comboBox->show();
    ui->comboBox->addItem("*");
    ui->comboBox->addItem("/");
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(on_operationMultiplicationButton_clicked()));
}

void MainWindow::on_operationInfoButton_clicked()
{   
    baseOperation op("");
    if (nBits == 8)
    {
        if (es == 1) op = showPositInfo<8, 1>(ui->lineEdit->text().toStdString());
        else op = showPositInfo<8, 2>(ui->lineEdit->text().toStdString());
    }
    else
        if (es == 1) op = showPositInfo<16, 1>(ui->lineEdit->text().toStdString());
        else op = showPositInfo<16, 2>(ui->lineEdit->text().toStdString());

    showOperation(op.title, op.steps);
}
void MainWindow::on_operationConversionButton_clicked()
{
    graph = conversionGraph;

    baseOperation op("");
    if (nBits == 8)
    {
        if (es == 1) op = conversion_to_posit<8, 1, double>(ui->lineEdit->text().toDouble());
        else op = conversion_to_posit<8, 2, double>(ui->lineEdit->text().toDouble());
    }
    else
        if (es == 1) op = conversion_to_posit<16, 1, double>(ui->lineEdit->text().toDouble());
        else op = conversion_to_posit<16, 2, double>(ui->lineEdit->text().toDouble());

    showOperation(op.title, op.steps);
}
void MainWindow::on_operationAdditionButton_clicked()
{
    graph = additionGraph;
    baseOperation op("");
    if (ui->comboBox->currentIndex() == 0)
         op = addition<8, 1>(ui->lineEdit_2->text().toDouble(), ui->lineEdit->text().toDouble());
    else op = addition<8, 1>(ui->lineEdit_2->text().toDouble(), -(ui->lineEdit->text().toDouble()));

    showOperation(op.title, op.steps);
}
void MainWindow::on_operationMultiplicationButton_clicked()
{
    //If you open multiplication->division the multiplication will not close on clicking back
    //This fixes it
    if (graph && graph->isVisible())
    {
        graph->close();
        graph = nullptr;
    }

    baseOperation op("");
    if (ui->comboBox->currentIndex() == 0)
    {
        graph = multiplicationGraph;
        op = multiply<8, 1>(ui->lineEdit_2->text().toDouble(), ui->lineEdit->text().toDouble());
    }
    else
    {
        graph = divisionGraph;
        op = divide<8, 1>(ui->lineEdit_2->text().toDouble(), ui->lineEdit->text().toDouble());
    }

    showOperation(op.title, op.steps);
}


void MainWindow::on_glossaryButton_clicked()
{
    if (!glossary->isVisible())
    {
        glossary->show();
        glossary->move(pos().x() + width() + 10, pos().y());
    }
}

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

    connect(ui->nBitsBox, SIGNAL(currentTextChanged(QString)), this, SLOT(on_nBits_changed(QString)));
    connect(ui->esBox, SIGNAL(currentTextChanged(QString)), this, SLOT(on_es_changed(QString)));

    //Number input format
    validator = new QDoubleValidator(this);
    validator->setNotation(QDoubleValidator::StandardNotation);
    validator->setLocale(QLocale::C);
    validator->setDecimals(20);
    ui->lineEdit->setValidator( validator );
    ui->lineEdit_2->setValidator( validator );


    ui->lineEdit->setText(QString::number(num));

    ui->nBitsBox->addItem("8");
    ui->nBitsBox->addItem("16");

    ui->esBox->addItem("1");
    ui->esBox->addItem("2");
    QString path = QCoreApplication::applicationDirPath();
    path.append("/images/info.png");
    ui->infoButton->setIcon(QIcon(path));

    path = QCoreApplication::applicationDirPath();
    path.append("/images/conversion.png");
    ui->conversionButton->setIcon(QIcon(path));

    path = QCoreApplication::applicationDirPath();
    path.append("/images/addition.png");
    ui->additionButton->setIcon(QIcon(path));

    path = QCoreApplication::applicationDirPath();
    path.append("/images/multiplication.png");
    ui->multDivButton->setIcon(QIcon(path));


//    operation<int> test("Operation");
//    test.nextStep("Step");
//    test.nextSubstep("Substep");
//    test.add("Text");
//    showOperation(test.title, test.steps);
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
    if (opSteps.size() > 1)
    {
        ui->nextButton->setText("Next");
        ui->nextButton->setEnabled(true);
    }
    else ui->nextButton->setText("Finished");
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
         ui->nextButton->setText("Finished");
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
    ui->nextButton->setText("Next");
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

void MainWindow::on_nBits_changed(QString newValue)
{
    nBits = newValue.toInt();
}

void MainWindow::on_es_changed(QString newValue)
{
    es = newValue.toInt();
}

void MainWindow::on_infoButton_clicked()
{
    ui->operationTitle->setText("Posit Info");
    ui->stackedWidget->setCurrentIndex(1);
    if (operators == 2)
    {
        QString aux = ui->lineEdit->text();
        ui->lineEdit->setText(ui->lineEdit_2->text());
        ui->lineEdit_2->setText(aux);
    }
    operators = 1;
    clearOperation();
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(on_operationInfoButton_clicked()));
}

void MainWindow::on_conversionButton_clicked()
{
    ui->operationTitle->setText("Conversion");
    ui->stackedWidget->setCurrentIndex(1);
    if (operators == 2)
    {
        QString aux = ui->lineEdit->text();
        ui->lineEdit->setText(ui->lineEdit_2->text());
        ui->lineEdit_2->setText(aux);
    }
    operators = 1;
    clearOperation();
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(on_operationConversionButton_clicked()));
}



void MainWindow::on_additionButton_clicked()
{
    ui->operationTitle->setText("Addition/Subtraction");
    ui->stackedWidget->setCurrentIndex(1);
    clearOperation();
    ui->lineEdit_2->show();
    if (operators == 1)
    {
        QString aux = ui->lineEdit->text();
        ui->lineEdit->setText(ui->lineEdit_2->text());
        ui->lineEdit_2->setText(aux);
    }
    operators = 2;
    ui->comboBox->show();
    ui->comboBox->addItem("+");
    ui->comboBox->addItem("-");
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(on_operationAdditionButton_clicked()));
}


void MainWindow::on_multDivButton_clicked()
{
    ui->operationTitle->setText("Multiplication/Division");
    ui->stackedWidget->setCurrentIndex(1);
    clearOperation();
    ui->lineEdit_2->show();
    if (operators == 1)
    {
        QString aux = ui->lineEdit->text();
        ui->lineEdit->setText(ui->lineEdit_2->text());
        ui->lineEdit_2->setText(aux);
    }
    operators = 2;
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
    {
        if (nBits == 8)
        {
            if (es == 1) op = addition<8, 1>(ui->lineEdit_2->text().toDouble(), ui->lineEdit->text().toDouble());
            else op = addition<8, 2>(ui->lineEdit_2->text().toDouble(), ui->lineEdit->text().toDouble());
        }
        else
            if (es == 1) op = addition<16, 1>(ui->lineEdit_2->text().toDouble(), ui->lineEdit->text().toDouble());
            else op = addition<16, 2>(ui->lineEdit_2->text().toDouble(), ui->lineEdit->text().toDouble());
         //op = addition<8, 1>(ui->lineEdit_2->text().toDouble(), ui->lineEdit->text().toDouble());
    }

    else
    {
        if (nBits == 8)
        {
            if (es == 1) op = addition<8, 1>(ui->lineEdit_2->text().toDouble(), -(ui->lineEdit->text().toDouble()));
            else op = addition<8, 2>(ui->lineEdit_2->text().toDouble(), -(ui->lineEdit->text().toDouble()));
        }
        else
            if (es == 1) op = addition<16, 1>(ui->lineEdit_2->text().toDouble(), -(ui->lineEdit->text().toDouble()));
            else op = addition<16, 2>(ui->lineEdit_2->text().toDouble(), -(ui->lineEdit->text().toDouble()));

        //op = addition<8, 1>(ui->lineEdit_2->text().toDouble(), -(ui->lineEdit->text().toDouble()));
    }

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
    QString ay = "HOla";
    baseOperation op("");
    if (ui->comboBox->currentIndex() == 0)
    {
        graph = multiplicationGraph;

        if (nBits == 8)
        {
            if (es == 1) op = multiply<8, 1>(ui->lineEdit_2->text().toDouble(), ui->lineEdit->text().toDouble());
            else op = multiply<8, 2>(ui->lineEdit_2->text().toDouble(), ui->lineEdit->text().toDouble());
        }
        else
            if (es == 1) op = multiply<16, 1>(ui->lineEdit_2->text().toDouble(), ui->lineEdit->text().toDouble());
            else op = multiply<16, 2>(ui->lineEdit_2->text().toDouble(), ui->lineEdit->text().toDouble());

        //op = multiply<8, 1>(ui->lineEdit_2->text().toDouble(), ui->lineEdit->text().toDouble());
    }
    else
    {
        graph = divisionGraph;
        //op = divide<8, 1>(ui->lineEdit_2->text().toDouble(), ui->lineEdit->text().toDouble());

        if (nBits == 8)
        {
            if (es == 1) op = divide<8, 1>(ui->lineEdit_2->text().toDouble(), ui->lineEdit->text().toDouble());
            else op = divide<8, 2>(ui->lineEdit_2->text().toDouble(), ui->lineEdit->text().toDouble());
        }
        else
            if (es == 1) op = divide<16, 1>(ui->lineEdit_2->text().toDouble(), ui->lineEdit->text().toDouble());
            else op = divide<16, 2>(ui->lineEdit_2->text().toDouble(), ui->lineEdit->text().toDouble());
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

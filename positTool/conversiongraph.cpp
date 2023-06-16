#include "conversiongraph.h"
#include "ui_conversiongraph.h"

ConversionGraph::ConversionGraph(QWidget *parent) :
    Graph(parent),
    ui(new Ui::ConversionGraph)
{
    ui->setupUi(this);
    textEdits.push_back(ui->textEdit);
    textEdits.push_back(ui->textEdit_2);
    textEdits.push_back(ui->textEdit_3);
    textEdits.push_back(ui->textEdit_4);
    textEdits.push_back(ui->textEdit_5);
    textEdits.push_back(ui->textEdit_6);
    textEdits.push_back(ui->textEdit_7);
}

ConversionGraph::~ConversionGraph()
{
    delete ui;
}

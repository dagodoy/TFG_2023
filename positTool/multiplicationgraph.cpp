#include "multiplicationgraph.h"
#include "ui_multiplicationgraph.h"

MultiplicationGraph::MultiplicationGraph(QWidget *parent) :
    Graph(parent),
    ui(new Ui::MultiplicationGraph)
{
    ui->setupUi(this);

    textEdits.push_back(ui->textEdit);
    textEdits.push_back(ui->textEdit_2);
    textEdits.push_back(ui->textEdit_3);
    textEdits.push_back(ui->textEdit_4);
    textEdits.push_back(ui->textEdit_5);
    textEdits.push_back(ui->textEdit_6);
    textEdits.push_back(ui->textEdit_7);
    textEdits.push_back(ui->textEdit_8);
}

MultiplicationGraph::~MultiplicationGraph()
{
    delete ui;
}

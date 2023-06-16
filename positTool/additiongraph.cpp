#include "additiongraph.h"
#include "ui_additiongraph.h"

AdditionGraph::AdditionGraph(QWidget *parent) :
    Graph(parent),
    ui(new Ui::AdditionGraph)
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
    textEdits.push_back(ui->textEdit_9);
}

AdditionGraph::~AdditionGraph()
{
    delete ui;
}

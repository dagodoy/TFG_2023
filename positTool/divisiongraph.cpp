#include "divisiongraph.h"
#include "ui_divisiongraph.h"

DivisionGraph::DivisionGraph(QWidget *parent) :
    Graph(parent),
    ui(new Ui::DivisionGraph)
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

DivisionGraph::~DivisionGraph()
{
    delete ui;
}

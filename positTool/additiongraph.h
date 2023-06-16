#ifndef ADDITIONGRAPH_H
#define ADDITIONGRAPH_H

#include <QTextEdit>
#include "graph.h"
namespace Ui {
class AdditionGraph;
}

class AdditionGraph : public Graph
{
    Q_OBJECT

public:
    explicit AdditionGraph(QWidget *parent = nullptr);
    ~AdditionGraph();
private:
    Ui::AdditionGraph *ui;
};

#endif // ADDITIONGRAPH_H

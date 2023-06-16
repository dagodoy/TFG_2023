#ifndef MULTIPLICATIONGRAPH_H
#define MULTIPLICATIONGRAPH_H

#include <QMainWindow>
#include "graph.h"
namespace Ui {
class MultiplicationGraph;
}

class MultiplicationGraph : public Graph
{
    Q_OBJECT

public:
    explicit MultiplicationGraph(QWidget *parent = nullptr);
    ~MultiplicationGraph();

private:
    Ui::MultiplicationGraph *ui;
};

#endif // MULTIPLICATIONGRAPH_H

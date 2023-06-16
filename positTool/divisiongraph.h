#ifndef DIVISIONGRAPH_H
#define DIVISIONGRAPH_H

#include <QMainWindow>
#include "graph.h"
namespace Ui {
class DivisionGraph;
}

class DivisionGraph : public Graph
{
    Q_OBJECT

public:
    explicit DivisionGraph(QWidget *parent = nullptr);
    ~DivisionGraph();

private:
    Ui::DivisionGraph *ui;
};

#endif // DIVISIONGRAPH_H

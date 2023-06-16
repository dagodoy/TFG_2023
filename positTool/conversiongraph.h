#ifndef CONVERSIONGRAPH_H
#define CONVERSIONGRAPH_H

#include <QMainWindow>
#include "graph.h"
namespace Ui {
class ConversionGraph;
}

class ConversionGraph : public Graph
{
    Q_OBJECT

public:
    explicit ConversionGraph(QWidget *parent = nullptr);
    ~ConversionGraph();

private:
    Ui::ConversionGraph *ui;
};

#endif // CONVERSIONGRAPH_H

#include "graph.h"

Graph::Graph(QWidget *parent):
    QMainWindow(parent)
{
    basePalette.setColor(QPalette::Base,Qt::white);
    basePalette.setColor(QPalette::Text,Qt::black);
    highlightPalette.setColor(QPalette::Base,Qt::blue);
    highlightPalette.setColor(QPalette::Text,Qt::white);
}

void Graph::highlightNextStep(std::vector<int> highlights)
{
    for (int i = 0; i < textEdits.size(); i++)
    {
        textEdits[i]->setPalette(basePalette);
    }
    for (int i = 0; i < highlights.size(); i++)
    {
        textEdits[highlights[i]]->setPalette(highlightPalette);
    }
}

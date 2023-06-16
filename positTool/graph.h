#ifndef GRAPH_H
#define GRAPH_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPalette>
class Graph : public QMainWindow
{
public:
    explicit Graph(QWidget *parent = nullptr);
    void highlightNextStep(std::vector<int> highlights);

protected:
    std::vector<QTextEdit*> textEdits;
private:
    QPalette basePalette;
    QPalette highlightPalette;
};

#endif // GRAPH_H

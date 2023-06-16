#ifndef GLOSSARY_H
#define GLOSSARY_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QTextEdit>

namespace Ui {
class Glossary;
}

class Glossary : public QMainWindow
{
    Q_OBJECT

public:
    explicit Glossary(QWidget *parent = nullptr);
    ~Glossary();

private:
    QVBoxLayout * lay;
    std::vector<QTextEdit*> textEdits;

    Ui::Glossary *ui;
};

#endif // GLOSSARY_H

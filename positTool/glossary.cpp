#include "glossary.h"
#include "ui_glossary.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDir>


Glossary::Glossary(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Glossary)
{
    ui->setupUi(this);


    lay = new QVBoxLayout();
    ui->scrollContents->setLayout(lay);

    QString path = QCoreApplication::applicationDirPath();
    path.append("/glossary.json");

    QFile file(path);

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open file.");
    }

    QByteArray data = file.readAll();

    QJsonDocument jsonDocument(QJsonDocument::fromJson(data));

    if (!jsonDocument.isArray())
        qWarning("Not an array");

    QJsonArray jsonArray = jsonDocument.array();

    for (const QJsonValue &v : jsonArray) {
        QJsonObject arrayObject = v.toObject();
        QTextEdit* textEdit = new QTextEdit();
        textEdit->append(arrayObject.value("title").toString());
        textEdit->append(arrayObject.value("description").toString());
        textEdit->setMinimumSize(ui->scrollArea->width() - 100, 110);
        textEdit->setReadOnly(true);
        //textEdits.push_back(textEdit);
        lay->addWidget(textEdit);
    }

}

Glossary::~Glossary()
{
    delete ui;
}

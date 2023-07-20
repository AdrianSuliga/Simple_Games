#include "goodending.h"
#include "ui_goodending.h"

GoodEnding::GoodEnding(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GoodEnding)
{
    ui->setupUi(this);
}

GoodEnding::~GoodEnding()
{
    delete ui;
}

void GoodEnding::on_pushButton_clicked()
{
    emit clickedButton();
    close();
}


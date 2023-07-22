#include "badending.h"
#include "ui_badending.h"

BadEnding::BadEnding(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BadEnding)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

BadEnding::~BadEnding()
{
    delete ui;
}

void BadEnding::on_pushButton_clicked()
{
    emit buttonClicked();
    close();
}


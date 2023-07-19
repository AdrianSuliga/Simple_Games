#include "tutorial.h"
#include "ui_tutorial.h"
#include <QFontDatabase>

Tutorial::Tutorial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tutorial)
{
    ui->setupUi(this);

    int id_newfont = QFontDatabase::addApplicationFont(":/images/resources/Other/Bohemian Typewriter.ttf");
    QString family_newfont = QFontDatabase::applicationFontFamilies(id_newfont).at(0);
    QFont Bohemian(family_newfont);

    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->titleLabel->setFont(Bohemian);
    ui->introInfoLabel->setFont(Bohemian);
    ui->goalLabel->setFont(Bohemian);
    ui->soaLabel->setFont(Bohemian);
    ui->jrLabel->setFont(Bohemian);
    ui->dgLabel->setFont(Bohemian);
    ui->shopLabel->setFont(Bohemian);
    ui->hamLabel->setFont(Bohemian);
    ui->pickLabel->setFont(Bohemian);
    ui->childLabel->setFont(Bohemian);
    ui->drillLabel->setFont(Bohemian);
    ui->dynLabel->setFont(Bohemian);
}

Tutorial::~Tutorial()
{
    delete ui;
}

void Tutorial::on_closeButton_clicked()
{
    this -> close();
}


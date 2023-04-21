#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->RangeTitle->hide();

    ui->firstNumLcd->hide();
    ui->firstNumSlider->hide();
    ui->firstNumLabel->hide();
    ui->secondNumSlider->hide();
    ui->secondNumLcd->hide();
    ui->secondNumLabel->hide();

    connect(ui->firstNumSlider, SIGNAL(valueChanged(int)), ui->firstNumLcd, SLOT(display(int)));
    connect(ui->secondNumSlider, SIGNAL(valueChanged(int)), ui->secondNumLcd, SLOT(display(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BeginButton_clicked()
{
    ui->TitleLabel->hide();
    ui->IntroLabel->hide();
    ui->BeginButton->hide();

    ui->RangeTitle->show();

    ui->firstNumSlider->show();
    ui->firstNumLcd->show();
    ui->firstNumLabel->show();
    ui->secondNumSlider->show();
    ui->secondNumLcd->show();
    ui->secondNumLabel->show();
}


void MainWindow::on_quitButton_clicked()
{
    close();
}


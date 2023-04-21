#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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


}


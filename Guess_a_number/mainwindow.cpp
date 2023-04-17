#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));
    connect(ui->numberSlider, SIGNAL(valueChanged(int)), ui->lcdNumber, SLOT(display(int)));
    ui -> connectButton -> hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_connectButton_clicked()
{
    connect(ui -> horizontalSlider, SIGNAL(valueChanged(int)), ui -> progressBar, SLOT(setValue(int)));
    ui -> progressBar -> setValue(ui->horizontalSlider->value());
    ui -> disconnectButton -> show();
    ui -> connectButton -> hide();
}


void MainWindow::on_disconnectButton_clicked()
{
    disconnect(ui -> horizontalSlider, SIGNAL(valueChanged(int)), ui -> progressBar, SLOT(setValue(int)));
    ui -> horizontalSlider -> setValue(0);
    ui -> progressBar -> setValue(0);
    ui -> connectButton -> show();
    ui -> disconnectButton -> hide();
}


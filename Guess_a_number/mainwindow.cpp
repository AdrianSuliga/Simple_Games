#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui -> textEdit -> hide();
    ui -> saveButton -> hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_editTextButton_clicked()
{
    ui -> label -> hide();
    ui -> editTextButton -> hide();
    ui -> textEdit -> show();
    ui -> saveButton -> show();
}

void MainWindow::on_saveButton_clicked()
{
    ui -> label -> setText(ui->textEdit->toPlainText());
    ui -> textEdit -> hide();
    ui -> label -> show();
    ui -> saveButton -> hide();
    ui -> editTextButton -> show();
}


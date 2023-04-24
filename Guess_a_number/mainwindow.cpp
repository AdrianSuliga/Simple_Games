#include <cstdlib>
#include <QMessageBox>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->RangeTitle->hide();
    ui->SaveRangeButton->hide();
    ui->answerEdit->hide();

    ui->FirstNumEdit->hide();
    ui->SecondNumEdit->hide();

    ui->firstNumLcd->hide();
    ui->firstNumSlider->hide();
    ui->firstNumLabel->hide();

    ui->secondNumSlider->hide();
    ui->secondNumLcd->hide();
    ui->secondNumLabel->hide();

    ui->gameLabel->hide();
    ui->beginIntervalNum->hide();
    ui->beginIntervalLcd->hide();
    ui->endIntervalNum->hide();
    ui->endIntervalLcd->hide();

    ui->yGuessLabel->hide();
    ui->yGuessButton->hide();
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
    ui->SaveRangeButton->show();

    ui->FirstNumEdit->show();
    ui->firstNumSlider->show();
    ui->firstNumLcd->show();
    ui->firstNumLabel->show();

    ui->SecondNumEdit->show();
    ui->secondNumSlider->show();
    ui->secondNumLcd->show();
    ui->secondNumLabel->show();

    ui->SecondNumEdit->setText("0");
    ui->FirstNumEdit->setText("0");
}

void MainWindow::on_quitButton_clicked()
{
    close();
}

void MainWindow::on_secondNumSlider_valueChanged(int value)
{
    ui->secondNumLcd->display(value);
}

void MainWindow::on_firstNumSlider_valueChanged(int value)
{
    if (ui->secondNumSlider->value() > value)
        ui->firstNumLcd->display(value);
}

void MainWindow::on_SaveRangeButton_clicked()
{
    bool flag1, flag2;
    int num1 = ui->FirstNumEdit->toPlainText().toInt(&flag1, 10);
    int num2 = ui->SecondNumEdit->toPlainText().toInt(&flag2, 10);
    if (num2 >= num1 && num1 >= 0 && num2 > 0)
    {
        ui->RangeTitle->hide();
        ui->SaveRangeButton->hide();

        ui->FirstNumEdit->hide();
        ui->SecondNumEdit->hide();

        ui->firstNumLcd->hide();
        ui->firstNumSlider->hide();
        ui->firstNumLabel->hide();

        ui->secondNumSlider->hide();
        ui->secondNumLcd->hide();
        ui->secondNumLabel->hide();

        ui->gameLabel->show();
        ui->answerEdit->show();
        ui->yGuessLabel->show();
        ui->yGuessButton->show();

        ui->beginIntervalNum->show();
        ui->beginIntervalLcd->show();
        ui->endIntervalNum->show();
        ui->endIntervalLcd->show();

        first = num1;
        second = num2;
        random_number = randomize_number(first,second);

        ui->beginIntervalLcd->display(first);
        ui->endIntervalLcd->display(second);
    }
    else if (num2 < num1 || num1 < 0 || num2 < 0)
    {
        QMessageBox::critical(this, "Invalid range", "Range you've chosen is invalid. Please choose again.");
    }
    else if (num1 == 0 && num2 == 0)
    {
        ui->RangeTitle->hide();
        ui->SaveRangeButton->hide();

        ui->FirstNumEdit->hide();
        ui->SecondNumEdit->hide();

        ui->firstNumLcd->hide();
        ui->firstNumSlider->hide();
        ui->firstNumLabel->hide();

        ui->secondNumSlider->hide();
        ui->secondNumLcd->hide();
        ui->secondNumLabel->hide();

        ui->gameLabel->show();
        ui->answerEdit->show();
        ui->yGuessLabel->show();
        ui->yGuessButton->show();

        ui->beginIntervalNum->show();
        ui->beginIntervalLcd->show();
        ui->endIntervalNum->show();
        ui->endIntervalLcd->show();

        first = ui->firstNumLcd->value();
        second = ui->secondNumLcd->value();

        random_number = randomize_number(first,second);

        ui->beginIntervalLcd->display(first);
        ui->endIntervalLcd->display(second);
    }
}
int MainWindow::randomize_number(int fst, int snd)
{
    snd++;
    srand(time(NULL));
    return rand()%snd+fst;
}


void MainWindow::on_yGuessButton_clicked()
{
    bool flag;
    int yGuess = ui->answerEdit->toPlainText().toInt(&flag, 10);
    if (ui->answerEdit->toPlainText() == "")
        QMessageBox::critical(this, "Invalid input", "You didn't enter any number.");
    else if (yGuess < random_number)
        QMessageBox::information(this, "Hint", "Actual number is bigger");
    else if (yGuess > random_number)
        QMessageBox::information(this, "Hint", "Actual number is smaller");
    else if (yGuess == random_number)
    {
        QMessageBox::StandardButton reply = QMessageBox::information(this, "You guessed it", "Congratulations, you found the number!",
                                          QMessageBox::Ok);
        if (reply == QMessageBox::Ok)
            close();
    }
}


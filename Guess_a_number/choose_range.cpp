#include "choose_range.h"
#include "ui_choose_range.h"

#include <QMessageBox>
#include <string>

Choose_Range::Choose_Range(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Choose_Range)
{
    ui->setupUi(this);
    setWindowTitle("Guessing Game");
    ui->FirstNumEdit->insertPlainText("0");
    ui->SecondNumEdit->insertPlainText("0");
}

Choose_Range::~Choose_Range()
{
    delete ui;
}


void Choose_Range::on_QuitToTitleButton_clicked()
{
    setAttribute(Qt::WA_DeleteOnClose);
    emit accepted();
    this->close();
}


void Choose_Range::on_FirstNumSlider_valueChanged(int value)
{
    if (value <= ui->SecondNumLcd->value())
        ui->FirstNumLcd->display(value);
}


void Choose_Range::on_SecondNumSlider_valueChanged(int value)
{
    ui->SecondNumLcd->display(value);
}


void Choose_Range::on_SaveRangeButton_clicked()
{
    if (ui->FirstNumEdit->toPlainText() != "0" || ui->SecondNumEdit->toPlainText() != "0")
    {
        QString NumEdit1 = ui->FirstNumEdit->toPlainText(), NumEdit2 = ui->SecondNumEdit->toPlainText();
        std::string StringNum1 = NumEdit1.toStdString(), StringNum2 = NumEdit2.toStdString();
        bool isValidNum = areTheyValid(StringNum1, StringNum2);
        if (isValidNum == false)
            QMessageBox::critical(this,"Invalid Range","Range you've typed is invalid");
        else if(isValidNum == true)
        {
            //create new window, save this range
        }
    }
}

bool Choose_Range::areTheyValid(std::string s1, std::string s2)
{
    for (int i=0; i<s1.length(); i++)
    {
        if (s1[i] < 48 || s1[i] > 57)
            return false;
    }
    for (int i=0; i<s2.length(); i++)
    {
        if (s2[i] < 48 || s2[i] > 57)
            return false;
    }
    return true;
}


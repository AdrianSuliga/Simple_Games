#include "choose_range.h"
#include "ui_choose_range.h"

#include <QMessageBox>
#include <string>

Choose_Range::Choose_Range(QWidget *parent, int firstNum, int secondNum) :
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

//Coding QUIT TO TITLE button
void Choose_Range::on_QuitToTitleButton_clicked()
{
    setAttribute(Qt::WA_DeleteOnClose);
    emit accepted();
    this->close();
}

//Connecting FirstNumSlider to LCD display
void Choose_Range::on_FirstNumSlider_valueChanged(int value)
{
    if (value <= ui->SecondNumLcd->value())
        ui->FirstNumLcd->display(value);
}

//Coonnecting SecondNumSlider to LCD display
void Choose_Range::on_SecondNumSlider_valueChanged(int value)
{
    ui->SecondNumLcd->display(value);
}

//Saving chosen range
void Choose_Range::on_SaveRangeButton_clicked()
{
    //Check if numbers chosen in TextEdits are valid
    std::string StringNum1 = ui->FirstNumEdit->toPlainText().toStdString(),
                StringNum2 = ui->SecondNumEdit->toPlainText().toStdString();

    bool isValidNum = areTheyValid(StringNum1, StringNum2);

    //when this if executes user chose invalid range
    if (isValidNum == false)
        QMessageBox::critical(this, "Invalid range", "Range you are proposing is invalid");
    else if ((ui->FirstNumEdit->toPlainText() != "0" || ui->SecondNumEdit->toPlainText() != "0") && isValidNum == true)
    { //when this else if executes we take numbers from TextEdits
        firstNum = ui->FirstNumEdit->toPlainText().toInt(nullptr, 10);
        secondNum = ui->SecondNumEdit->toPlainText().toInt(nullptr, 10);
    }
    else //else executes when user did not enter values into TextEdits. We tak nums from LCD displayers
    {
        firstNum = ui->FirstNumLcd->value();
        secondNum = ui->SecondNumLcd->value();
    }
}

bool Choose_Range::areTheyValid(std::string s1, std::string s2)
{
    int s1L = s1.length(), s2L = s2.length();
    for (int i=0; i<s1L; i++)
    {
        if (s1[i] < 48 || s1[i] > 57)
            return false;
    }
    for (int i=0; i<s2L; i++)
    {
        if (s2[i] < 48 || s2[i] > 57)
            return false;
    }
    if (s1 == "" || s2 == "")
        return false;
    if (s1.length() > 1 && s1[0] == '0')
        return false;
    if (s2.length() > 1 && s2[0] == '0')
        return false;

    if (ui->FirstNumEdit->toPlainText().toInt(nullptr, 10) > ui->SecondNumEdit->toPlainText().toInt(nullptr, 10))
        return false;
    if (ui->FirstNumEdit->toPlainText().toInt(nullptr, 10) > 10000 || ui->SecondNumEdit->toPlainText().toInt(nullptr, 10) > 10000)
        return false;

    return true;
}


#include "guess_number.h"
#include "ui_guess_number.h"
#include <cstdlib>
#include <time.h>

Guess_Number::Guess_Number(QWidget *parent, int fNum, int sNum) :
    QDialog(parent),
    ui(new Ui::Guess_Number)
{
    ui->setupUi(this);
    firstNum = fNum;
    secondNum = sNum;
    ui->FirstNumLcd->display(firstNum);
    ui->SecondNumLcd->display(secondNum);
    randomNum = randomize(firstNum, secondNum);
}

Guess_Number::~Guess_Number()
{
    delete ui;
}


void Guess_Number::on_QuiToTitleButton_pressed()
{
    setAttribute(Qt::WA_DeleteOnClose);
    emit accepted();
    this->close();
}

int Guess_Number::randomize(int n1, int n2)
{
    int size = n2 - n1 + 1;
    srand(time(NULL));
    return rand()%size+n1;
}


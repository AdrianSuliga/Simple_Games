#include "guess_number.h"
#include "ui_guess_number.h"
#include <QMessageBox>
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
    setWindowTitle("Guessing Game");
    setAttribute(Qt::WA_DeleteOnClose);
    ui->YourGuessEdit->setPlainText("0");
}

Guess_Number::~Guess_Number()
{
    delete ui;
}


void Guess_Number::on_QuiToTitleButton_pressed()
{
    emit accepted();
    this->close();
}

int Guess_Number::randomize(int n1, int n2)
{
    int size = n2 - n1 + 1;
    srand(time(NULL));
    return rand()%size+n1;
}


void Guess_Number::on_GuessButton_pressed()
{
    int yGuess = ui->YourGuessEdit->toPlainText().toInt(nullptr, 10);

    if (areTheyValid(ui->YourGuessEdit->toPlainText().toStdString()) == false)
        QMessageBox::critical(this, "Invalid input", "Number you've entered is invalid");

    if (yGuess > randomNum)
        QMessageBox::information(this,"Hint","Number you are looking for is actually smaller");
    else if (yGuess < randomNum)
        QMessageBox::information(this,"Hint", "Number you are looking for is actually bigger");
    else if (yGuess == randomNum)
    {
        QMessageBox::StandardButton reply = QMessageBox::information(this,"You won", "Congratulations! You guessed it!",
                                                                  QMessageBox::Ok);

        if (reply == QMessageBox::Ok)
            on_QuiToTitleButton_pressed();
    }
}

bool Guess_Number::areTheyValid(std::string s)
{
    int s1L = s.length();
    for (int i=0; i<s1L; i++)
    {
        if (s[i] < 48 || s[i] > 57)
            return false;
    }
    if (s == "")
        return false;
    if (s.length() > 1 && s[0] == '0')
        return false;

    return true;
}

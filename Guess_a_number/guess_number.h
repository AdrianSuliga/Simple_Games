#ifndef GUESS_NUMBER_H
#define GUESS_NUMBER_H

#include <QDialog>

namespace Ui {
class Guess_Number;
}

class Guess_Number : public QDialog
{
    Q_OBJECT

public:
    explicit Guess_Number(QWidget *parent = nullptr, int fNum = 0, int sNum = 0);
    ~Guess_Number();

private slots:

    void on_QuiToTitleButton_pressed();

    int randomize(int n1, int n2);

    void on_GuessButton_pressed();

    bool areTheyValid(std::string s);

private:
    Ui::Guess_Number *ui;
    int firstNum, secondNum, randomNum;
};

#endif // GUESS_NUMBER_H

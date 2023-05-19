#include "titlescreen.h"
#include "choose_range.h"
#include "ui_titlescreen.h"

TitleScreen::TitleScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TitleScreen)
{
    ui->setupUi(this);
    setWindowTitle("Guessing Game");
}

TitleScreen::~TitleScreen()
{
    delete ui;
}

void TitleScreen::on_QuitButton_clicked()
{
    close();
}

void TitleScreen::on_BeginGameButton_clicked()
{
    Choose_Range *ChR = new Choose_Range(this);
    ChR -> show();
    hide();
}


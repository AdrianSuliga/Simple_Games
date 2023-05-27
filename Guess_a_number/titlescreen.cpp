#include "titlescreen.h"
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
    ChR = new Choose_Range(this);
    connect(ChR, SIGNAL(accepted()), this, SLOT(show()));
    connect(ChR, SIGNAL(destroyed()), this, SLOT(show()));
    ChR->show();
    this -> hide();
}


#include "end_game.h"
#include "ui_end_game.h"
#include <QMessageBox>

End_Game::End_Game(QWidget *parent, int result) :
    QDialog(parent),
    ui(new Ui::End_Game)
{
    ui->setupUi(this);

    setMinimumSize(500, 220);
    setMaximumSize(1000, 440);

    switch(result)
    {
    case -1: QMessageBox::warning(this, "UNABLE TO END GAME", "There is problem with ending this session!"); break;
    case 0: setLayoutForVictoryGameScreen(); break;
    case 1: setLayoutForFailureGameScreen(); break;
    case 2: setLayoutForDrawGameScreen(); break;
    }
    setStylesForEndGameScreen();
}

End_Game::~End_Game()
{
    emit accepted();
    delete ui;
}

void End_Game::setLayoutForVictoryGameScreen()
{
    setWindowTitle("YOU WON");

    iconLabel = new QLabel("TROPHY.png");
    iconLabel -> setPixmap(QPixmap(":/img/images/trophy.png"));
    iconLabel -> setScaledContents(true);
    iconLabel -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    infoLabel = new QLabel("Congratulations, you achieved victory! Your enemies will tremble in fear for eternity.");
    infoLabel -> setWordWrap(true);
    infoLabel -> setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
    infoLabel -> setMargin(5);

    dialogButton = new QPushButton("OK");
    dialogButton -> setMinimumSize(80, 30);
    leftSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    rightSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    buttonLayout = new QHBoxLayout();
    buttonLayout ->insertSpacerItem(0, leftSpacer);
    buttonLayout ->insertWidget(1, dialogButton);
    buttonLayout ->insertSpacerItem(2, rightSpacer);

    bodyLayout = new QVBoxLayout();
    bodyLayout ->insertWidget(0, infoLabel, 1);
    bodyLayout ->insertLayout(1, buttonLayout, 1);

    mainLayout = new QHBoxLayout();
    mainLayout -> insertWidget(0, iconLabel, 3);
    mainLayout -> insertLayout(1, bodyLayout, 4);

    setLayout(mainLayout);
    setAttribute(Qt::WA_DeleteOnClose);
    connect(dialogButton, SIGNAL(clicked()), this, SLOT(close()));
}
void End_Game::setLayoutForFailureGameScreen()
{
    setWindowTitle("YOU LOST HONEY");

    iconLabel = new QLabel("SAD_FACE.png");
    iconLabel -> setPixmap(QPixmap(":/img/images/defeat.png"));
    iconLabel -> setScaledContents(true);
    iconLabel -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    infoLabel = new QLabel("You were defeated... crushed into the ground by your opponent...");
    infoLabel -> setWordWrap(true);
    infoLabel -> setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
    infoLabel -> setMargin(5);

    dialogButton = new QPushButton("OK");
    dialogButton -> setMinimumSize(80, 30);
    leftSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    rightSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    buttonLayout = new QHBoxLayout();
    buttonLayout ->insertSpacerItem(0, leftSpacer);
    buttonLayout ->insertWidget(1, dialogButton);
    buttonLayout ->insertSpacerItem(2, rightSpacer);

    bodyLayout = new QVBoxLayout();
    bodyLayout ->insertWidget(0, infoLabel, 1);
    bodyLayout ->insertLayout(1, buttonLayout, 1);

    mainLayout = new QHBoxLayout();
    mainLayout -> insertWidget(0, iconLabel, 3);
    mainLayout -> insertLayout(1, bodyLayout, 4);

    setLayout(mainLayout);
    setAttribute(Qt::WA_DeleteOnClose);
    connect(dialogButton, SIGNAL(clicked()), this, SLOT(close()));
}
void End_Game::setLayoutForDrawGameScreen()
{
    setWindowTitle("NO WINNER, NO BITCHES");

    iconLabel = new QLabel("BOREDOM.png");
    iconLabel -> setPixmap(QPixmap(":/img/images/boredom.png"));
    iconLabel -> setScaledContents(true);
    iconLabel -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    infoLabel = new QLabel("Even though the fight was epic... nobody emerged victorious...");
    infoLabel -> setWordWrap(true);
    infoLabel -> setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
    infoLabel -> setMargin(5);

    dialogButton = new QPushButton("OK");
    dialogButton -> setMinimumSize(80, 30);
    leftSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    rightSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    buttonLayout = new QHBoxLayout();
    buttonLayout ->insertSpacerItem(0, leftSpacer);
    buttonLayout ->insertWidget(1, dialogButton);
    buttonLayout ->insertSpacerItem(2, rightSpacer);

    bodyLayout = new QVBoxLayout();
    bodyLayout ->insertWidget(0, infoLabel, 1);
    bodyLayout ->insertLayout(1, buttonLayout, 1);

    mainLayout = new QHBoxLayout();
    mainLayout -> insertWidget(0, iconLabel, 3);
    mainLayout -> insertLayout(1, bodyLayout, 4);

    setLayout(mainLayout);
    setAttribute(Qt::WA_DeleteOnClose);
    connect(dialogButton, SIGNAL(clicked()), this, SLOT(close()));
}

void End_Game::setStylesForEndGameScreen()
{
    setStyleSheet("background-color: rgb(11, 83, 81);");

    QString iconStyle = "background-color: rgb(0, 169, 165); border-radius: 20px; padding: 2px;";
    iconLabel -> setStyleSheet(iconStyle);

    QString dialogButtonStyle = "QPushButton { background-color: rgb(0, 169, 165);"
                                "font-size: 16px; color: white;"
                                "border-radius: 14px;"
                                "font-weight: bold;}"
                                "QPushButton:hover {"
                                "background-color: rgb(0, 143, 140);"
                                "}";
    dialogButton -> setStyleSheet(dialogButtonStyle);

    QString infoLabelStyle = "font-size: 24px; color: white; background-color: rgb(0, 169, 165);"
                             "border-style: solid; border-radius: 14px; font-weight: bold;";
    infoLabel -> setStyleSheet(infoLabelStyle);
}


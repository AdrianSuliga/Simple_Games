#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <thread>
#include <time.h>
#include <cstdlib>
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setLayoutForTitleScreen();
    setStylesForTitleScreen();
}
//std::this_thread::sleep_for(std::chrono::seconds(2));
MainWindow::~MainWindow()
{
    delete ui;
}

//TITLE SCREEN FUNCTIONS
void MainWindow::setLayoutForTitleScreen()
{
    //code title label
    titleLabel = new QLabel("ROCK, PAPER, SCISSORS");
    titleLabel -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    titleLabel -> setMargin(6);

    //set layout with quit button
    quitButton = new QPushButton("QUIT");
    quitButton -> setMinimumSize(80,30);

    hQuitSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    quitLayout = new QHBoxLayout();
    quitLayout ->insertSpacerItem(0, hQuitSpacer);
    quitLayout->insertWidget(1, quitButton);

    //set layout with rounds editor
    roundsLabel = new QLabel("ROUNDS YOU WANT TO PLAY: ");
    roundsLabel -> wordWrap();

    roundsEdit = new QLineEdit("1");
    roundsEdit -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    roundsLayout = new QHBoxLayout();
    roundsLayout -> insertWidget(0, roundsLabel);
    roundsLayout -> insertSpacing(1, 10);
    roundsLayout -> insertWidget(2, roundsEdit);

    //set layout for begin button
    beginButton = new QPushButton("BEGIN");
    beginButton -> setMinimumSize(150, 56);
    beginButton -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    hLeftBeginSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    hRightBeginSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    beginButtonLayout = new QHBoxLayout();
    beginButtonLayout -> insertSpacerItem(0, hLeftBeginSpacer);
    beginButtonLayout -> insertWidget(1, beginButton);
    beginButtonLayout -> insertSpacerItem(2, hRightBeginSpacer);

    //set layout with rounds editor and begin button
    vBeginSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    vBelowBeginButtonSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

    roundsAndBeginLayout = new QVBoxLayout();
    roundsAndBeginLayout -> insertLayout(0, roundsLayout);
    roundsAndBeginLayout -> insertSpacerItem(1, vBeginSpacer);
    roundsAndBeginLayout -> insertLayout(2, beginButtonLayout);
    roundsAndBeginLayout -> insertSpacerItem(3, vBelowBeginButtonSpacer);

    //set layouts with rules
    rulesLabel = new QLabel("RULES");
    rulesLabel -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    rulesLabel -> setFrameStyle(QFrame::Panel);
    rulesLabel -> setLineWidth(1);

    rBeatsSLabel_Rock = new QLabel();
    rBeatsSLabel_Rock ->setPixmap(QPixmap(":/img/images/rock.png"));
    rBeatsSLabel_Rock ->setScaledContents(true);
    rBeatsSLabel_Rock ->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    rBeatsSLabel_Beats = new QLabel("BEATS");
    rBeatsSLabel_Beats -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    rBeatsSLabel_Scissors = new QLabel();
    rBeatsSLabel_Scissors ->setPixmap(QPixmap(":/img/images/scissors.png"));
    rBeatsSLabel_Scissors ->setScaledContents(true);
    rBeatsSLabel_Scissors ->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    rBsLayout = new QHBoxLayout();
    rBsLayout -> insertWidget(0, rBeatsSLabel_Rock);
    rBsLayout -> insertSpacing(1, 10);
    rBsLayout -> insertWidget(2, rBeatsSLabel_Beats);
    rBsLayout -> insertSpacing(3, 10);
    rBsLayout -> insertWidget(4, rBeatsSLabel_Scissors);

    sBeatsPLabel_Scissors = new QLabel();
    sBeatsPLabel_Scissors ->setPixmap(QPixmap(":/img/images/scissors.png"));
    sBeatsPLabel_Scissors ->setScaledContents(true);
    sBeatsPLabel_Scissors ->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    sBeatsPLabel_Beats = new QLabel("BEATS");
    sBeatsPLabel_Beats -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    sBeatsPLabel_Paper = new QLabel();
    sBeatsPLabel_Paper ->setPixmap(QPixmap(":/img/images/paper.png"));
    sBeatsPLabel_Paper ->setScaledContents(true);
    sBeatsPLabel_Paper ->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    sBpLayout = new QHBoxLayout();
    sBpLayout -> insertWidget(0, sBeatsPLabel_Scissors);
    sBpLayout -> insertSpacing(1, 10);
    sBpLayout -> insertWidget(2, sBeatsPLabel_Beats);
    sBpLayout -> insertSpacing(3, 10);
    sBpLayout -> insertWidget(4, sBeatsPLabel_Paper);

    pBeatsRLabel_Paper = new QLabel("PAPER.png");
    pBeatsRLabel_Paper ->setPixmap(QPixmap(":/img/images/paper.png"));
    pBeatsRLabel_Paper ->setScaledContents(true);
    pBeatsRLabel_Paper ->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    pBeatsRLabel_Beats = new QLabel("BEATS");
    pBeatsRLabel_Beats -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    pBeatsRLabel_Rock = new QLabel("ROCK.png");
    pBeatsRLabel_Rock ->setPixmap(QPixmap(":/img/images/rock.png"));
    pBeatsRLabel_Rock ->setScaledContents(true);
    pBeatsRLabel_Rock ->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    pBrLayout = new QHBoxLayout();
    pBrLayout -> insertWidget(0, pBeatsRLabel_Paper);
    pBrLayout -> insertSpacing(1, 10);
    pBrLayout -> insertWidget(2, pBeatsRLabel_Beats);
    pBrLayout -> insertSpacing(3, 10);
    pBrLayout -> insertWidget(4, pBeatsRLabel_Rock);

    rulesLayout = new QVBoxLayout();
    rulesLayout -> insertWidget(0, rulesLabel);
    rulesLayout -> insertLayout(1, rBsLayout);
    rulesLayout -> insertLayout(2, sBpLayout);
    rulesLayout -> insertLayout(3, pBrLayout);

    //set main body layout
    hBetweenRulesAndBeginSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    mainBodyLayout = new QHBoxLayout();
    mainBodyLayout -> insertLayout(0, rulesLayout, 2);
    mainBodyLayout -> insertSpacerItem(1, hBetweenRulesAndBeginSpacer);
    mainBodyLayout -> insertLayout(2, roundsAndBeginLayout, 1);

    //set central widget's layout
    mainLayout = new QVBoxLayout(ui->centralwidget);
    mainLayout->insertLayout(0, quitLayout);
    mainLayout->insertWidget(1, titleLabel);
    mainLayout->insertSpacing(2, 20);
    mainLayout->insertLayout(3, mainBodyLayout);

    //coding push buttons
    connect(quitButton, SIGNAL(pressed()), this, SLOT(close()));
    connect(beginButton, SIGNAL(pressed()), this, SLOT(moveToGameScreen()));
}
void MainWindow::setStylesForTitleScreen()
{
    //app's background color
    ui->centralwidget->setStyleSheet("background-color: rgb(11, 83, 81);");
    ui->statusbar->setStyleSheet("background-color: rgb(11, 83, 81);");

    //set buttons style
    QString quitButtonStyle = "QPushButton { background-color: rgb(0, 169, 165);"
                              "font-size: 20px; color: white;"
                              "border-radius: 14px;}"
                              "QPushButton:hover {"
                              "background-color: rgb(0, 143, 140);"
                              "}";
    QString beginButtonStyle ="QPushButton { background-color: rgb(0, 169, 165);"
                              "font-size: 30px; color: white;"
                              "border-radius: 14px; }"
                              "QPushButton:hover {"
                              "background-color: rgb(0, 143, 140);"
                              "}";

    quitButton -> setStyleSheet(quitButtonStyle);
    beginButton -> setStyleSheet(beginButtonStyle);

    //set labels styles
    QString titleLabelStyle = "font-size: 40px; background-color: rgb(0, 169, 165); color: white; border-radius: 14px;";
    QString rulesLabelStyle = "font-size: 36px; color: white; background-color: rgb(0, 169, 165); border-style: solid; border-radius: 14px;";
    QString roundsLabelStyle = "font-size:20px; background-color: rgb(0, 169, 165); color: white; padding: 2px; border-radius: 14px;";

    QString rockIconStyle = "background-color: rgb(0, 169, 165); border-radius: 20px; padding: 2px;";
    QString paperIconStyle = "background-color: rgb(0, 169, 165); border-radius: 20px; padding: 2px;";
    QString scissorsIconStyle = "background-color: rgb(0, 169, 165); border-radius: 20px; padding: 3px;";
    QString beatsLabelStyle = "color: white; background-color: rgb(0, 169, 165); border-radius: 20px; font-size: 16px;";

    titleLabel -> setStyleSheet(titleLabelStyle);
    rulesLabel -> setStyleSheet(rulesLabelStyle);
    roundsLabel -> setStyleSheet(roundsLabelStyle);

    pBeatsRLabel_Rock -> setStyleSheet(rockIconStyle);
    rBeatsSLabel_Rock -> setStyleSheet(rockIconStyle);

    pBeatsRLabel_Paper -> setStyleSheet(paperIconStyle);
    sBeatsPLabel_Paper -> setStyleSheet(paperIconStyle);

    rBeatsSLabel_Scissors -> setStyleSheet(scissorsIconStyle);
    sBeatsPLabel_Scissors -> setStyleSheet(scissorsIconStyle);

    pBeatsRLabel_Beats -> setStyleSheet(beatsLabelStyle);
    rBeatsSLabel_Beats -> setStyleSheet(beatsLabelStyle);
    sBeatsPLabel_Beats -> setStyleSheet(beatsLabelStyle);

    //set line edit style
    QString lineEditStyle = "font-size:20px; color: white; background-color: rgb(0, 169, 165); border-style: solid;";

    roundsEdit -> setStyleSheet(lineEditStyle);
}
void MainWindow::removeLayoutForTitleScreen()
{
    //delete buttons
    delete quitButton;
    delete beginButton;
    //delete labels
    delete titleLabel;
    delete rulesLabel;
    delete roundsLabel;

    delete rBeatsSLabel_Rock;
    delete rBeatsSLabel_Beats;
    delete rBeatsSLabel_Scissors;

    delete sBeatsPLabel_Scissors;
    delete sBeatsPLabel_Beats;
    delete sBeatsPLabel_Paper;

    delete pBeatsRLabel_Paper;
    delete pBeatsRLabel_Beats;
    delete pBeatsRLabel_Rock;
    //delete edit
    delete roundsEdit;
    //delete layouts
    delete quitLayout;

    delete rBsLayout;
    delete sBpLayout;
    delete pBrLayout;

    delete rulesLayout;

    delete roundsLayout;
    delete roundsAndBeginLayout;
    delete mainBodyLayout;

    delete ui->centralwidget->layout();
}

//GAME SCREEN FUNCTIONS
void MainWindow::setLayoutForGameScreen()
{
    //set layout with user's and computer's points
    userScoreLabel = new QLabel("YOUR SCORE");
    compScoreLabel = new QLabel("ENEMY'S SCORE");

    userScoreLabel -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    userScoreLabel -> setMargin(5);
    compScoreLabel -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    compScoreLabel -> setMargin(5);

    userScoreLcd = new QLCDNumber();
    userScoreLcd -> setMinimumSize(100, 60);
    compScoreLcd = new QLCDNumber();
    compScoreLcd -> setMinimumSize(100, 60);

    userScoreLcd -> display(0);
    compScoreLcd -> display(0);

    pointsMainLayout = new QVBoxLayout();
    pointsMainLayout -> insertWidget(0, compScoreLabel, 3);
    pointsMainLayout -> insertWidget(1, compScoreLcd, 2);
    pointsMainLayout -> insertStretch(2, 2);
    pointsMainLayout -> insertWidget(3, userScoreLcd, 2);
    pointsMainLayout -> insertWidget(4, userScoreLabel, 3);

    //set layout with icons
    rockButton = new QPushButton(QIcon(QPixmap(":/img/images/rock.png")), "");
    rockButton -> setMinimumSize(100, 100);
    rockButton -> setIconSize(QSize(100,100));
    paperButton = new QPushButton(QIcon(QPixmap(":/img/images/paper.png")), "");
    paperButton -> setMinimumSize(100, 100);
    paperButton -> setIconSize(QSize(100,100));
    scissorsButton = new QPushButton(QIcon(QPixmap(":/img/images/scissors.png")), "");
    scissorsButton -> setMinimumSize(100, 100);
    scissorsButton -> setIconSize(QSize(100,100));

    iconsLayout = new QHBoxLayout();
    iconsLayout -> insertWidget(0, rockButton, 1);
    iconsLayout -> insertWidget(1, paperButton, 1);
    iconsLayout -> insertWidget(2, scissorsButton, 1);

    //set layout with main game screen
    userLabel = new QLabel();
    userLabel -> setPixmap(QPixmap(":/img/images/user.png"));
    userLabel -> setMinimumSize(100, 100);
    userLabel -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    compLabel = new QLabel();
    compLabel -> setPixmap(QPixmap(":/img/images/computer.png"));
    compLabel -> setMinimumSize(100, 100);
    compLabel -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    userChoiceLabel = new QLabel("");
    userChoiceLabel -> setMinimumSize(100, 100);
    userChoiceLabel -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    compChoiceLabel = new QLabel("");
    compChoiceLabel -> setMinimumSize(100, 100);
    compChoiceLabel -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    gameInterfaceLayout = new QVBoxLayout();
    gameInterfaceLayout -> insertWidget(0, compLabel, 3);
    gameInterfaceLayout -> insertStretch(1, 2);
    gameInterfaceLayout -> insertWidget(2, compChoiceLabel, 3);
    gameInterfaceLayout -> insertStretch(3, 2);
    gameInterfaceLayout -> insertWidget(4, userChoiceLabel, 3);
    gameInterfaceLayout -> insertStretch(5, 2);
    gameInterfaceLayout -> insertWidget(6, userLabel, 3);

    //set main body layout
    mainBodyLayout = new QHBoxLayout();
    mainBodyLayout -> insertStretch(0);
    mainBodyLayout -> insertLayout(1, gameInterfaceLayout);
    mainBodyLayout -> insertStretch(2);

    //set layout that is right from user's and comp's points
    rightSideOfWindowLayout = new QVBoxLayout();
    rightSideOfWindowLayout -> insertLayout(0, mainBodyLayout);
    rightSideOfWindowLayout -> insertLayout(1, iconsLayout);

    //main window layout
    mainLayoutGS = new QHBoxLayout(ui->centralwidget);
    mainLayoutGS ->insertLayout(0, pointsMainLayout);
    mainLayoutGS ->insertLayout(1, rightSideOfWindowLayout);
}
void MainWindow::setStylesForGameScreen()
{
    QString userAndCompScoreLabelsStyle = "font-size: 30px; color: white; background-color: rgb(0, 169, 165); border-style: solid;"
                                          "border-radius: 14px; padding: 5px;";

    userScoreLabel -> setStyleSheet(userAndCompScoreLabelsStyle);
    compScoreLabel -> setStyleSheet(userAndCompScoreLabelsStyle);

    QString LcdStyle = "font-size: 36px; color: white; background-color: rgb(0, 169, 165); border-style: solid;";

    userScoreLcd -> setStyleSheet(LcdStyle);
    compScoreLcd -> setStyleSheet(LcdStyle);

    QString iconsStyle = "QPushButton { background-color: rgb(0, 169, 165);"
                         "font-size: 30px; color: white;"
                         "border-radius: 14px; "
                         "padding: 2px;"
                         "}"
                         "QPushButton:hover {"
                         "background-color: rgb(0, 143, 140);"
                         "}";

    rockButton -> setStyleSheet(iconsStyle);
    paperButton -> setStyleSheet(iconsStyle);
    scissorsButton -> setStyleSheet(iconsStyle);

    QString iconsInLabelsStyle = "background-color: rgb(0, 169, 165); font-size: 30px; color: white; border-radius: 14px;";

    userLabel -> setStyleSheet(iconsInLabelsStyle);
    compLabel -> setStyleSheet(iconsInLabelsStyle);
    userChoiceLabel -> setStyleSheet(iconsInLabelsStyle);
    compChoiceLabel -> setStyleSheet(iconsInLabelsStyle);
}

//GAME MECHANICS FUNCTIONS
void MainWindow::moveToGameScreen()
{
    bool canIMoveOn = saveEditedInput();
    if (canIMoveOn == true)
    {
        numberOfRounds = roundsEdit->text().toInt(nullptr, 10);
        counter = 0;

        removeLayoutForTitleScreen();
        setLayoutForGameScreen();
        setStylesForGameScreen();
        srand(time(NULL));

        connect(rockButton, SIGNAL(clicked()), this, SLOT(user_chose_rock()));
        connect(paperButton, SIGNAL(clicked()), this, SLOT(user_chose_paper()));
        connect(scissorsButton, SIGNAL(clicked()), this, SLOT(user_chose_scissors()));

        if (counter == numberOfRounds)
        {
            QMessageBox::information(this, "GAME IS OVER", "The game has ended.");
            close();
        }

    }
    else if (roundsEdit->text().toInt(nullptr, 10) > 100)
        QMessageBox::warning(this, "Too big input", "Don't you think this input is a little too big? You don't want to spend"
                                                    " too much time here!");
    else
        QMessageBox::critical(this, "Invalid input", "Input you've entered is invalid");
}
bool MainWindow::saveEditedInput()
{
    //save input from text edit into std::string
    std::string lineInput = roundsEdit->text().toStdString();
    int length = lineInput.length();
    bool isItValid = true, ok;

    for (int i=0; i<length; i++)
    {
        if (lineInput[i] < 48 || lineInput[i] > 57)
        {
            isItValid = false;
            break;
        }
    }

    if (lineInput[0] == '0' || lineInput == "")
        isItValid = false;

    if (isItValid == true && roundsEdit->text().toInt(&ok, 10) <= 100)
        return true;
    else
        return false;
}

void MainWindow::user_chose_rock()
{
    int compChoice = rand() % 3;
    userChoiceLabel -> setPixmap(QPixmap(":/img/images/rock.png"));

    if (compChoice == 0)
    {
        compChoiceLabel -> setPixmap(QPixmap(":/img/images/rock.png"));
        counter++;
        QMessageBox::information(this, "DRAW", "Nobody wins in this round");
    }
    else if (compChoice == 1)
    {
        compChoiceLabel -> setPixmap(QPixmap(":/img/images/paper.png"));
        QMessageBox::information(this, "FAILURE", "You lost in this round");
        counter++;
        compScoreLcd -> display(compScoreLcd->value()+1);
    }
    else if (compChoice == 2)
    {
        compChoiceLabel -> setPixmap(QPixmap(":/img/images/scissors.png"));
        QMessageBox::information(this, "VICTORY", "You won in this round");
        counter++;
        userScoreLcd -> display(userScoreLcd->value()+1);
    }
}
void MainWindow::user_chose_paper() {int userChoice = 1;}
void MainWindow::user_chose_scissors() {int userChoice = 2;}






















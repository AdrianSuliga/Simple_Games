#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <thread>
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setLayoutForTitleScreen();
    ui->centralwidget->setStyleSheet("background-color: rgb(11, 83, 81);");
    ui->statusbar->setStyleSheet("background-color: rgb(11, 83, 81);");
}
//std::this_thread::sleep_for(std::chrono::seconds(2));
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLayoutForTitleScreen()
{
    //colors: rgb(9, 35, 39) ; rgb(11, 83, 81) ; rgb(0, 204, 201);
    //code title label
    titleLabel = new QLabel("ROCK, PAPER, SCISSORS");
    titleLabel -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    titleLabel -> setStyleSheet("font-size: 40px; background-color: rgb(0, 169, 165); color: white; border-radius: 14px;");
    titleLabel -> setMargin(6);

    //set layout with quit button
    quitButton = new QPushButton("QUIT");
    quitButton -> setMinimumSize(80,30);
    quitButton -> setStyleSheet("background-color: rgb(0, 169, 165); font-size: 20px; color: white;"
                                "border-radius: 14px;");

    hQuitSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    quitLayout = new QHBoxLayout();
    quitLayout ->insertSpacerItem(0, hQuitSpacer);
    quitLayout->insertWidget(1, quitButton);

    //set layout with rounds editor
    roundsLabel = new QLabel("ROUNDS YOU WANT TO PLAY: ");
    roundsLabel -> wordWrap();
    roundsLabel -> setStyleSheet("font-size:20px; background-color: rgb(0, 169, 165); color: white; padding: 2px; border-radius: 14px;");

    roundsEdit = new QLineEdit("1");
    roundsEdit -> setStyleSheet("font-size:20px; color: white; background-color: rgb(0, 169, 165); border-style: solid;");

    roundsLayout = new QHBoxLayout();
    roundsLayout -> insertWidget(0, roundsLabel);
    roundsLayout -> insertSpacing(1, 10);
    roundsLayout -> insertWidget(2, roundsEdit);

    //set layout for begin button
    beginButton = new QPushButton("BEGIN");
    beginButton -> setStyleSheet("background-color: rgb(0, 169, 165); font-size: 30px; color: white;"
                                 "border-radius: 14px;");
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
    rulesLabel -> setStyleSheet("font-size: 36px; color: white; background-color: rgb(0, 169, 165); border-style: solid;");
    rulesLabel -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    rulesLabel -> setFrameStyle(QFrame::Panel);
    rulesLabel -> setLineWidth(1);

    rBeatsSLabel_Rock = new QLabel();
    rBeatsSLabel_Rock ->setPixmap(QPixmap(":/img/images/rock.png"));
    rBeatsSLabel_Rock -> setStyleSheet("background-color: rgb(0, 169, 165); border-radius: 20px; padding: 2px;");
    rBeatsSLabel_Rock ->setScaledContents(true);
    rBeatsSLabel_Rock ->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    rBeatsSLabel_Beats = new QLabel("BEATS");
    rBeatsSLabel_Beats -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    rBeatsSLabel_Beats -> setStyleSheet("color: white; background-color: rgb(0, 169, 165); border-radius: 20px; font-size: 16px;");

    rBeatsSLabel_Scissors = new QLabel();
    rBeatsSLabel_Scissors ->setPixmap(QPixmap(":/img/images/scissors.png"));
    rBeatsSLabel_Scissors ->setScaledContents(true);
    rBeatsSLabel_Scissors ->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    rBeatsSLabel_Scissors -> setStyleSheet("background-color: rgb(0, 169, 165); border-radius: 20px; padding: 3px;");

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
    sBeatsPLabel_Scissors ->setStyleSheet("background-color: rgb(0, 169, 165); border-radius: 20px; padding: 3px;");


    sBeatsPLabel_Beats = new QLabel("BEATS");
    sBeatsPLabel_Beats -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    sBeatsPLabel_Beats -> setStyleSheet("color: white; background-color: rgb(0, 169, 165); border-radius: 20px; font-size: 16px;");

    sBeatsPLabel_Paper = new QLabel();
    sBeatsPLabel_Paper ->setPixmap(QPixmap(":/img/images/paper.png"));
    sBeatsPLabel_Paper ->setScaledContents(true);
    sBeatsPLabel_Paper ->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    sBeatsPLabel_Paper -> setStyleSheet("background-color: rgb(0, 169, 165); border-radius: 20px; padding: 2px;");

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
    pBeatsRLabel_Paper ->setStyleSheet("background-color: rgb(0, 169, 165); border-radius: 20px; padding: 2px;");

    pBeatsRLabel_Beats = new QLabel("BEATS");
    pBeatsRLabel_Beats -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    pBeatsRLabel_Beats -> setStyleSheet("color: white; background-color: rgb(0, 169, 165); border-radius: 20px; font-size: 16px;");

    pBeatsRLabel_Rock = new QLabel("ROCK.png");
    pBeatsRLabel_Rock ->setPixmap(QPixmap(":/img/images/rock.png"));
    pBeatsRLabel_Rock ->setScaledContents(true);
    pBeatsRLabel_Rock ->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    pBeatsRLabel_Rock ->setStyleSheet("background-color: rgb(0, 169, 165); border-radius: 20px; padding: 2px;");

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
    connect(beginButton, SIGNAL(pressed()), this, SLOT(beginGame()));
}

void MainWindow::beginGame()
{
    bool canIMoveOn = saveEditedInput();
    if (canIMoveOn == true)
    {
        removeLayoutForTitleScreen();
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
}

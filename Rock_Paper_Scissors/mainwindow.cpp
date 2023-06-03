#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setLayoutForTitleScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLayoutForTitleScreen()
{
    //code title label
    titleLabel = new QLabel("ROCK, PAPER, SCISSORS");
    titleLabel -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    titleLabel -> setStyleSheet("font-size: 40px;");
    titleLabel -> setMargin(6);
    titleLabel -> setFrameStyle(QFrame::Panel);
    titleLabel -> setLineWidth(5);

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
    roundsLabel -> setStyleSheet("font-size:20px;");
    roundsLabel -> setFrameStyle(QFrame::Panel);
    roundsLabel -> setLineWidth(1);

    roundsEdit = new QLineEdit("1");
    roundsEdit -> setStyleSheet("font-size:20px;");

    roundsLayout = new QHBoxLayout();
    roundsLayout -> insertWidget(0, roundsLabel);
    roundsLayout -> insertWidget(1, roundsEdit);

    //set layout with rounds editor and begin button
    vBeginSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

    beginButton = new QPushButton("BEGIN");

    roundsAndBeginLayout = new QVBoxLayout();
    roundsAndBeginLayout->insertLayout(0, roundsLayout);
    roundsAndBeginLayout->insertSpacerItem(1, vBeginSpacer);
    roundsAndBeginLayout->insertWidget(2, beginButton);

    //set layouts with rules
    rulesLabel = new QLabel("RULES");
    rulesLabel -> setStyleSheet("font-size: 36px;");
    rulesLabel -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    rulesLabel -> setFrameStyle(QFrame::Panel);
    rulesLabel -> setLineWidth(1);

    rBeatsSLabel_Rock = new QLabel("ROCK.png");
    rBeatsSLabel_Beats = new QLabel("BEATS");
    rBeatsSLabel_Beats -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    rBeatsSLabel_Scissors = new QLabel("SCISSORS.png");

    rBsLayout = new QHBoxLayout();
    rBsLayout -> insertWidget(0, rBeatsSLabel_Rock);
    rBsLayout -> insertSpacing(1, 10);
    rBsLayout -> insertWidget(2, rBeatsSLabel_Beats);
    rBsLayout -> insertSpacing(3, 10);
    rBsLayout -> insertWidget(4, rBeatsSLabel_Scissors);

    sBeatsPLabel_Scissors = new QLabel("SCISSORS.png");
    sBeatsPLabel_Beats = new QLabel("BEATS");
    sBeatsPLabel_Beats -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    sBeatsPLabel_Paper = new QLabel("PAPER.png");

    sBpLayout = new QHBoxLayout();
    sBpLayout -> insertWidget(0, sBeatsPLabel_Scissors);
    sBpLayout -> insertSpacing(1, 10);
    sBpLayout -> insertWidget(2, sBeatsPLabel_Beats);
    sBpLayout -> insertSpacing(3, 10);
    sBpLayout -> insertWidget(4, sBeatsPLabel_Paper);

    pBeatsRLabel_Paper = new QLabel("PAPER.png");
    pBeatsRLabel_Beats = new QLabel("BEATS");
    pBeatsRLabel_Beats -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    pBeatsRLabel_Rock = new QLabel("ROCK.png");

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
    saveEditedInput();
    removeLayoutForTitleScreen();
}

void MainWindow::saveEditedInput()
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
        numberOfRounds = roundsEdit->text().toInt(&ok, 10);
    else if (isItValid == true && roundsEdit->text().toInt(&ok, 10) > 100)
        QMessageBox::warning(roundsEdit, "Too big input", "Don't you think your input is... too big? You don't want to spend too much time"
                                                          " here!");
    else
        QMessageBox::critical(roundsEdit, "Invalid input", "Number of rounds you want to play is incorrect");
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

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>

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
    titleLabel = new QLabel("ROCK, PAPER, SCISSORS");

    //set layout with quit button
    quitButton = new QPushButton("QUIT");
    hQuitSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    quitLayout = new QHBoxLayout();
    quitLayout ->insertSpacerItem(0, hQuitSpacer);
    quitLayout->insertWidget(1, quitButton);

    //set layout with rounds editor
    roundsLabel = new QLabel("ROUNDS YOU WANT TO PLAY: ");
    roundsEdit = new QLineEdit("1");
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

    rBeatsSLabel_Rock = new QLabel("ROCK.png");
    rBeatsSLabel_Beats = new QLabel("BEATS");
    rBeatsSLabel_Scissors = new QLabel("SCISSORS.png");
    rBsLayout = new QHBoxLayout();
    rBsLayout -> insertWidget(0, rBeatsSLabel_Rock);
    rBsLayout -> insertWidget(1, rBeatsSLabel_Beats);
    rBsLayout -> insertWidget(2, rBeatsSLabel_Scissors);

    sBeatsPLabel_Scissors = new QLabel("SCISSORS.png");
    sBeatsPLabel_Beats = new QLabel("BEATS");
    sBeatsPLabel_Paper = new QLabel("PAPER.png");
    sBpLayout = new QHBoxLayout();
    sBpLayout -> insertWidget(0, sBeatsPLabel_Scissors);
    sBpLayout -> insertWidget(1, sBeatsPLabel_Beats);
    sBpLayout -> insertWidget(2, sBeatsPLabel_Paper);

    pBeatsRLabel_Paper = new QLabel("PAPER.png");
    pBeatsRLabel_Beats = new QLabel("BREATS");
    pBeatsRLabel_Rock = new QLabel("ROCK.png");
    pBrLayout = new QHBoxLayout();
    pBrLayout -> insertWidget(0, pBeatsRLabel_Paper);
    pBrLayout -> insertWidget(1, pBeatsRLabel_Beats);
    pBrLayout -> insertWidget(2, pBeatsRLabel_Rock);

    rulesLayout = new QVBoxLayout();
    rulesLayout -> insertWidget(0, rulesLabel);
    rulesLayout -> insertLayout(1, rBsLayout);
    rulesLayout -> insertLayout(2, sBpLayout);
    rulesLayout -> insertLayout(3, pBrLayout);

    //set main body layout
    hBetweenRulesAndBeginSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    mainBodyLayout = new QHBoxLayout();
    mainBodyLayout -> insertLayout(0, rulesLayout);
    mainBodyLayout -> insertSpacerItem(1, hBetweenRulesAndBeginSpacer);
    mainBodyLayout -> insertLayout(2, roundsAndBeginLayout);

    //set central layout
    mainLayout = new QVBoxLayout(ui->centralwidget);
    mainLayout->insertLayout(0, quitLayout);
    mainLayout->insertWidget(1, titleLabel);
    mainLayout->insertLayout(2, mainBodyLayout);
}

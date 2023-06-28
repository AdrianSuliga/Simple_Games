#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFontDatabase>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    points = 0.0;
    multiplier = 1.0;
    hammers = 0;
    pickaxes = 0;
    children = 0;
    drills = 0;
    dynamite = 0;
    cbAbility = checkContinueButton();

    setLayoutTitleScreen();
    setStyleTitleScreen(cbAbility);

    ui->statusbar->hide();
    setMinimumSize(400, 400);
    setMaximumSize(1024, 1024);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLayoutTitleScreen()
{
    //title label
    titleLabel = new QLabel("AMETHYST CLICKER");
    int id_newfont = QFontDatabase::addApplicationFont(":/images/resources/Other/Bohemian Typewriter.ttf");
    QString family_newfont = QFontDatabase::applicationFontFamilies(id_newfont).at(0);
    QFont Bohemian(family_newfont);
    titleLabel -> setFont(Bohemian);
    titleLabel -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    //buttons
    continueButton = new QPushButton("CONTINUE");
    continueButton -> setMinimumSize(80, 30);
    continueButton -> setFont(Bohemian);

    newgameButton = new QPushButton("NEW GAME");
    newgameButton -> setMinimumSize(80, 30);
    newgameButton -> setFont(Bohemian);

    tutorialButton = new QPushButton("TUTORIAL");
    tutorialButton -> setMinimumSize(80, 30);
    tutorialButton -> setFont(Bohemian);

    aboutButton = new QPushButton("ABOUT");
    aboutButton -> setMinimumSize(80, 30);
    aboutButton -> setFont(Bohemian);

    quitButton = new QPushButton("QUIT");
    quitButton -> setMinimumSize(80, 30);
    quitButton -> setFont(Bohemian);

    //spacers
    lcSpacer = new QSpacerItem(40,10,QSizePolicy::Expanding,QSizePolicy::Minimum);
    rcSpacer = new QSpacerItem(40,10,QSizePolicy::Expanding,QSizePolicy::Minimum);
    lnSpacer = new QSpacerItem(40,10,QSizePolicy::Expanding,QSizePolicy::Minimum);
    rnSpacer = new QSpacerItem(40,10,QSizePolicy::Expanding,QSizePolicy::Minimum);
    ltSpacer = new QSpacerItem(40,10,QSizePolicy::Expanding,QSizePolicy::Minimum);
    rtSpacer = new QSpacerItem(40,10,QSizePolicy::Expanding,QSizePolicy::Minimum);
    laSpacer = new QSpacerItem(40,10,QSizePolicy::Expanding,QSizePolicy::Minimum);
    raSpacer = new QSpacerItem(40,10,QSizePolicy::Expanding,QSizePolicy::Minimum);
    lqSpacer = new QSpacerItem(40,10,QSizePolicy::Expanding,QSizePolicy::Minimum);
    rqSpacer = new QSpacerItem(40,10,QSizePolicy::Expanding,QSizePolicy::Minimum);

    //layouts
    continueLayout = new QHBoxLayout();
    continueLayout -> insertSpacerItem(0, lcSpacer);
    continueLayout -> insertWidget(1, continueButton);
    continueLayout -> insertSpacerItem(2, rcSpacer);

    newgameLayout = new QHBoxLayout();
    newgameLayout -> insertSpacerItem(0, lnSpacer);
    newgameLayout -> insertWidget(1, newgameButton);
    newgameLayout -> insertSpacerItem(2, rnSpacer);

    tutorialLayout = new QHBoxLayout();
    tutorialLayout -> insertSpacerItem(0, ltSpacer);
    tutorialLayout -> insertWidget(1, tutorialButton);
    tutorialLayout -> insertSpacerItem(2, rtSpacer);

    aboutLayout = new QHBoxLayout();
    aboutLayout -> insertSpacerItem(0, laSpacer);
    aboutLayout -> insertWidget(1, aboutButton);
    aboutLayout -> insertSpacerItem(2, raSpacer);

    quitLayout = new QHBoxLayout();
    quitLayout -> insertSpacerItem(0, lqSpacer);
    quitLayout -> insertWidget(1, quitButton);
    quitLayout -> insertSpacerItem(2, rqSpacer);

    mainLayout = new QVBoxLayout(ui->centralwidget);
    mainLayout -> insertWidget(0, titleLabel, 3);
    mainLayout -> insertStretch(1, 1);
    mainLayout -> insertLayout(2, continueLayout, 2);
    mainLayout -> insertLayout(3, newgameLayout, 2);
    mainLayout -> insertLayout(4, tutorialLayout, 2);
    mainLayout -> insertStretch(5, 1);
    mainLayout -> insertLayout(6, aboutLayout, 2);
    mainLayout -> insertLayout(7, quitLayout, 2);
    mainLayout -> insertStretch(8, 1);
}

void MainWindow::setStyleTitleScreen(bool cbAbility)
{
    //background
    ui->centralwidget->setStyleSheet("#centralwidget {border-image: url(:/images/resources/Other/background.png) 0 0 0 0 stretch stretch;}");
    //title label

    //buttons
    if (cbAbility == false)
    {

    }
    else
    {

    }
}

void MainWindow::removeStyleTitleScreen()
{

}

bool MainWindow::checkContinueButton()
{
    return false;
}

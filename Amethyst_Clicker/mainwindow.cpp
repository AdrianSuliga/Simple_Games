#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFontDatabase>
#include <QSizeGrip>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setWindowIcon(QIcon(QPixmap(":/images/resources/Other/Icon.png")));

    points = 0.0;
    multiplier = 1.0;
    hammers = 0;
    pickaxes = 0;
    children = 0;
    drills = 0;
    dynamite = 0;

    setLayoutTitleScreen();
    checkContinueButton();
    setStyleTitleScreen();

    setMinimumSize(400, 400);
    setMaximumSize(1024, 1024);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLayoutTitleScreen()
{
    //TITLE BAR
    iconLabelTB = new QLabel("ICON.png");
    iconLabelTB -> setPixmap(QPixmap(":/images/resources/Other/Icon.png"));
    iconLabelTB -> setScaledContents(true);
    iconLabelTB -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    iconLabelTB -> setMinimumSize(30, 30);

    titleLabelTB = new QLabel("FOOL'S GOLD");
    titleLabelTB -> setAlignment(Qt::AlignCenter);

    spacerTB = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    minimiseButtonTB = new QPushButton("-");
    minimiseButtonTB -> setFixedSize(30, 30);
    maximiseButtonTB = new QPushButton("O");
    maximiseButtonTB -> setFixedSize(30, 30);
    exitButtonTB = new QPushButton("X");
    exitButtonTB -> setFixedSize(30, 30);

    mainLayoutTB = new QHBoxLayout();
    mainLayoutTB -> insertWidget(0, iconLabelTB);
    mainLayoutTB -> insertSpacing(1, 30);
    mainLayoutTB -> insertWidget(2, titleLabelTB);
    mainLayoutTB -> insertSpacerItem(3, spacerTB);
    mainLayoutTB -> insertWidget(4, minimiseButtonTB);
    mainLayoutTB -> insertWidget(5, maximiseButtonTB);
    mainLayoutTB -> insertWidget(6, exitButtonTB);
    mainLayoutTB -> setContentsMargins(0, 0, 0, 0);

    TB = new QWidget();
    TB -> setLayout(mainLayoutTB);
    TB -> setFixedHeight(30);
    //TITLE SCREEN
    //title label
    titleLabelTS = new QLabel("FOOL'S GOLD");
    int id_newfont = QFontDatabase::addApplicationFont(":/images/resources/Other/Bohemian Typewriter.ttf");
    QString family_newfont = QFontDatabase::applicationFontFamilies(id_newfont).at(0);
    QFont Bohemian(family_newfont);
    titleLabelTS -> setFont(Bohemian);
    titleLabelTS -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    //buttons
    continueButtonTS = new QPushButton("CONTINUE");
    continueButtonTS -> setMinimumSize(100, 40);
    continueButtonTS -> setFont(Bohemian);

    newgameButtonTS = new QPushButton("NEW GAME");
    newgameButtonTS -> setMinimumSize(100, 40);
    newgameButtonTS -> setFont(Bohemian);

    tutorialButtonTS = new QPushButton("TUTORIAL");
    tutorialButtonTS -> setMinimumSize(100, 40);
    tutorialButtonTS -> setFont(Bohemian);

    aboutButtonTS = new QPushButton("ABOUT");
    aboutButtonTS -> setMinimumSize(100, 40);
    aboutButtonTS -> setFont(Bohemian);

    quitButtonTS = new QPushButton("QUIT");
    quitButtonTS -> setMinimumSize(100, 40);
    quitButtonTS -> setFont(Bohemian);

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
    continueLayoutTS = new QHBoxLayout();
    continueLayoutTS -> insertSpacerItem(0, lcSpacer);
    continueLayoutTS -> insertWidget(1, continueButtonTS);
    continueLayoutTS -> insertSpacerItem(2, rcSpacer);

    newgameLayoutTS = new QHBoxLayout();
    newgameLayoutTS -> insertSpacerItem(0, lnSpacer);
    newgameLayoutTS -> insertWidget(1, newgameButtonTS);
    newgameLayoutTS -> insertSpacerItem(2, rnSpacer);

    tutorialLayoutTS = new QHBoxLayout();
    tutorialLayoutTS -> insertSpacerItem(0, ltSpacer);
    tutorialLayoutTS -> insertWidget(1, tutorialButtonTS);
    tutorialLayoutTS -> insertSpacerItem(2, rtSpacer);

    aboutLayoutTS = new QHBoxLayout();
    aboutLayoutTS -> insertSpacerItem(0, laSpacer);
    aboutLayoutTS -> insertWidget(1, aboutButtonTS);
    aboutLayoutTS -> insertSpacerItem(2, raSpacer);

    quitLayoutTS = new QHBoxLayout();
    quitLayoutTS -> insertSpacerItem(0, lqSpacer);
    quitLayoutTS -> insertWidget(1, quitButtonTS);
    quitLayoutTS -> insertSpacerItem(2, rqSpacer);

    //grips
    brGrip = new QSizeGrip(this);
    blGrip = new QSizeGrip(this);

    bottomGrip = new QWidget();
    bGLayout = new QHBoxLayout();
    bGLayout -> insertWidget(0, blGrip, 0, Qt::AlignBottom | Qt::AlignLeft);
    bGLayout -> insertWidget(1, brGrip, 0, Qt::AlignBottom | Qt::AlignRight);
    bGLayout -> setContentsMargins(QMargins());
    bottomGrip -> setLayout(bGLayout);

    mainLayoutTS = new QVBoxLayout(ui->centralwidget);
    mainLayoutTS -> insertWidget(0, TB);
    mainLayoutTS -> insertWidget(1, titleLabelTS, 3);
    mainLayoutTS -> insertStretch(2, 1);
    mainLayoutTS -> insertLayout(3, continueLayoutTS, 2);
    mainLayoutTS -> insertLayout(4, newgameLayoutTS, 2);
    mainLayoutTS -> insertLayout(5, tutorialLayoutTS, 2);
    mainLayoutTS -> insertStretch(6, 1);
    mainLayoutTS -> insertLayout(7, aboutLayoutTS, 2);
    mainLayoutTS -> insertLayout(8, quitLayoutTS, 2);
    mainLayoutTS -> insertStretch(9, 1);
    mainLayoutTS -> insertWidget(10, bottomGrip, 0);
    mainLayoutTS -> setContentsMargins(0, 0, 0, 0);

    connect(quitButtonTS, SIGNAL(clicked()), this, SLOT(close()));

    connect(minimiseButtonTB, SIGNAL(clicked()), this, SLOT(showMinimized()));
    connect(maximiseButtonTB, SIGNAL(clicked()), this, SLOT());
    connect(exitButtonTB, SIGNAL(clicked()), this, SLOT(close()));
}
void MainWindow::setStyleTitleScreen()
{
    //background
    ui->centralwidget->setStyleSheet("#centralwidget {"
                                     "border-image: url(:/images/resources/Other/background.png) 0 0 0 0 stretch stretch;"
                                     "}");
    TB -> setStyleSheet("background-color: rgb(84,94,106);");

    //title label
    QString titleLabelTSStyle = "background-color: rgba(40,60,69,255);"
                                "color: rgba(254,220,105,255);"
                                "border-radius: 20px;"
                                "margin-left: 80px;"
                                "margin-right: 80px;"
                                "margin-top: 20px;"
                                "font-size: 54px;";
    titleLabelTS -> setStyleSheet(titleLabelTSStyle);

    //buttons
    QString disabledButtons = "QPushButton {"
                              "background-color: rgba(84,94,106,255);"
                              "color: #B8BF33;"
                              "font-size: 16px;"
                              "}";
    QString enabledButtons = "QPushButton {"
                             "background-color: rgba(40,60,69,255);"
                             "color: rgba(254,220,105,255);"
                             "font-size: 16px;"
                             "}"
                             "QPushButton:hover {"
                             "background-color: rgba(11,29,41,255);"
                             "}";
    if (continueButtonTS->isEnabled() == false)
        continueButtonTS -> setStyleSheet(disabledButtons);
    else
        continueButtonTS -> setStyleSheet(enabledButtons);

    newgameButtonTS -> setStyleSheet(enabledButtons);
    tutorialButtonTS -> setStyleSheet(enabledButtons);
    aboutButtonTS -> setStyleSheet(enabledButtons);
    quitButtonTS -> setStyleSheet(enabledButtons);

    QString buttonTBStyle = "QPushButton {"
                            "color: white;"
                            "background-color: rgb(84,94,106);"
                            "}"
                            "QPushButton:hover {"
                            "background-color: rgb(110, 120, 135);"
                            "}";

    minimiseButtonTB -> setStyleSheet(buttonTBStyle);
    maximiseButtonTB -> setStyleSheet(buttonTBStyle);
    exitButtonTB -> setStyleSheet("QPushButton {"
                                  "color: white;"
                                  "background-color: rgb(84,94,106);"
                                  "}"
                                  "QPushButton:hover {"
                                  "background-color: red;"
                                  "}");

    QString titleLabelTBStyle = "color: white;";
    titleLabelTB -> setStyleSheet(titleLabelTBStyle);
}

void MainWindow::removeLayoutTitleScreen()
{

}

void MainWindow::checkContinueButton()
{
    continueButtonTS -> setEnabled(false);
}

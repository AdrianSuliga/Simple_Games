#include "mainwindow.h"
#include "qscreen.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QFontDatabase>
#include <QSizeGrip>
#include <QMessageBox>
#include <QDebug>
#include <cstdlib>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setWindowIcon(QIcon(QPixmap(":/images/resources/Other/Icon.png")));
    setWindowTitle("FOOL'S GOLD");
    points = 0.0;
    multiplier = 1.0;
    hammers = 0;
    pickaxes = 0;
    children = 0;
    drills = 0;
    dynamite = 0;

    oreType = -1;
    cSave = -1;

    setLayoutTitleScreen();
    setStyleTitleScreen();

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeo = screen->availableGeometry();
    int height = screenGeo.height();
    int width = screenGeo.width();
    int x = (width - this->width()) / 2;
    int y = (height - this->height()) / 2;
    setGeometry(x, y, 400, 500);
    setMinimumSize(500, 500);
    setMaximumSize(width, height);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLayoutTitleScreen()
{
    int id_newfont = QFontDatabase::addApplicationFont(":/images/resources/Other/Bohemian Typewriter.ttf");
    QString family_newfont = QFontDatabase::applicationFontFamilies(id_newfont).at(0);
    QFont Bohemian(family_newfont);
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
    mainLayoutTB -> setSpacing(2);

    TB = new QWidget();
    TB -> setLayout(mainLayoutTB);
    TB -> setFixedHeight(30);
    //TITLE SCREEN
    //title label
    titleLabelTS = new QLabel("FOOL'S GOLD");
    titleLabelTS -> setFont(Bohemian);
    titleLabelTS -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    titleLabelTS -> setWordWrap(true);

    titleLayoutTS = new QVBoxLayout();
    titleLayoutTS -> insertWidget(0, titleLabelTS);

    titleWidgetTS = new QWidget();
    titleWidgetTS -> setLayout(titleLayoutTS);

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
    brGripTS = new QSizeGrip(this);
    blGripTS = new QSizeGrip(this);

    bottomGripTS = new QWidget();
    bGLayout = new QHBoxLayout();
    bGLayout -> insertWidget(0, blGripTS, 0, Qt::AlignBottom | Qt::AlignLeft);
    bGLayout -> insertWidget(1, brGripTS, 0, Qt::AlignBottom | Qt::AlignRight);
    bGLayout -> setContentsMargins(QMargins());
    bottomGripTS -> setLayout(bGLayout);

    //main layout
    mainLayoutTS = new QVBoxLayout();
    mainLayoutTS -> insertWidget(0, titleWidgetTS, 2);
    mainLayoutTS -> insertStretch(1, 1);
    mainLayoutTS -> insertLayout(2, continueLayoutTS, 2);
    mainLayoutTS -> insertLayout(3, newgameLayoutTS, 2);
    mainLayoutTS -> insertLayout(4, tutorialLayoutTS, 2);
    mainLayoutTS -> insertStretch(5, 1);
    mainLayoutTS -> insertLayout(6, aboutLayoutTS, 2);
    mainLayoutTS -> insertLayout(7, quitLayoutTS, 2);
    mainLayoutTS -> insertStretch(8, 1);

    mainLayout = new QVBoxLayout(ui->centralwidget);
    mainLayout -> insertWidget(0, TB);
    mainLayout -> insertLayout(1, mainLayoutTS);
    mainLayout -> insertWidget(2, bottomGripTS);
    mainLayout -> setContentsMargins(0, 0, 0, 0);

    //functionalities
    connect(newgameButtonTS, &QPushButton::clicked, this, &MainWindow::transitionToSaveScreen);
    connect(tutorialButtonTS, &QPushButton::clicked, this, &MainWindow::showTutorialSection);
    connect(quitButtonTS, &QPushButton::clicked, this, &MainWindow::close);

    connect(minimiseButtonTB, &QPushButton::clicked, this, &MainWindow::showMinimized);
    connect(maximiseButtonTB, &QPushButton::clicked, this, &MainWindow::showMaximisedWindow);
    connect(exitButtonTB, &QPushButton::clicked, this, &MainWindow::close);
}
void MainWindow::setStyleTitleScreen()
{
    //background
    ui->centralwidget->setStyleSheet("#centralwidget {"
                                     "border-image: url(:/images/resources/Other/background.png) 0 0 0 0 stretch stretch;"
                                     "}");
    TB -> setStyleSheet("background-color: rgb(84,94,106);");

    //title label
    QString titleLabelTSStyle = "QLabel {"
                                "color: rgb(254,220,105);"
                                "border-radius: 20px;"
                                "margin-left: 80px;"
                                "margin-right: 80px;"
                                "margin-top: 40px;"
                                "font-size: 60px;"
                                "}";
    QString titleWidgetStyle = "QWidget {"
                               "border-image: url(:/images/resources/Other/TitleScreenBackground.png) 0 0 0 0 stretch stretch;"
                               "margin-left: 80px;"
                               "margin-right: 80px;"
                               "margin-top: 40px;"
                               "border-radius: 20px;"
                               "}";
    titleLabelTS -> setStyleSheet(titleLabelTSStyle);
    titleWidgetTS -> setStyleSheet(titleWidgetStyle);

    //buttons
    QString disabledButtons = "QPushButton {"
                              "background-color: rgb(84,94,106);"
                              "color: #B8BF33;"
                              "font-size: 16px;"
                              "border-style: solid;"
                              "border-radius: 4px;"
                              "border-color: rgb(40,60,69);"
                              "border-width: 2px;"
                              "}";
    QString enabledButtons = "QPushButton {"
                             "background-color: rgb(40,60,69);"
                             "color: rgb(254,220,105);"
                             "font-size: 16px;"
                             "border-style: solid;"
                             "border-radius: 4px;"
                             "border-color: rgb(11,29,41);"
                             "border-width: 2px;"
                             "}"
                             "QPushButton:hover {"
                             "background-color: rgb(11,29,41);"
                             "}";
    if (saveSettings.contains("CB") == false)
    {
        continueButtonTS -> setEnabled(false);
        continueButtonTS -> setStyleSheet(disabledButtons);
    }
    else
    {
        continueButtonTS -> setEnabled(true);
        continueButtonTS -> setStyleSheet(enabledButtons);
        connect(continueButtonTS, &QPushButton::clicked, this, [this]() { userWantsToContinue(saveSettings.value("CB").toInt(nullptr)); });
    }

    newgameButtonTS -> setStyleSheet(enabledButtons);
    tutorialButtonTS -> setStyleSheet(enabledButtons);
    aboutButtonTS -> setStyleSheet(enabledButtons);
    quitButtonTS -> setStyleSheet(enabledButtons);

    QString buttonTBStyle = "QPushButton {"
                            "color: white;"
                            "background-color: rgb(84,94,106);"
                            "border-style: solid;"
                            "}"
                            "QPushButton:hover {"
                            "background-color: rgb(110, 120, 135);"
                            "}";

    minimiseButtonTB -> setStyleSheet(buttonTBStyle);
    maximiseButtonTB -> setStyleSheet(buttonTBStyle);
    exitButtonTB -> setStyleSheet("QPushButton {"
                                  "color: white;"
                                  "background-color: rgb(84,94,106);"
                                  "border-style: solid;"
                                  "}"
                                  "QPushButton:hover {"
                                  "background-color: red;"
                                  "}");

    QString titleLabelTBStyle = "color: white;";
    titleLabelTB -> setStyleSheet(titleLabelTBStyle);
}
void MainWindow::removeLayoutTitleScreen()
{
    delete continueButtonTS;
    delete newgameButtonTS;
    delete tutorialButtonTS;
    delete aboutButtonTS;
    delete quitButtonTS;

    delete titleWidgetTS;

    delete continueLayoutTS;
    delete newgameLayoutTS;
    delete tutorialLayoutTS;
    delete aboutLayoutTS;
    delete quitLayoutTS;

    delete mainLayoutTS;
}

void MainWindow::showTutorialSection()
{
    tutorialScreen = new Tutorial();
    tutorialScreen -> setModal(true);
    tutorialScreen -> show();
}
void MainWindow::showMaximisedWindow()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeo = screen->availableGeometry();
    int height = screenGeo.height();
    int width = screenGeo.width();
    int x = (width - 900) / 2;
    setGeometry(x, 0, 900, height);
}

void MainWindow::transitionToSaveScreen()
{
    removeLayoutTitleScreen();
    setLayoutSaveScreen();
    setStyleSaveScreen();
}

void MainWindow::setLayoutSaveScreen()
{
    //font
    int id_newfont = QFontDatabase::addApplicationFont(":/images/resources/Other/Bohemian Typewriter.ttf");
    QString family_newfont = QFontDatabase::applicationFontFamilies(id_newfont).at(0);
    QFont Bohemian(family_newfont);
    //TITLE
    titleLabelSS = new QLabel("SAVE FILES");
    titleLabelSS -> setAlignment(Qt::AlignCenter);
    titleLabelSS -> setFont(Bohemian);

    lineTitleSS = new QLabel("LINE.png");
    lineTitleSS -> setMinimumHeight(20);
    lineTitleSS -> setPixmap(QPixmap(":/images/resources/Other/YellowLine.png"));
    lineTitleSS -> setScaledContents(true);
    lineTitleSS -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    infoTitleSS = new QLabel("Choose slot to play");
    infoTitleSS -> setFont(Bohemian);
    infoTitleSS -> setAlignment(Qt::AlignCenter);

    titleLayoutSS = new QVBoxLayout();
    titleLayoutSS -> insertWidget(0, titleLabelSS, 4);
    titleLayoutSS -> insertWidget(1, lineTitleSS, 3);
    titleLayoutSS -> insertWidget(2, infoTitleSS, 3);

    titleWidgetSS = new QWidget();
    titleWidgetSS -> setLayout(titleLayoutSS);

    //SAVES
    if (saveSettings.contains("Save1/Points") == true)
        points = saveSettings.value("Save1/Points").toDouble(nullptr);
    if (saveSettings.contains("Save1/Multi") == true)
        multiplier = saveSettings.value("Save1/Multi").toDouble(nullptr);
    if (saveSettings.contains("Save1/Hammers") == true)
        hammers = saveSettings.value("Save1/Hammers").toInt(nullptr);
    if (saveSettings.contains("Save1/Pickaxes") == true)
        pickaxes = saveSettings.value("Save1/Pickaxes").toInt(nullptr);
    if (saveSettings.contains("Save1/Children") == true)
        children = saveSettings.value("Save1/Children").toInt(nullptr);
    if (saveSettings.contains("Save1/Drills") == true)
        drills = saveSettings.value("Save1/Drills").toInt(nullptr);
    if (saveSettings.contains("Save1/Dynamite") == true)
        dynamite = saveSettings.value("Save1/Dynamite").toInt(nullptr);

    save1Widget = new ClickableWidget(nullptr, 1, QString::number(points), QString::number(multiplier), QString::number(hammers),
                                      QString::number(pickaxes), QString::number(children), QString::number(drills),
                                      QString::number(dynamite));
    save1Widget -> setMinimumHeight(280);

    points = 0.0;
    multiplier = 1.0;
    hammers = 0;
    pickaxes = 0;
    children = 0;
    drills = 0;
    dynamite = 0;

    if (saveSettings.contains("Save2/Points") == true)
        points = saveSettings.value("Save2/Points").toDouble(nullptr);
    if (saveSettings.contains("Save2/Multi") == true)
        multiplier = saveSettings.value("Save2/Multi").toDouble(nullptr);
    if (saveSettings.contains("Save2/Hammers") == true)
        hammers = saveSettings.value("Save2/Hammers").toInt(nullptr);
    if (saveSettings.contains("Save2/Pickaxes") == true)
        pickaxes = saveSettings.value("Save2/Pickaxes").toInt(nullptr);
    if (saveSettings.contains("Save2/Children") == true)
        children = saveSettings.value("Save2/Children").toInt(nullptr);
    if (saveSettings.contains("Save2/Drills") == true)
        drills = saveSettings.value("Save2/Drills").toInt(nullptr);
    if (saveSettings.contains("Save2/Dynamite") == true)
        dynamite = saveSettings.value("Save2/Dynamite").toInt(nullptr);

    save2Widget = new ClickableWidget(nullptr, 1, QString::number(points), QString::number(multiplier), QString::number(hammers),
                                      QString::number(pickaxes), QString::number(children), QString::number(drills),
                                      QString::number(dynamite));
    save2Widget -> setMinimumHeight(280);

    points = 0.0;
    multiplier = 1.0;
    hammers = 0;
    pickaxes = 0;
    children = 0;
    drills = 0;
    dynamite = 0;

    if (saveSettings.contains("Save3/Points") == true)
        points = saveSettings.value("Save3/Points").toDouble(nullptr);
    if (saveSettings.contains("Save3/Multi") == true)
        multiplier = saveSettings.value("Save3/Multi").toDouble(nullptr);
    if (saveSettings.contains("Save3/Hammers") == true)
        hammers = saveSettings.value("Save3/Hammers").toInt(nullptr);
    if (saveSettings.contains("Save3/Pickaxes") == true)
        pickaxes = saveSettings.value("Save3/Pickaxes").toInt(nullptr);
    if (saveSettings.contains("Save3/Children") == true)
        children = saveSettings.value("Save3/Children").toInt(nullptr);
    if (saveSettings.contains("Save3/Drills") == true)
        drills = saveSettings.value("Save3/Drills").toInt(nullptr);
    if (saveSettings.contains("Save3/Dynamite") == true)
        dynamite = saveSettings.value("Save3/Dynamite").toInt(nullptr);

    save3Widget = new ClickableWidget(nullptr, 3, QString::number(points), QString::number(multiplier), QString::number(hammers),
                                      QString::number(pickaxes), QString::number(children), QString::number(drills),
                                      QString::number(dynamite));
    save3Widget -> setMinimumHeight(280);

    points = 0.0;
    multiplier = 1.0;
    hammers = 0;
    pickaxes = 0;
    children = 0;
    drills = 0;
    dynamite = 0;

    if (saveSettings.contains("Save4/Points") == true)
        points = saveSettings.value("Save4/Points").toDouble(nullptr);
    if (saveSettings.contains("Save4/Multi") == true)
        multiplier = saveSettings.value("Save4/Multi").toDouble(nullptr);
    if (saveSettings.contains("Save4/Hammers") == true)
        hammers = saveSettings.value("Save4/Hammers").toInt(nullptr);
    if (saveSettings.contains("Save4/Pickaxes") == true)
        pickaxes = saveSettings.value("Save4/Pickaxes").toInt(nullptr);
    if (saveSettings.contains("Save4/Children") == true)
        children = saveSettings.value("Save4/Children").toInt(nullptr);
    if (saveSettings.contains("Save4/Drills") == true)
        drills = saveSettings.value("Save4/Drills").toInt(nullptr);
    if (saveSettings.contains("Save4/Dynamite") == true)
        dynamite = saveSettings.value("Save4/Dynamite").toInt(nullptr);

    save4Widget = new ClickableWidget(nullptr, 4, QString::number(points), QString::number(multiplier), QString::number(hammers),
                                      QString::number(pickaxes), QString::number(children), QString::number(drills),
                                      QString::number(dynamite));
    save4Widget -> setMinimumHeight(280);

    points = 0.0;
    multiplier = 1.0;
    hammers = 0;
    pickaxes = 0;
    children = 0;
    drills = 0;
    dynamite = 0;

    //LAYOUT
    saveMainBodyLayout = new QHBoxLayout();
    saveMainBodyLayout -> insertWidget(0, save1Widget, 1);
    saveMainBodyLayout -> insertWidget(1, save2Widget, 1);
    saveMainBodyLayout -> insertWidget(2, save3Widget, 1);
    saveMainBodyLayout -> insertWidget(3, save4Widget, 1);
    saveMainBodyLayout -> setContentsMargins(10, 0, 10, 0);

    mainLayoutSS = new QVBoxLayout();
    mainLayoutSS -> insertStretch(0, 1);
    mainLayoutSS -> insertWidget(1, titleWidgetSS, 2);
    mainLayoutSS -> insertStretch(2, 3);
    mainLayoutSS -> insertLayout(3, saveMainBodyLayout, 4);
    mainLayoutSS -> insertStretch(4, 2);

    mainLayout -> insertLayout(1, mainLayoutSS);

    //CONNECT
    connect(save1Widget, &ClickableWidget::clicked, this, [this]() { transitionToGameScreen(1); });
    connect(save2Widget, &ClickableWidget::clicked, this, [this]() { transitionToGameScreen(2); });
    connect(save3Widget, &ClickableWidget::clicked, this, [this]() { transitionToGameScreen(3); });
    connect(save4Widget, &ClickableWidget::clicked, this, [this]() { transitionToGameScreen(4); });
}
void MainWindow::setStyleSaveScreen()
{
    QString titleWidgetStyle = "border-image: url(:/images/resources/Other/TitleScreenBackground.png) 0 0 0 0 stretch stretch;"
                               "margin-left: 80px;"
                               "margin-right: 80px;"
                               "border-radius: 20px;";
    QString titleLabelStyle =  "color: rgb(254,220,105); font-size: 44px;";
    QString lineLabelStyle = "margin-left: 80px; margin-right: 80px;";
    QString infoLabelStyle = "color: rgb(254, 220, 105); font-size: 24px;";

    titleWidgetSS -> setStyleSheet(titleWidgetStyle);
    titleLabelSS -> setStyleSheet(titleLabelStyle);
    lineTitleSS -> setStyleSheet(lineLabelStyle);
    infoTitleSS -> setStyleSheet(infoLabelStyle);
}
void MainWindow::removeLayoutSaveScreen()
{
    delete titleLabelSS;
    delete lineTitleSS;
    delete infoTitleSS;

    delete titleLayoutSS;
    delete titleWidgetSS;

    delete save1Widget;
    delete save2Widget;
    delete save3Widget;
    delete save4Widget;

    delete saveMainBodyLayout;
    delete mainLayoutSS;
}

void MainWindow::transitionToGameScreen(int saveNr)
{
    removeLayoutSaveScreen();
    switch (saveNr)
    {
    case 1:
        cSave = 1;
        loadProgress(1);
        saveSettings.setValue("CB", 1);
        break;
    case 2:
        cSave = 2;
        loadProgress(2);
        saveSettings.setValue("CB", 2);
        break;
    case 3:
        cSave = 3;
        loadProgress(3);
        saveSettings.setValue("CB", 3);
        break;
    case 4:
        cSave = 4;
        loadProgress(4);
        saveSettings.setValue("CB", 4);
        break;
    }
    setLayoutGameScreen(cSave);
    setStyleGameScreen();
}
void MainWindow::userWantsToContinue(int nr)
{
    removeLayoutTitleScreen();
    switch (nr)
    {
    case 1:
        loadProgress(1);
        cSave = 1;
        break;
    case 2:
        loadProgress(2);
        cSave = 2;
        break;
    case 3:
        loadProgress(3);
        cSave = 3;
        break;
    case 4:
        loadProgress(4);
        cSave = 4;
        break;
    }
    setLayoutGameScreen(cSave);
    setStyleGameScreen();
}

void MainWindow::setLayoutGameScreen(int nr)
{
    int id_newfont = QFontDatabase::addApplicationFont(":/images/resources/Other/Bohemian Typewriter.ttf");
    QString family_newfont = QFontDatabase::applicationFontFamilies(id_newfont).at(0);
    QFont Bohemian(family_newfont);
    //ORE MINING LAYOUT
    scoreLabel = new QLabel(QString::number(points) + " $");
    scoreLabel -> setAlignment(Qt::AlignCenter);
    scoreLabel -> setFont(Bohemian);

    multiplierLabel = new QLabel("x " + QString::number(multiplier));
    multiplierLabel -> setAlignment(Qt::AlignCenter);
    multiplierLabel -> setFont(Bohemian);

    srand(time(nullptr));
    oreType = drawOreType();

    oreLabel = new ClickableLabel();
    switch (oreType)
    {
    case 0:
        oreLabel -> setPixmap(QPixmap(":/images/resources/Ores/selenite_ore.png"));
        break;
    case 1:
        oreLabel -> setPixmap(QPixmap(":/images/resources/Ores/onyx_ore.png"));
        break;
    case 2:
        oreLabel -> setPixmap(QPixmap(":/images/resources/Ores/amethyst_ore.png"));
        break;
    case 3:
        oreLabel -> setPixmap(QPixmap(":/images/resources/Ores/diamond_ore.png"));
        break;
    case 4:
        oreLabel -> setPixmap(QPixmap(":/images/resources/Ores/gold_ore.png"));
        break;
    case 5:
        oreLabel -> setPixmap(QPixmap(":/images/resources/Ores/ruby_ore.png"));
        break;
    case 6:
        oreLabel -> setPixmap(QPixmap(":/images/resources/Ores/jade_ore.png"));
        break;
    default:
        QMessageBox::critical(this, "ALERT", "UNABLE TO LOAD ORE ICON!");
        return;
    }
    oreLabel -> setScaledContents(true);
    oreLabel -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    miningLayout = new QVBoxLayout();
    miningLayout -> insertWidget(0, scoreLabel, 2);
    miningLayout -> insertWidget(1, multiplierLabel, 1);
    miningLayout -> insertStretch(2, 1);
    miningLayout -> insertWidget(3, oreLabel, 4);
    miningLayout -> insertStretch(4, 1);

    //INVENTORY LAYOUT
    inventoryLabel = new QLabel("INVENTORY");
    inventoryLabel -> setAlignment(Qt::AlignCenter);
    inventoryLabel -> setFont(Bohemian);

    inventoryWidget = new QWidget();

    numHamm = new QLabel(QString::number(hammers, 10));
    numHamm -> setAlignment(Qt::AlignCenter);
    numHamm -> setFont(Bohemian);

    hammIcon = new QLabel();
    hammIcon -> setPixmap(QPixmap(":/images/resources/ShopItems/hammer.png"));
    hammIcon -> setScaledContents(true);
    hammIcon -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ownedHammersLayout = new QHBoxLayout();
    ownedHammersLayout -> insertWidget(0, numHamm, 1);
    ownedHammersLayout -> insertWidget(1, hammIcon, 1);

    numPick = new QLabel(QString::number(pickaxes, 10));
    numPick -> setAlignment(Qt::AlignCenter);
    numPick -> setFont(Bohemian);

    pickIcon = new QLabel();
    pickIcon -> setPixmap(QPixmap(":/images/resources/ShopItems/pickaxe.png"));
    pickIcon -> setScaledContents(true);
    pickIcon -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ownedPickaxesLayout = new QHBoxLayout();
    ownedPickaxesLayout -> insertWidget(0, numPick, 1);
    ownedPickaxesLayout -> insertWidget(1, pickIcon, 1);

    numChild = new QLabel(QString::number(children, 10));
    numChild -> setAlignment(Qt::AlignCenter);
    numChild -> setFont(Bohemian);

    childIcon = new QLabel();
    childIcon -> setPixmap(QPixmap(":/images/resources/ShopItems/child.png"));
    childIcon -> setScaledContents(true);
    childIcon -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ownedChildrenLayout = new QHBoxLayout();
    ownedChildrenLayout -> insertWidget(0, numChild, 1);
    ownedChildrenLayout -> insertWidget(1, childIcon, 1);

    numDrill = new QLabel(QString::number(drills, 10));
    numDrill -> setAlignment(Qt::AlignCenter);
    numDrill -> setFont(Bohemian);

    drillIcon = new QLabel();
    drillIcon -> setPixmap(QPixmap(":/images/resources/ShopItems/drill.png"));
    drillIcon -> setScaledContents(true);
    drillIcon -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ownedDrillsLayout = new QHBoxLayout();
    ownedDrillsLayout -> insertWidget(0, numDrill, 1);
    ownedDrillsLayout -> insertWidget(1, drillIcon, 1);

    numDyn = new QLabel(QString::number(dynamite, 10));
    numDyn -> setAlignment(Qt::AlignCenter);
    numDyn -> setFont(Bohemian);

    dynIcon = new QLabel();
    dynIcon -> setPixmap(QPixmap(":/images/resources/ShopItems/dynamite.png"));
    dynIcon -> setScaledContents(true);
    dynIcon -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ownedDynamiteLayout = new QHBoxLayout();
    ownedDynamiteLayout -> insertWidget(0, numDyn, 1);
    ownedDynamiteLayout -> insertWidget(1, dynIcon, 1);

    invBodyLayout = new QVBoxLayout();
    invBodyLayout -> insertLayout(0, ownedHammersLayout, 1);
    invBodyLayout -> insertLayout(1, ownedPickaxesLayout, 1);
    invBodyLayout -> insertLayout(2, ownedChildrenLayout, 1);
    invBodyLayout -> insertLayout(3, ownedDrillsLayout, 1);
    invBodyLayout -> insertLayout(4, ownedDynamiteLayout, 1);

    inventoryWidget -> setLayout(invBodyLayout);

    inventoryLayout = new QVBoxLayout();
    inventoryLayout -> insertStretch(0, 1);
    inventoryLayout -> insertWidget(1, inventoryLabel, 2);
    inventoryLayout -> insertStretch(2, 1);
    inventoryLayout -> insertWidget(3, inventoryWidget, 5);
    inventoryLayout -> insertStretch(4, 1);

    //SHOP LAYOUT
    shopLabel = new QLabel("SHOP");
    shopLabel -> setAlignment(Qt::AlignCenter);
    shopLabel -> setFont(Bohemian);

    shopWidget = new QWidget();

    shopHammerWidget = new ShopItem(shopWidget, ":/images/resources/ShopItems/hammer.png", 1000.0 * hammers * hammers + 1000.0);
    shopPickaxeWidget = new ShopItem(shopWidget, ":/images/resources/ShopItems/pickaxe.png", 5000.0 * pickaxes * pickaxes + 5000.0);
    shopChildWidget = new ShopItem(shopWidget, ":/images/resources/ShopItems/child.png", 20000.0 * children * children + 20000.0);
    shopDrillWidget = new ShopItem(shopWidget, ":/images/resources/ShopItems/drill.png", 100000.0 * drills * drills + 100000.0);
    shopDynamiteWidget = new ShopItem(shopWidget, ":/images/resources/ShopItems/dynamite.png", 1000000.0 * dynamite * dynamite + 1000000.0);

    shop1Spacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    shop2Spacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    shop3Spacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    shop4Spacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    shop5Spacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

    column1Layout = new QVBoxLayout();
    column1Layout -> insertWidget(0, shopHammerWidget);
    column1Layout -> insertSpacerItem(1, shop1Spacer);
    column1Layout -> insertWidget(2, shopPickaxeWidget);
    column1Layout -> insertSpacerItem(3, shop2Spacer);
    column1Layout -> insertWidget(4, shopChildWidget);

    column2Layout = new QVBoxLayout();
    column2Layout -> insertSpacerItem(0, shop3Spacer);
    column2Layout -> insertWidget(1, shopDrillWidget);
    column2Layout -> insertSpacerItem(2, shop4Spacer);
    column2Layout -> insertWidget(3, shopDynamiteWidget);
    column2Layout -> insertSpacerItem(4, shop5Spacer);

    shopColumnsLayout = new QHBoxLayout();
    shopColumnsLayout -> insertLayout(0, column1Layout);
    shopColumnsLayout -> insertLayout(1, column2Layout);

    shopWidget -> setLayout(shopColumnsLayout);

    shopLayout = new QVBoxLayout();
    shopLayout -> insertStretch(0, 1);
    shopLayout -> insertWidget(1, shopLabel, 2);
    shopLayout -> insertStretch(2, 1);
    shopLayout -> insertWidget(3, shopWidget, 5);
    shopLayout -> insertStretch(4, 1);

    //MAIN LAYOUT
    gameMainBodyLayout = new QHBoxLayout();
    gameMainBodyLayout -> insertLayout(0, inventoryLayout, 3);
    gameMainBodyLayout -> insertStretch(1, 1);
    gameMainBodyLayout -> insertLayout(2, miningLayout, 5);
    gameMainBodyLayout -> insertStretch(3, 1);
    gameMainBodyLayout -> insertLayout(4, shopLayout, 3);
    gameMainBodyLayout -> setContentsMargins(5, 0, 5, 0);

    mainLayout -> insertLayout(1, gameMainBodyLayout);

    //FUNCTIONALITIES
    connect(oreLabel, &ClickableLabel::clicked, this, &MainWindow::userClickedOre);
    connect(shopHammerWidget, &ShopItem::clicked, this, &MainWindow::userWantsToBuyHammer);
    connect(shopPickaxeWidget, &ShopItem::clicked, this, &MainWindow::userWantsToBuyPickaxe);
    connect(shopChildWidget, &ShopItem::clicked, this, &MainWindow::userWantsToBuyChild);
    connect(shopDrillWidget, &ShopItem::clicked, this, &MainWindow::userWantsToBuyDrill);
    connect(shopDynamiteWidget, &ShopItem::clicked, this, &MainWindow::userWantsToBuyDynamite);

    disconnect(exitButtonTB, &QPushButton::clicked, this, &MainWindow::close);
    switch (nr)
    {
    case 1:
        connect(exitButtonTB, &QPushButton::clicked, this, [this]() { saveProgress(1); });
        break;
    case 2:
        connect(exitButtonTB, &QPushButton::clicked, this, [this]() { saveProgress(2); });
        break;
    case 3:
        connect(exitButtonTB, &QPushButton::clicked, this, [this]() { saveProgress(3); });
        break;
    case 4:
        connect(exitButtonTB, &QPushButton::clicked, this, [this]() { saveProgress(4); });
        break;
    }
    connect(exitButtonTB, &QPushButton::clicked, this, &MainWindow::close);
}
void MainWindow::setStyleGameScreen()
{
    ui->centralwidget->setStyleSheet("#centralwidget {"
                                     "border-image: url(:/images/resources/Other/MineBackground.png) 0 0 0 0 stretch stretch;"
                                     "}");

    QString pointsStyle = "QLabel {"
                          "color: rgb(254,220,105);"
                          "border-radius: 20px;"
                          "border-image: url(:/images/resources/Other/TitleScreenBackground.png) 0 0 0 0 stretch stretch;"
                          "font-size: 40px;"
                          "}";

    scoreLabel -> setStyleSheet(pointsStyle);

    QString invAndShopStyle = "QLabel {"
                              "color: rgb(254, 220, 105);"
                              "border-radius: 10px;"
                              "font-size: 26px;"
                              "background-color: rgb(40,60,69);"
                              "border-style: solid;"
                              "border-color: rgb(11,29,41);"
                              "border-width: 5px;"
                              "}";

    inventoryLabel -> setStyleSheet(invAndShopStyle);
    shopLabel -> setStyleSheet(invAndShopStyle);
    multiplierLabel -> setStyleSheet(invAndShopStyle);

    inventoryWidget -> setObjectName("inventoryWidget");
    shopWidget -> setObjectName("shopWidget");
    QString invWidgetStyle = "#inventoryWidget {"
                             "background-color: rgb(40,60,69);"
                             "color: rgb(254,220,105);"
                             "font-size: 16px;"
                             "border-style: solid;"
                             "border-radius: 10px;"
                             "border-color: rgb(11,29,41);"
                             "border-width: 5px;"
                             "}";
    QString shopWidgetStyle = "#shopWidget {"
                              "background-color: rgb(40,60,69);"
                              "color: rgb(254,220,105);"
                              "font-size: 16px;"
                              "border-style: solid;"
                              "border-radius: 10px;"
                              "border-color: rgb(11,29,41);"
                              "border-width: 5px;"
                              "}";
    inventoryWidget -> setStyleSheet(invWidgetStyle);
    shopWidget -> setStyleSheet(shopWidgetStyle);

    numHamm -> setStyleSheet("color: rgb(254,220,105); font-size: 24px;");
    numPick -> setStyleSheet("color: rgb(254,220,105); font-size: 24px;");
    numChild -> setStyleSheet("color: rgb(254,220,105); font-size: 24px;");
    numDrill -> setStyleSheet("color: rgb(254,220,105); font-size: 24px;");
    numDyn -> setStyleSheet("color: rgb(254,220,105); font-size: 24px;");
}
void MainWindow::removeLayoutGameScreen()
{

}

short MainWindow::drawOreType()
{
    short x = rand() % 100 + 1;
    if (x > 0 && x <= 20)
        return 0;
    else if (x > 20 && x <= 40)
        return 1;
    else if (x > 40 && x <= 60)
        return 2;
    else if (x > 60 && x <= 75)
        return 3;
    else if (x > 75 && x <= 90)
        return 4;
    else if (x > 90 && x <= 95)
        return 5;
    else if (x > 95 && x <= 100)
        return 6;
    else
        return -1;
}

void MainWindow::userClickedOre()
{
    switch(oreType)
    {
    case 0:
    case 1:
    case 2:
        points += multiplier * 100.0;
        break;
    case 3:
    case 4:
        points += multiplier * 150.0;
        break;
    case 5:
    case 6:
        points += multiplier * 500.0;
        break;
    default:
        QMessageBox::critical(this, "ERROR", "WRONG ORE");
        return;
        break;
    }
    scoreLabel -> setText(QString::number(points, 'g', 10) + " $");

    oreType = drawOreType();
    switch(oreType)
    {
    case 0:
        oreLabel -> setPixmap(QPixmap(":/images/resources/Ores/selenite_ore.png"));
        break;
    case 1:
        oreLabel -> setPixmap(QPixmap(":/images/resources/Ores/onyx_ore.png"));
        break;
    case 2:
        oreLabel -> setPixmap(QPixmap(":/images/resources/Ores/amethyst_ore.png"));
        break;
    case 3:
        oreLabel -> setPixmap(QPixmap(":/images/resources/Ores/diamond_ore.png"));
        break;
    case 4:
        oreLabel -> setPixmap(QPixmap(":/images/resources/Ores/gold_ore.png"));
        break;
    case 5:
        oreLabel -> setPixmap(QPixmap(":/images/resources/Ores/ruby_ore.png"));
        break;
    case 6:
        oreLabel -> setPixmap(QPixmap(":/images/resources/Ores/jade_ore.png"));
        break;
    default:
        QMessageBox::critical(this, "ALERT", "UNABLE TO LOAD ORE ICON!");
        return;
    }

    if (points > 100000000 && children == 0)
        goodEnding();
    else if (points > 100000000 && children != 0)
        badEnding();
}

void MainWindow::userWantsToBuyHammer()
{
    double price = 1000.0 * hammers * hammers + 1000.0;
    if (points >= price)
    {
        points -= price;
        hammers++;
        multiplier += 0.1;
        numHamm -> setText(QString::number(hammers, 10));
        scoreLabel -> setText(QString::number(points, 'g', 10) + " $");
        multiplierLabel -> setText("x " + QString::number(multiplier));
        price = 1000.0 * hammers * hammers + 1000.0;
        shopHammerWidget -> priceLabel -> setText(QString::number(price, 'g', 10) + " $");
    }
    else if (points < price)
    {
        return;
    }
}
void MainWindow::userWantsToBuyPickaxe()
{
    double price = 5000.0 * pickaxes * pickaxes + 5000.0;
    if (points >= price)
    {
        points -= price;
        pickaxes++;
        multiplier += 0.25;
        numPick -> setText(QString::number(pickaxes, 10));
        scoreLabel -> setText(QString::number(points, 'g', 10) + " $");
        multiplierLabel -> setText("x " + QString::number(multiplier));
        price = 5000.0 * pickaxes * pickaxes + 5000.0;
        shopPickaxeWidget -> priceLabel -> setText(QString::number(price, 'g', 10) + " $");
    }
    else if (points < price)
    {
        return;
    }
}
void MainWindow::userWantsToBuyChild()
{
    double price = 20000.0 * children * children + 20000.0;
    if (points >= price)
    {
        points -= price;
        children++;
        multiplier += 0.5;
        numChild -> setText(QString::number(children, 10));
        scoreLabel -> setText(QString::number(points, 'g', 10) + " $");
        multiplierLabel -> setText("x " + QString::number(multiplier));
        price = 20000.0 * children * children + 20000.0;
        shopChildWidget -> priceLabel -> setText(QString::number(price, 'g', 10) + " $");
    }
    else if (points < price)
    {
        return;
    }
}
void MainWindow::userWantsToBuyDrill()
{
    double price = 100000.0 * drills * drills + 100000.0;
    if (points >= price)
    {
        points -= price;
        drills++;
        multiplier += 2.0;
        numDrill -> setText(QString::number(drills, 10));
        scoreLabel -> setText(QString::number(points, 'g', 10) + " $");
        multiplierLabel -> setText("x " + QString::number(multiplier));
        price = 100000.0 * drills * drills + 100000.0;
        shopDrillWidget -> priceLabel -> setText(QString::number(price, 'g', 10) + " $");
    }
    else if (points < price)
    {
        return;
    }
}
void MainWindow::userWantsToBuyDynamite()
{
    double price = 1000000.0 * dynamite * dynamite + 1000000.0;
    if (points >= price)
    {
        points -= price;
        dynamite++;
        multiplier += 5.0;
        numDyn -> setText(QString::number(dynamite, 10));
        scoreLabel -> setText(QString::number(points, 'g', 10) + " $");
        multiplierLabel -> setText("x " + QString::number(multiplier));
        price = 1000000.0 * dynamite * dynamite + 1000000.0;
        shopDynamiteWidget -> priceLabel -> setText(QString::number(price, 'g', 10) + " $");
    }
    else if (points < price)
    {
        return;
    }
}

void MainWindow::goodEnding()
{

}
void MainWindow::badEnding()
{

}

void MainWindow::saveProgress(int nr)
{
     switch (nr)
     {
     case 1:
        saveSettings.beginGroup("Save1");
        saveSettings.setValue("Points", points);
        saveSettings.setValue("Multi", multiplier);
        saveSettings.setValue("Hammers", hammers);
        saveSettings.setValue("Pickaxes", pickaxes);
        saveSettings.setValue("Children", children);
        saveSettings.setValue("Drills", drills);
        saveSettings.setValue("Dynamite", dynamite);
        saveSettings.endGroup();
        break;
     case 2:
        saveSettings.beginGroup("Save2");
        saveSettings.setValue("Points", points);
        saveSettings.setValue("Multi", multiplier);
        saveSettings.setValue("Hammers", hammers);
        saveSettings.setValue("Pickaxes", pickaxes);
        saveSettings.setValue("Children", children);
        saveSettings.setValue("Drills", drills);
        saveSettings.setValue("Dynamite", dynamite);
        saveSettings.endGroup();
        break;
     case 3:
        saveSettings.beginGroup("Save3");
        saveSettings.setValue("Points", points);
        saveSettings.setValue("Multi", multiplier);
        saveSettings.setValue("Hammers", hammers);
        saveSettings.setValue("Pickaxes", pickaxes);
        saveSettings.setValue("Children", children);
        saveSettings.setValue("Drills", drills);
        saveSettings.setValue("Dynamite", dynamite);
        saveSettings.endGroup();
        break;
     case 4:
        saveSettings.beginGroup("Save4");
        saveSettings.setValue("Points", points);
        saveSettings.setValue("Multi", multiplier);
        saveSettings.setValue("Hammers", hammers);
        saveSettings.setValue("Pickaxes", pickaxes);
        saveSettings.setValue("Children", children);
        saveSettings.setValue("Drills", drills);
        saveSettings.setValue("Dynamite", dynamite);
        saveSettings.endGroup();
        break;
     default:
         QMessageBox::critical(this, "ERROR", "Something went wrong!");
         return;
         break;
     }
}
void MainWindow::loadProgress(int nr)
{
    switch (nr)
    {
    case 1:
        if (saveSettings.contains("Save1/Points") == true)
            points = saveSettings.value("Save1/Points").toDouble(nullptr);
        if (saveSettings.contains("Save1/Multi") == true)
            multiplier = saveSettings.value("Save1/Multi").toDouble(nullptr);
        if (saveSettings.contains("Save1/Hammers") == true)
            hammers = saveSettings.value("Save1/Hammers").toInt(nullptr);
        if (saveSettings.contains("Save1/Pickaxes") == true)
            pickaxes = saveSettings.value("Save1/Pickaxes").toInt(nullptr);
        if (saveSettings.contains("Save1/Children") == true)
            children = saveSettings.value("Save1/Children").toInt(nullptr);
        if (saveSettings.contains("Save1/Drills") == true)
            drills = saveSettings.value("Save1/Drills").toInt(nullptr);
        if (saveSettings.contains("Save1/Dynamite") == true)
            dynamite = saveSettings.value("Save1/Dynamite").toInt(nullptr);
        break;
    case 2:
        if (saveSettings.contains("Save2/Points") == true)
            points = saveSettings.value("Save2/Points").toDouble(nullptr);
        if (saveSettings.contains("Save2/Multi") == true)
            multiplier = saveSettings.value("Save2/Multi").toDouble(nullptr);
        if (saveSettings.contains("Save2/Hammers") == true)
            hammers = saveSettings.value("Save2/Hammers").toInt(nullptr);
        if (saveSettings.contains("Save2/Pickaxes") == true)
            pickaxes = saveSettings.value("Save2/Pickaxes").toInt(nullptr);
        if (saveSettings.contains("Save2/Children") == true)
            children = saveSettings.value("Save2/Children").toInt(nullptr);
        if (saveSettings.contains("Save2/Drills") == true)
            drills = saveSettings.value("Save2/Drills").toInt(nullptr);
        if (saveSettings.contains("Save2/Dynamite") == true)
            dynamite = saveSettings.value("Save2/Dynamite").toInt(nullptr);
        break;
    case 3:
        if (saveSettings.contains("Save3/Points") == true)
            points = saveSettings.value("Save3/Points").toDouble(nullptr);
        if (saveSettings.contains("Save3/Multi") == true)
            multiplier = saveSettings.value("Save3/Multi").toDouble(nullptr);
        if (saveSettings.contains("Save3/Hammers") == true)
            hammers = saveSettings.value("Save3/Hammers").toInt(nullptr);
        if (saveSettings.contains("Save3/Pickaxes") == true)
            pickaxes = saveSettings.value("Save3/Pickaxes").toInt(nullptr);
        if (saveSettings.contains("Save3/Children") == true)
            children = saveSettings.value("Save3/Children").toInt(nullptr);
        if (saveSettings.contains("Save3/Drills") == true)
            drills = saveSettings.value("Save3/Drills").toInt(nullptr);
        if (saveSettings.contains("Save3/Dynamite") == true)
            dynamite = saveSettings.value("Save3/Dynamite").toInt(nullptr);
        break;
    case 4:
        if (saveSettings.contains("Save4/Points") == true)
            points = saveSettings.value("Save4/Points").toDouble(nullptr);
        if (saveSettings.contains("Save4/Multi") == true)
            multiplier = saveSettings.value("Save4/Multi").toDouble(nullptr);
        if (saveSettings.contains("Save4/Hammers") == true)
            hammers = saveSettings.value("Save4/Hammers").toInt(nullptr);
        if (saveSettings.contains("Save4/Pickaxes") == true)
            pickaxes = saveSettings.value("Save4/Pickaxes").toInt(nullptr);
        if (saveSettings.contains("Save4/Children") == true)
            children = saveSettings.value("Save4/Children").toInt(nullptr);
        if (saveSettings.contains("Save4/Drills") == true)
            drills = saveSettings.value("Save4/Drills").toInt(nullptr);
        if (saveSettings.contains("Save4/Dynamite") == true)
            dynamite = saveSettings.value("Save4/Dynamite").toInt(nullptr);
        break;
    default:
        QMessageBox::critical(this, "ERROR", "Something went wrong!");
        return;
    }
}

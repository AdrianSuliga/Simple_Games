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

    int id_newfont = QFontDatabase::addApplicationFont(":/images/resources/Other/Bohemian Typewriter.ttf");
    QString family_newfont = QFontDatabase::applicationFontFamilies(id_newfont).at(0);
    QFont Bohemian(family_newfont);

    points = 0.0;
    multiplier = 1.0;
    hammers = 0;
    pickaxes = 0;
    children = 0;
    drills = 0;
    dynamite = 0;
    oreType = -1;

    setLayoutTitleScreen();
    checkContinueButton();
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
    connect(quitButtonTS, &QPushButton::clicked, this, &MainWindow::close);
    connect(newgameButtonTS, &QPushButton::clicked, this, &MainWindow::transitionToSaveScreen);

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

void MainWindow::showMaximisedWindow()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeo = screen->availableGeometry();
    int height = screenGeo.height();
    int width = screenGeo.width();
    int x = (width - 900) / 2;
    setGeometry(x, 0, 900, height);
}

void MainWindow::checkContinueButton()
{
    if ((didYouUseThisSave(":/saves/saves/Save_1.txt") == true) || (didYouUseThisSave(":/saves/saves/Save_2.txt") == true)
       || (didYouUseThisSave(":/saves/saves/Save_3.txt") == true) || (didYouUseThisSave(":/saves/saves/Save_4.txt") == true))
        continueButtonTS -> setEnabled(true);
    else
        continueButtonTS -> setEnabled(false);
}
bool MainWindow::didYouUseThisSave(QString path)
{
    QFile file(path);
    int nr = 1;
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream line(&file);
        while(!line.atEnd())
        {
            switch(nr)
            {
            case 1:
            {
                double saved_multi = line.readLine().toDouble(nullptr);
                if (saved_multi > 1.0001)
                    return true;
                break;
            }
            case 2:
            {
                double saved_points = line.readLine().toDouble(nullptr);
                if (saved_points > 0.0001)
                    return true;
                break;
            }
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            {
                int saved_bought_items = line.readLine().toInt(nullptr, 10);
                if (saved_bought_items != 0)
                    return true;
                break;
            }
            default:
                QMessageBox::critical(this, "TOO MANY LINES", "Tried to read too many lines");
                break;
            }
            nr++;
        }
        file.close();
    }
    else
        QMessageBox::critical(this, "FILE NOT FOUND", "File not found!");

    return false;
}

void MainWindow::transitionToSaveScreen()
{
    removeLayoutTitleScreen();
    setLayoutSaveScreen();
    setStyleSaveScreen();
}

void MainWindow::setLayoutSaveScreen()
{
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
    save1Widget = new ClickableWidget(nullptr, ":/saves/saves/Save_1.txt", 1);
    save1Widget -> setMinimumHeight(280);

    save2Widget = new ClickableWidget(nullptr, ":/saves/saves/Save_2.txt", 2);
    save2Widget -> setMinimumHeight(280);

    save3Widget = new ClickableWidget(nullptr, ":/saves/saves/Save_3.txt", 3);
    save3Widget -> setMinimumHeight(280);

    save4Widget = new ClickableWidget(nullptr, ":/saves/saves/Save_4.txt", 4);
    save4Widget -> setMinimumHeight(280);

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

void MainWindow::loadContentFromSaveFile(QString path)
{
    int counter = 1;
    QFile saveFile(path);
    if (saveFile.open(QIODevice::ReadOnly))
    {
        QTextStream textLine(&saveFile);
        while (!textLine.atEnd())
        {
            switch(counter)
            {
            case 1:
                multiplier = textLine.readLine().toDouble(nullptr);
                break;
            case 2:
                points = textLine.readLine().toDouble(nullptr);
                break;
            case 3:
                hammers = textLine.readLine().toInt(nullptr, 10);
                break;
            case 4:
                pickaxes = textLine.readLine().toInt(nullptr, 10);
                break;
            case 5:
                children = textLine.readLine().toInt(nullptr, 10);
                break;
            case 6:
                drills = textLine.readLine().toInt(nullptr, 10);
                break;
            case 7:
                dynamite = textLine.readLine().toInt(nullptr, 10);
                break;
            default:
                QMessageBox::critical(this, "ERROR", "Tried to read too many lines.");
                return;
                break;
            }
            counter++;
        }
        saveFile.close();
    }
    else
        QMessageBox::critical(this, "ERROR", "File not found!");
}

void MainWindow::transitionToGameScreen(int saveNr)
{
    removeLayoutSaveScreen();
    switch (saveNr)
    {
    case 1:
        loadContentFromSaveFile(":/saves/saves/Save_1.txt");
        break;
    case 2:
        loadContentFromSaveFile(":/saves/saves/Save_2.txt");
        break;
    case 3:
        loadContentFromSaveFile(":/saves/saves/Save_3.txt");
        break;
    case 4:
        loadContentFromSaveFile(":/saves/saves/Save_4.txt");
        break;
    }
    setLayoutGameScreen();
    setStyleGameScreen();
}

void MainWindow::setLayoutGameScreen()
{
    //ORE MINING LAYOUT
    scoreLabel = new QLabel(QString::number(points) + " $");
    scoreLabel -> setAlignment(Qt::AlignCenter);

    multiplierLabel = new QLabel("x " + QString::number(multiplier));
    multiplierLabel -> setAlignment(Qt::AlignCenter);

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

    inventoryWidget = new QWidget();

    numHamm = new QLabel(QString::number(hammers, 10));
    numHamm -> setAlignment(Qt::AlignCenter);

    hammIcon = new QLabel();
    hammIcon -> setPixmap(QPixmap(":/images/resources/ShopItems/hammer.png"));
    hammIcon -> setScaledContents(true);
    hammIcon -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ownedHammersLayout = new QHBoxLayout();
    ownedHammersLayout -> insertWidget(0, numHamm, 1);
    ownedHammersLayout -> insertWidget(1, hammIcon, 1);

    numPick = new QLabel(QString::number(pickaxes, 10));
    numPick -> setAlignment(Qt::AlignCenter);

    pickIcon = new QLabel();
    pickIcon -> setPixmap(QPixmap(":/images/resources/ShopItems/pickaxe.png"));
    pickIcon -> setScaledContents(true);
    pickIcon -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ownedPickaxesLayout = new QHBoxLayout();
    ownedPickaxesLayout -> insertWidget(0, numPick, 1);
    ownedPickaxesLayout -> insertWidget(1, pickIcon, 1);

    numChild = new QLabel(QString::number(children, 10));
    numChild -> setAlignment(Qt::AlignCenter);

    childIcon = new QLabel();
    childIcon -> setPixmap(QPixmap(":/images/resources/ShopItems/child.png"));
    childIcon -> setScaledContents(true);
    childIcon -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ownedChildrenLayout = new QHBoxLayout();
    ownedChildrenLayout -> insertWidget(0, numChild, 1);
    ownedChildrenLayout -> insertWidget(1, childIcon, 1);

    numDrill = new QLabel(QString::number(drills, 10));
    numDrill -> setAlignment(Qt::AlignCenter);

    drillIcon = new QLabel();
    drillIcon -> setPixmap(QPixmap(":/images/resources/ShopItems/drill.png"));
    drillIcon -> setScaledContents(true);
    drillIcon -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ownedDrillsLayout = new QHBoxLayout();
    ownedDrillsLayout -> insertWidget(0, numDrill, 1);
    ownedDrillsLayout -> insertWidget(1, drillIcon, 1);

    numDyn = new QLabel(QString::number(dynamite, 10));
    numDyn -> setAlignment(Qt::AlignCenter);

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

    shopWidget = new QWidget();

    shopHammerWidget = new ShopItem(shopWidget, ":/images/resources/ShopItems/hammer.png", 1000);
    shopPickaxeWidget = new ShopItem(shopWidget, ":/images/resources/ShopItems/pickaxe.png", 5000);
    shopChildWidget = new ShopItem(shopWidget, ":/images/resources/ShopItems/child.png", 20000);
    shopDrillWidget = new ShopItem(shopWidget, ":/images/resources/ShopItems/drill.png", 100000);
    shopDynamiteWidget = new ShopItem(shopWidget, ":/images/resources/ShopItems/dynamite.png", 1000000);

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

    connect(exitButtonTB, &QPushButton::clicked, this, &MainWindow::saveProgressToFile);
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

void MainWindow::saveProgressToFile()
{

}

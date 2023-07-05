#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QFontDatabase>
#include <QSizeGrip>
#include <QMessageBox>
#include <QDebug>
#include "clickablewidget.h"

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

    setLayoutTitleScreen();
    checkContinueButton();
    setStyleTitleScreen();

    setMinimumSize(400, 500);
    setMaximumSize(820, 820);
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

    mainLayout = new QVBoxLayout(ui->centralwidget);
    mainLayout -> insertWidget(0, TB);
    mainLayout -> insertWidget(1, titleWidgetTS, 2);
    mainLayout -> insertStretch(2, 1);
    mainLayout -> insertLayout(3, continueLayoutTS, 2);
    mainLayout -> insertLayout(4, newgameLayoutTS, 2);
    mainLayout -> insertLayout(5, tutorialLayoutTS, 2);
    mainLayout -> insertStretch(6, 1);
    mainLayout -> insertLayout(7, aboutLayoutTS, 2);
    mainLayout -> insertLayout(8, quitLayoutTS, 2);
    mainLayout -> insertStretch(9, 1);
    mainLayout -> insertWidget(10, bottomGripTS, 0);
    mainLayout -> setContentsMargins(0, 0, 0, 0);

    connect(quitButtonTS, SIGNAL(clicked()), this, SLOT(close()));
    connect(newgameButtonTS, SIGNAL(clicked()), this, SLOT(transitionToSaveScreen()));

    connect(minimiseButtonTB, SIGNAL(clicked()), this, SLOT(showMinimized()));
    connect(maximiseButtonTB, SIGNAL(clicked()), this, SLOT(showMaximisedWindow()));
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
                             "border-style:solid;"
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
}

void MainWindow::showMaximisedWindow() {setGeometry(0, 0, 820, 820);}

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

    mainLayout -> insertStretch(1, 1);
    mainLayout -> insertWidget(2, titleWidgetSS, 2);
    mainLayout -> insertStretch(3, 3);
    mainLayout -> insertLayout(4, saveMainBodyLayout, 4);
    mainLayout -> insertStretch(5, 2);
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

}

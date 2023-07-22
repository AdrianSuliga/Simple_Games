#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>
#include <QBoxLayout>
#include <QSizeGrip>
#include <QSettings>

#include <clickablewidget.h>
#include <shopitem.h>
#include <titlebarwidget.h>
#include <clickablelabel.h>
#include <tutorial.h>
#include <goodending.h>
#include <badending.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int hammers, pickaxes, children, drills, dynamite;
    QSettings saveSettings;
private slots:
    //FUNCTIONS CREATING TITLE SCREEN
    void setLayoutTitleScreen();
    void setStyleTitleScreen();
    void removeLayoutTitleScreen();
    //TITLE SCREEN FUNCIONALITIES FUNCTIONS
    void showMaximisedWindow();
    void showTutorialSection();
    void transitionToSaveScreen();
    void userWantsToContinue(int nr);
    //FUNCTIONS CREATING SAVE SCREEN
    void setLayoutSaveScreen();
    void setStyleSaveScreen();
    void removeLayoutSaveScreen();
    //SAVE SCREEN FUNCTIONALITIES FUNCTIONS
    void transitionToGameScreen(int saveNr);
    //FUNCTIONS CREATING GAME SCREEN
    void setLayoutGameScreen(int nr);
    void setStyleGameScreen();
    void removeLayoutGameScreen();
    //GAME SCREEN FUNCTIONALITIES FUNCTIONS
    short drawOreType();
    void userClickedOre();
    void userWantsToBuyHammer();
    void userWantsToBuyPickaxe();
    void userWantsToBuyChild();
    void userWantsToBuyDrill();
    void userWantsToBuyDynamite();
    void goodEnding();
    void badEnding();
    void saveProgress(int nr);
    void loadProgress(int nr);
    void removeProgress(int nr);

private:
    Ui::MainWindow *ui;
    //GAME VARIABLES
    double points, multiplier;
    short oreType, cSave;

    QVBoxLayout *mainLayout;
    GoodEnding *gE;
    BadEnding *bE;

    //TITLE BAR
    TitleBarWidget *TB;
    //TITLE SCREEN
    QPushButton *continueButtonTS, *newgameButtonTS, *tutorialButtonTS, *aboutButtonTS, *quitButtonTS;
    QLabel *titleLabelTS;
    QSpacerItem *lcSpacer, *rcSpacer, *lnSpacer, *rnSpacer, *ltSpacer, *rtSpacer, *laSpacer, *raSpacer, *lqSpacer, *rqSpacer;
    QVBoxLayout *mainLayoutTS, *titleLayoutTS;
    QHBoxLayout *continueLayoutTS, *newgameLayoutTS, *tutorialLayoutTS, *aboutLayoutTS, *quitLayoutTS, *bGLayout;
    QSizeGrip *brGripTS, *blGripTS;
    QWidget *bottomGripTS, *titleWidgetTS;
    Tutorial *tutorialScreen;
    //SAVE SCREEN
    QLabel *titleLabelSS, *lineTitleSS, *infoTitleSS;
    ClickableWidget *save1Widget, *save2Widget, *save3Widget, *save4Widget;
    QWidget *titleWidgetSS;
    QVBoxLayout *titleLayoutSS, *mainLayoutSS;
    QHBoxLayout *saveMainBodyLayout;
    //GAME SCREEN
    QLabel *scoreLabel, *multiplierLabel, *shopLabel,*inventoryLabel, *numPick, *numHamm, *numChild, *numDrill, *numDyn,
            *pickIcon, *hammIcon, *childIcon, *drillIcon, *dynIcon;
    ClickableLabel *oreLabel;
    QVBoxLayout *miningLayout, *inventoryLayout, *invBodyLayout, *shopLayout, *column1Layout, *column2Layout;
    QHBoxLayout *gameMainBodyLayout, *ownedPickaxesLayout, *ownedHammersLayout, *ownedChildrenLayout, *ownedDrillsLayout,
                *ownedDynamiteLayout, *shopColumnsLayout;
    QSpacerItem *shop1Spacer, *shop2Spacer, *shop3Spacer, *shop4Spacer, *shop5Spacer;
    QWidget *inventoryWidget, *shopWidget;
    ShopItem *shopHammerWidget, *shopPickaxeWidget, *shopChildWidget, *shopDrillWidget, *shopDynamiteWidget;
};
#endif // MAINWINDOW_H

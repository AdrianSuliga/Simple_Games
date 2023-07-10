#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>
#include <QBoxLayout>
#include <QSizeGrip>

#include <clickablewidget.h>
#include <shopitem.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    //FUNCTIONS CREATING TITLE SCREEN
    void setLayoutTitleScreen();
    void setStyleTitleScreen();
    void removeLayoutTitleScreen();
    //TITLE SCREEN FUNCIONALITIES FUNCTIONS
    void showMaximisedWindow();
    void checkContinueButton();
    bool didYouUseThisSave(QString path);
    void transitionToSaveScreen();
    //FUNCTIONS CREATING SAVE SCREEN
    void setLayoutSaveScreen();
    void setStyleSaveScreen();
    void removeLayoutSaveScreen();
    //SAVE SCREEN FUNCTIONALITIES FUNCTIONS
    void loadContentFromSaveFile(QString path);
    void transitionToGameScreen(int saveNr);
    //FUNCTIONS CREATING GAME SCREEN
    void setLayoutGameScreen();
    void setStyleGameScreen();
    void removeLayoutGameScreen();
    //GAME SCREEN FUNCTIONALITIES FUNCTIONS
    short drawOreType();

private:
    Ui::MainWindow *ui;
    //GAME VARIABLES
    double points, multiplier;
    short oreType;
    int hammers, pickaxes, children, drills, dynamite;
    QFont Bohemian;
    //TITLE BAR
    QLabel *iconLabelTB, *titleLabelTB;
    QSpacerItem *spacerTB;
    QPushButton *minimiseButtonTB, *maximiseButtonTB, *exitButtonTB;
    QWidget *TB;
    QHBoxLayout *mainLayoutTB;
    //TITLE SCREEN
    QPushButton *continueButtonTS, *newgameButtonTS, *tutorialButtonTS, *aboutButtonTS, *quitButtonTS;
    QLabel *titleLabelTS;
    QSpacerItem *lcSpacer, *rcSpacer, *lnSpacer, *rnSpacer, *ltSpacer, *rtSpacer, *laSpacer, *raSpacer, *lqSpacer, *rqSpacer;
    QVBoxLayout *mainLayout, *titleLayoutTS;
    QHBoxLayout *continueLayoutTS, *newgameLayoutTS, *tutorialLayoutTS, *aboutLayoutTS, *quitLayoutTS, *bGLayout;
    QSizeGrip *brGripTS, *blGripTS;
    QWidget *bottomGripTS, *titleWidgetTS;
    //SAVE SCREEN
    QLabel *titleLabelSS, *lineTitleSS, *infoTitleSS;
    ClickableWidget *save1Widget, *save2Widget, *save3Widget, *save4Widget;
    QWidget *titleWidgetSS;
    QVBoxLayout *titleLayoutSS;
    QHBoxLayout *saveMainBodyLayout;
    //GAME SCREEN
    QLabel *scoreLabel, *multiplierLabel, *shopLabel, *oreLabel, *inventoryLabel, *numPick, *numHamm, *numChild, *numDrill, *numDyn,
            *pickIcon, *hammIcon, *childIcon, *drillIcon, *dynIcon;
    QVBoxLayout *miningLayout, *inventoryLayout, *invBodyLayout, *shopLayout, *column1Layout, *column2Layout;
    QHBoxLayout *gameMainBodyLayout, *ownedPickaxesLayout, *ownedHammersLayout, *ownedChildrenLayout, *ownedDrillsLayout,
                *ownedDynamiteLayout, *shopColumnsLayout;
    QSpacerItem *shop1Spacer, *shop2Spacer, *shop3Spacer, *shop4Spacer, *shop5Spacer;
    QWidget *inventoryWidget, *shopWidget;
    ShopItem *shopHammerWidget, *shopPickaxeWidget, *shopChildWidget, *shopDrillWidget, *shopDynamiteWidget;
};
#endif // MAINWINDOW_H

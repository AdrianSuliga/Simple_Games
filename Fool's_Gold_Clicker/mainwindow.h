#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>
#include <QBoxLayout>
#include <QSizeGrip>

#include <clickablewidget.h>

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

private:
    Ui::MainWindow *ui;
    //GAME VARIABLES
    double points, multiplier;
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
    QLabel *titleLabelSS, *lineTitleSS, *infoTitleSS, *save1Label, *save2Label, *save3Label, *save4Label,
            *line1Label, *line2Label, *line3Label, *line4Label, *content1Label, *content2Label, *content3Label,
            *content4Label;
    QWidget *save1Widget, *save2Widget, *save3Widget, *save4Widget, *titleWidgetSS;
    QVBoxLayout *titleLayoutSS, *save1Layout, *save2Layout, *save3Layout, *save4Layout;
    QHBoxLayout *saveMainBodyLayout;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>
#include <QBoxLayout>
#include <QSizeGrip>

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
    void setLayoutTitleScreen();
    void setStyleTitleScreen();
    void removeLayoutTitleScreen();
    void checkContinueButton();

private:
    Ui::MainWindow *ui;
    //GAME VARIABLES
    double points, multiplier;
    int hammers, pickaxes, children, drills, dynamite;
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
    QVBoxLayout *mainLayoutTS;
    QHBoxLayout *continueLayoutTS, *newgameLayoutTS, *tutorialLayoutTS, *aboutLayoutTS, *quitLayoutTS, *bGLayout;
    QSizeGrip *brGrip, *blGrip;
    QWidget *bottomGrip;
    //CHOOSE SAVE SCREEN

};
#endif // MAINWINDOW_H

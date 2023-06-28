#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>
#include <QBoxLayout>

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

private:
    Ui::MainWindow *ui;
    //GAME VARIABLES
    double points, multiplier;
    int hammers, pickaxes, children, drills, dynamite;
    //TITLE SCREEN
    QPushButton *continueButton, *newgameButton, *tutorialButton, *aboutButton, *quitButton;
    QLabel *titleLabel;
    QSpacerItem *lcSpacer, *rcSpacer, *lnSpacer, *rnSpacer, *ltSpacer, *rtSpacer, *laSpacer, *raSpacer, *lqSpacer, *rqSpacer;
    QVBoxLayout *mainLayout;
    QHBoxLayout *continueLayout, *newgameLayout, *tutorialLayout, *aboutLayout, *quitLayout;
    //CHOOSE SAVE SCREEN

};
#endif // MAINWINDOW_H

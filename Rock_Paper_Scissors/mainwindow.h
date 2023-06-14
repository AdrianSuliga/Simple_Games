#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QSpacerItem>
#include <QLCDNumber>
#include <QLayout>

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
    //TITLE SCREEN FUNCTIONS
    void setLayoutForTitleScreen();
    void setStylesForTitleScreen();
    void removeLayoutForTitleScreen();

    //GAME SCREEN FUNCTIONS
    void setLayoutForGameScreen();
    void setStylesForGameScreen();
    void removeLayoutForGameScreen();

    //GAME MECHANICS FUNCTIONS
    void moveToGameScreen();
    bool saveEditedInput();
    void beginGame();
    void endGame();
    void user_chose_paper();
    void user_chose_rock();
    void user_chose_scissors();

private:
    Ui::MainWindow *ui;
    int numberOfRounds, counter;

    //TITLE SCREEN
    QPushButton *quitButton, *beginButton;
    QLabel *titleLabel, *rulesLabel, *roundsLabel, *rBeatsSLabel_Rock, *rBeatsSLabel_Beats, *rBeatsSLabel_Scissors,
            *sBeatsPLabel_Scissors, *sBeatsPLabel_Beats, *sBeatsPLabel_Paper, *pBeatsRLabel_Paper, *pBeatsRLabel_Beats,
            *pBeatsRLabel_Rock;
    QLineEdit *roundsEdit;
    QSpacerItem *hQuitSpacer, *hBetweenRulesAndBeginSpacer, *vBeginSpacer, *vBelowBeginButtonSpacer, *hLeftBeginSpacer, *hRightBeginSpacer;
    QVBoxLayout *mainLayout, *rulesLayout, *roundsAndBeginLayout;
    QHBoxLayout *quitLayout, *mainBodyLayout, *roundsLayout, *rBsLayout, *sBpLayout, *pBrLayout, *beginButtonLayout;

    //GAME SCREEN
    QVBoxLayout *pointsMainLayout, *gameInterfaceLayout, *rightSideOfWindowLayout;
    QHBoxLayout *iconsLayout, *gameBodyLayout, *mainLayoutGS;
    QPushButton *rockButton, *paperButton, *scissorsButton;
    QLabel *userScoreLabel, *compScoreLabel, *userLabel, *compLabel, *userChoiceLabel,
            *compChoiceLabel;
    QLCDNumber *userScoreLcd, *compScoreLcd;
};
#endif // MAINWINDOW_H

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

    void beginGame();
    bool saveEditedInput();
    void removeLayoutForTitleScreen();

    //GAME SCREEN FUNCTIONS
    void setLayoutForGameScreen();
    void setStylesForGameScreen();

private:
    Ui::MainWindow *ui;
    int numberOfRounds;

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
    QVBoxLayout *pointsMainLayout, *userPointsLayout, *compPointsLayout, *gameInterfaceLayout;
    QHBoxLayout *iconsLayout, *gameBodyLayout;
    QLabel *userScoreLabel, *compScoreLabel, *rockLabel, *paperLabel, *scissorsLabel, *userLabel, *compLabel, *userChoiceLabel,
            *compChoiceLabel, *loadingLabel;
    QLCDNumber *userScoreLcd, *compScoreLcd;
    QSpacerItem *vBetweenLcdSpacer, *hLeftSpacer, *hRightSpacer;
};
#endif // MAINWINDOW_H

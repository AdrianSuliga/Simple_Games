#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QSpacerItem>
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
    void setLayoutForTitleScreen();

private:
    Ui::MainWindow *ui;
    QPushButton *quitButton, *beginButton;
    QLabel *titleLabel, *rulesLabel, *roundsLabel, *rBeatsSLabel_Rock, *rBeatsSLabel_Beats, *rBeatsSLabel_Scissors,
            *sBeatsPLabel_Scissors, *sBeatsPLabel_Beats, *sBeatsPLabel_Paper, *pBeatsRLabel_Paper, *pBeatsRLabel_Beats,
            *pBeatsRLabel_Rock;
    QLineEdit *roundsEdit;
    QSpacerItem *hQuitSpacer, *hBetweenRulesAndBeginSpacer, *vBeginSpacer;
    QVBoxLayout *mainLayout, *rulesLayout, *roundsAndBeginLayout;
    QHBoxLayout *quitLayout, *mainBodyLayout, *roundsLayout, *rBsLayout, *sBpLayout, *pBrLayout;

};
#endif // MAINWINDOW_H

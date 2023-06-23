#ifndef END_GAME_H
#define END_GAME_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>
#include <QBoxLayout>

namespace Ui {
class End_Game;
}

class End_Game : public QDialog
{
    Q_OBJECT

public:
    explicit End_Game(QWidget *parent = nullptr, int result = -1);
    ~End_Game();
private slots:
    void setLayoutForVictoryGameScreen();
    void setLayoutForFailureGameScreen();
    void setLayoutForDrawGameScreen();
    void setStylesForEndGameScreen();
private:
    Ui::End_Game *ui;

    QLabel *iconLabel, *infoLabel;
    QPushButton *dialogButton;
    QSpacerItem *leftSpacer, *rightSpacer;
    QHBoxLayout *mainLayout, *buttonLayout;
    QVBoxLayout *bodyLayout;
};

#endif // END_GAME_H

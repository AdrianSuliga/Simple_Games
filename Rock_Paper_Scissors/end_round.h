#ifndef END_ROUND_H
#define END_ROUND_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>
#include <QBoxLayout>

namespace Ui {
class End_Round;
}

class End_Round : public QDialog
{
    Q_OBJECT

public:
    explicit End_Round(QWidget *parent = nullptr, int result = -1);
    ~End_Round();
private slots:
    void setLayoutForVictoryRoundScreen();
    void setLayoutForFailureRoundScreen();
    void setLayoutForDrawRoundScreen();
    void setStylesForEndRoundScreen();
private:
    Ui::End_Round *ui;

    QLabel *iconLabel, *infoLabel;
    QPushButton *dialogButton;
    QSpacerItem *leftSpacer, *rightSpacer;
    QHBoxLayout *mainLayout, *buttonLayout;
    QVBoxLayout *bodyLayout;
};

#endif // END_ROUND_H

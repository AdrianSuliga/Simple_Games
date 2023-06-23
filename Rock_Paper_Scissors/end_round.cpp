#include "end_round.h"
#include "ui_end_round.h"
#include <QMessageBox>

End_Round::End_Round(QWidget *parent, int result) :
    QDialog(parent),
    ui(new Ui::End_Round)
{
    ui->setupUi(this);

    setMinimumSize(400, 175);
    setMaximumSize(800, 350);
    switch(result)
    {
        case -1: QMessageBox::warning(this, "UNABLE TO END ROUND", "There is problem with ending this round!"); break;
        case 0: setLayoutForVictoryRoundScreen(); break;
        case 1: setLayoutForFailureRoundScreen(); break;
        case 2: setLayoutForDrawRoundScreen(); break;
    }
    setStylesForEndRoundScreen();
}

End_Round::~End_Round()
{
    emit accepted();
    delete ui;
}

void End_Round::setLayoutForVictoryRoundScreen()
{
    setWindowTitle("YOU WON THIS ROUND");

    iconLabel = new QLabel("MEDAL.png");
    iconLabel -> setPixmap(QPixmap(":/img/images/medal_VR.png"));
    iconLabel -> setScaledContents(true);
    iconLabel -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    infoLabel = new QLabel("Congratulations, you won this round!");
    infoLabel -> setWordWrap(true);
    infoLabel -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    dialogButton = new QPushButton("OK");
    dialogButton -> setMinimumSize(80, 30);
    leftSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    rightSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    buttonLayout = new QHBoxLayout();
    buttonLayout ->insertSpacerItem(0, leftSpacer);
    buttonLayout ->insertWidget(1, dialogButton);
    buttonLayout ->insertSpacerItem(2, rightSpacer);

    bodyLayout = new QVBoxLayout();
    bodyLayout ->insertWidget(0, infoLabel, 1);
    bodyLayout ->insertLayout(1, buttonLayout, 1);

    mainLayout = new QHBoxLayout();
    mainLayout -> insertWidget(0, iconLabel, 3);
    mainLayout -> insertLayout(1, bodyLayout, 4);

    setLayout(mainLayout);
    setAttribute(Qt::WA_DeleteOnClose);
    connect(dialogButton, SIGNAL(clicked()), this, SLOT(close()));
}

void End_Round::setLayoutForFailureRoundScreen()
{
    setWindowTitle("YOU LOST THIS ROUND");

    iconLabel = new QLabel("SKULL.png");
    iconLabel -> setPixmap(QPixmap(":/img/images/skull_LR.png"));
    iconLabel -> setScaledContents(true);
    iconLabel -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    infoLabel = new QLabel("Unfortunately, you lost this round!");
    infoLabel -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    infoLabel -> setWordWrap(true);

    dialogButton = new QPushButton("OK");
    dialogButton -> setMinimumSize(80, 30);
    leftSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    rightSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    buttonLayout = new QHBoxLayout();
    buttonLayout ->insertSpacerItem(0, leftSpacer);
    buttonLayout ->insertWidget(1, dialogButton);
    buttonLayout ->insertSpacerItem(2, rightSpacer);

    bodyLayout = new QVBoxLayout();
    bodyLayout ->insertWidget(0, infoLabel, 1);
    bodyLayout ->insertLayout(1, buttonLayout, 1);

    mainLayout = new QHBoxLayout();
    mainLayout -> insertWidget(0, iconLabel, 3);
    mainLayout -> insertLayout(1, bodyLayout, 4);

    setLayout(mainLayout);
    setAttribute(Qt::WA_DeleteOnClose);
    connect(dialogButton, SIGNAL(clicked()), this, SLOT(close()));
}

void End_Round::setLayoutForDrawRoundScreen()
{
    setWindowTitle("NOBODY WON THIS ROUND");

    iconLabel = new QLabel("DRAW.png");
    iconLabel -> setPixmap(QPixmap(":/img/images/draw_DR.png"));
    iconLabel -> setScaledContents(true);
    iconLabel -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    infoLabel = new QLabel("Nobody was able to won this round!");
    infoLabel -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    infoLabel -> setWordWrap(true);

    dialogButton = new QPushButton("OK");
    dialogButton -> setMinimumSize(80, 30);
    leftSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    rightSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    buttonLayout = new QHBoxLayout();
    buttonLayout ->insertSpacerItem(0, leftSpacer);
    buttonLayout ->insertWidget(1, dialogButton);
    buttonLayout ->insertSpacerItem(2, rightSpacer);

    bodyLayout = new QVBoxLayout();
    bodyLayout ->insertWidget(0, infoLabel, 1);
    bodyLayout ->insertLayout(1, buttonLayout, 1);

    mainLayout = new QHBoxLayout();
    mainLayout -> insertWidget(0, iconLabel, 3);
    mainLayout -> insertLayout(1, bodyLayout, 4);

    setLayout(mainLayout);
    setAttribute(Qt::WA_DeleteOnClose);
    connect(dialogButton, SIGNAL(clicked()), this, SLOT(close()));
}

void End_Round::setStylesForEndRoundScreen()
{
    setStyleSheet("background-color: rgb(11, 83, 81);");

    QString iconStyle = "background-color: rgb(0, 169, 165); border-radius: 20px; padding: 2px;";
    iconLabel -> setStyleSheet(iconStyle);

    QString dialogButtonStyle = "QPushButton { background-color: rgb(0, 169, 165);"
                                "font-size: 12px; color: white;"
                                "border-radius: 14px;"
                                "font-weight: bold;}"
                                "QPushButton:hover {"
                                "background-color: rgb(0, 143, 140);"
                                "}";
    dialogButton -> setStyleSheet(dialogButtonStyle);

    QString infoLabelStyle = "font-size: 16px; color: white; background-color: rgb(0, 169, 165);"
                             "border-style: solid; border-radius: 14px; font-weight: bold;";
    infoLabel -> setStyleSheet(infoLabelStyle);
}



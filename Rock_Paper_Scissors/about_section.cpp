#include "about_section.h"
#include "ui_about_section.h"

About_Section::About_Section(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About_Section)
{
    ui->setupUi(this);
    setLayoutForAboutSection();
    setStylesForAboutSection();
}

About_Section::~About_Section()
{
    delete ui;
}

void About_Section::setLayoutForAboutSection()
{
    okButton = new QPushButton("OK", this);
    okButton -> setMinimumSize(80, 30);

    titleLabel = new QLabel("ABOUT", this);
    titleLabel -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    infoLabel = new QLabel("All of the icons used in this game come from <a href=\"https://icons8.com\">icons8</a>", this);
    infoLabel -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    infoLabel -> setWordWrap(true);
    infoLabel -> setTextFormat(Qt::RichText);
    infoLabel -> setTextInteractionFlags(Qt::TextBrowserInteraction);
    infoLabel -> setOpenExternalLinks(true);

    leftSpacer = new QSpacerItem(80, 30, QSizePolicy::Expanding, QSizePolicy::Minimum);
    rightSpacer = new QSpacerItem(80, 30, QSizePolicy::Expanding, QSizePolicy::Minimum);

    buttonLayout = new QHBoxLayout();
    buttonLayout -> insertSpacerItem(0, leftSpacer);
    buttonLayout -> insertWidget(1, okButton);
    buttonLayout -> insertSpacerItem(2, rightSpacer);

    mainLayout = new QVBoxLayout();
    mainLayout -> insertWidget(0, titleLabel, 1);
    mainLayout -> insertStretch(1, 2);
    mainLayout -> insertWidget(2, infoLabel, 2);
    mainLayout -> insertStretch(3, 1);
    mainLayout -> insertLayout(4, buttonLayout, 2);
    mainLayout -> insertStretch(5, 1);

    setLayout(mainLayout);

    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    connect(okButton, SIGNAL(clicked()), this, SLOT(close()));
}
void About_Section::setStylesForAboutSection()
{
    QString okButtonStyle = "QPushButton { background-color: rgb(0, 169, 165);"
                            "font-size: 26px; color: white; padding: 3px;"
                            "border-radius: 14px; }"
                            "QPushButton:hover {"
                            "background-color: rgb(0, 143, 140);"
                            "}";

    okButton -> setStyleSheet(okButtonStyle);

    QString titleLabelStyle = "font-size: 40px; background-color: rgb(0, 169, 165); color: white; border-radius: 14px; padding: 2px;";

    titleLabel -> setStyleSheet(titleLabelStyle);

    QString infoLabelStyle = "font-size:20px; background-color: rgb(0, 169, 165); color: white; padding: 2px; border-radius: 14px;";

    infoLabel -> setStyleSheet(infoLabelStyle);

    setStyleSheet("background-color: rgb(11, 83, 81);");
}

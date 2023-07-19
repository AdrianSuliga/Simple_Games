#include "clickablewidget.h"
#include "qstyleoption.h"
#include <QSettings>
#include <QFontDatabase>
#include <QPainter>
#include <QFile>
#include <QTextStream>

ClickableWidget::ClickableWidget(QWidget* parent, int nr, QString pts, QString m,
                                 QString h, QString pi, QString c, QString dl, QString dy)
    : QWidget(parent)
{
    int id_newfont = QFontDatabase::addApplicationFont(":/images/resources/Other/Bohemian Typewriter.ttf");
    QString family_newfont = QFontDatabase::applicationFontFamilies(id_newfont).at(0);
    QFont Bohemian(family_newfont);

    points = pts;
    multi = m;
    ham = h;
    pick = pi;
    ch = c;
    dr = dl;
    dm = dy;

    setLayoutClickableWidget(nr, Bohemian);
    setStyleClickableWidget();
}

ClickableWidget::~ClickableWidget()
{
    delete titleLabel;
    delete lineLabel;
    delete pointsLabel;
    delete multiLabel;

    delete hammersLabel;
    delete hammersIcon;
    delete hammersLayout;

    delete pickaxesLabel;
    delete pickaxesIcon;
    delete pickaxesLayout;

    delete childrenLabel;
    delete childrenIcon;
    delete childrenLayout;

    delete drillLabel;
    delete drillIcon;
    delete drillsLayout;

    delete dynamiteLabel;
    delete dynamiteIcon;
    delete dynamiteLayout;

    delete layout();
}

void ClickableWidget::mousePressEvent(QMouseEvent *event) {emit clicked();}

void ClickableWidget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void ClickableWidget::setLayoutClickableWidget(int nr, QFont Bohemian)
{
    //TITLE
    titleLabel = new QLabel("");
    switch(nr)
    {
    case 1:
        titleLabel -> setText("SAVE 1");
        break;
    case 2:
        titleLabel -> setText("SAVE 2");
        break;
    case 3:
        titleLabel -> setText("SAVE 3");
        break;
    case 4:
        titleLabel -> setText("SAVE 4");
        break;
    }
    titleLabel -> setAlignment(Qt::AlignCenter);
    titleLabel -> setFont(Bohemian);

    //YELLOW LINE
    lineLabel = new QLabel("LINE.png");
    lineLabel -> setPixmap(QPixmap(":/images/resources/Other/YellowLine.png"));
    lineLabel -> setMinimumHeight(20);
    lineLabel -> setScaledContents(true);
    lineLabel -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    //CONTENT
    int iconMinSize = 25;
    pointsLabel = new QLabel(points + " $");
    pointsLabel -> setMinimumHeight(30);

    multiLabel = new QLabel("x " + multi);
    multiLabel -> setMinimumHeight(30);

    pickaxesLabel = new QLabel(pick);
    pickaxesIcon = new QLabel("PICKAXE.png");
    pickaxesIcon -> setPixmap(QPixmap(":/images/resources/ShopItems/pickaxe.png"));
    pickaxesIcon -> setScaledContents(true);
    pickaxesIcon -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    pickaxesIcon -> setMinimumSize(iconMinSize, iconMinSize);
    pickaxesSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    pickaxesLayout = new QHBoxLayout();
    pickaxesLayout -> insertWidget(0, pickaxesLabel);
    pickaxesLayout -> insertWidget(1, pickaxesIcon);
    pickaxesLayout -> insertSpacerItem(2, pickaxesSpacer);

    hammersLabel = new QLabel(ham);
    hammersIcon = new QLabel("HAMMER.png");
    hammersIcon -> setPixmap(QPixmap(":/images/resources/ShopItems/hammer.png"));
    hammersIcon -> setScaledContents(true);
    hammersIcon -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    hammersIcon -> setMinimumSize(iconMinSize, iconMinSize);
    hammersSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hammersLayout = new QHBoxLayout();
    hammersLayout -> insertWidget(0, hammersLabel);
    hammersLayout -> insertWidget(1, hammersIcon);
    hammersLayout -> insertSpacerItem(2, hammersSpacer);

    childrenLabel = new QLabel(ch);
    childrenIcon = new QLabel("CHILD.png");
    childrenIcon -> setPixmap(QPixmap(":/images/resources/ShopItems/child.png"));
    childrenIcon -> setScaledContents(true);
    childrenIcon -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    childrenIcon -> setMinimumSize(iconMinSize, iconMinSize);
    childrenSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    childrenLayout = new QHBoxLayout();
    childrenLayout -> insertWidget(0, childrenLabel);
    childrenLayout -> insertWidget(1, childrenIcon);
    childrenLayout -> insertSpacerItem(2, childrenSpacer);

    drillLabel = new QLabel(dr);
    drillIcon = new QLabel("DRILL.png");
    drillIcon -> setPixmap(QPixmap(":/images/resources/ShopItems/drill.png"));
    drillIcon -> setScaledContents(true);
    drillIcon -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    drillIcon -> setMinimumSize(iconMinSize, iconMinSize);
    drillSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    drillsLayout = new QHBoxLayout();
    drillsLayout -> insertWidget(0, drillLabel);
    drillsLayout -> insertWidget(1, drillIcon);
    drillsLayout -> insertSpacerItem(2, drillSpacer);

    dynamiteLabel = new QLabel(dm);
    dynamiteIcon = new QLabel("DYNAMITE.png");
    dynamiteIcon -> setPixmap(QPixmap(":/images/resources/ShopItems/dynamite.png"));
    dynamiteIcon -> setScaledContents(true);
    dynamiteIcon -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    dynamiteIcon -> setMinimumSize(iconMinSize, iconMinSize);
    dynamiteSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    dynamiteLayout = new QHBoxLayout();
    dynamiteLayout -> insertWidget(0, dynamiteLabel);
    dynamiteLayout -> insertWidget(1, dynamiteIcon);
    dynamiteLayout -> insertSpacerItem(2, dynamiteSpacer);

    mainLayout = new QVBoxLayout();
    mainLayout -> insertWidget(0, titleLabel, 2);
    mainLayout -> insertWidget(1, lineLabel, 1);
    mainLayout -> insertWidget(2, pointsLabel, 1);
    mainLayout -> insertWidget(3, multiLabel, 1);
    mainLayout -> insertLayout(4, hammersLayout, 1);
    mainLayout -> insertLayout(5, pickaxesLayout, 1);
    mainLayout -> insertLayout(6, childrenLayout, 1);
    mainLayout -> insertLayout(7, drillsLayout, 1);
    mainLayout -> insertLayout(8, dynamiteLayout, 1);
    mainLayout -> insertSpacing(9, 5);
    mainLayout -> setSpacing(10);
    this->setLayout(mainLayout);
}

void ClickableWidget::setStyleClickableWidget()
{
    QString saveWidgetStyle = "ClickableWidget {"
                              "border-image: url(:/images/resources/Other/TitleScreenBackground.png) 0 0 0 0 stretch stretch;"
                              "border-radius: 20px;"
                              "}"
                              "ClickableWidget:hover {"
                              "border-image: url(:/images/resources/Other/HoverBackground.png) 0 0 0 0 stretch stretch;"
                              "}"
                              "QLabel {"
                              "font-size: 25px;"
                              "color: rgb(254, 220, 105);"
                              "}";
    this->setStyleSheet(saveWidgetStyle);
}

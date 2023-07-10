#include "shopitem.h"
#include <QPainter>
#include <QStyleOption>
#include <QFontDatabase>

ShopItem::ShopItem(QWidget *parent, QString path, int price)
    : QWidget(parent)
{
    setLayoutItemShop(path, price);
    setStyleItemShop();
}

ShopItem::~ShopItem()
{
    delete iconLabel;
    delete priceLabel;
    delete this->layout();
}

void ShopItem::mousePressEvent(QMouseEvent *event) {emit clicked();}

void ShopItem::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void ShopItem::setLayoutItemShop(QString path, int price)
{
    iconLabel = new QLabel();
    iconLabel -> setPixmap(QPixmap(path));
    iconLabel -> setScaledContents(true);
    iconLabel -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    iconLabel -> setMinimumSize(50, 50);

    priceLabel = new QLabel(QString::number(price, 10));
    priceLabel -> setAlignment(Qt::AlignCenter);

    mlayout = new QVBoxLayout();
    mlayout -> insertWidget(0, iconLabel, 3);
    mlayout -> insertWidget(1, priceLabel, 1);
    this -> setLayout(mlayout);
}

void ShopItem::setStyleItemShop()
{
    int id_newfont = QFontDatabase::addApplicationFont(":/images/resources/Other/Bohemian Typewriter.ttf");
    QString family_newfont = QFontDatabase::applicationFontFamilies(id_newfont).at(0);
    QFont Bohemian(family_newfont);
}

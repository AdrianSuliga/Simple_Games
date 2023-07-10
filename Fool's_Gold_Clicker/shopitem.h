#ifndef SHOPITEM_H
#define SHOPITEM_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QFont>

class ShopItem : public QWidget
{
    Q_OBJECT
public:
    explicit ShopItem(QWidget* parent = nullptr, QString path = "", int price = 0);
    ~ShopItem();
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
private slots:
    void setLayoutItemShop(QString path, int price);
    void setStyleItemShop();
private:
    QLabel *iconLabel, *priceLabel;
    QVBoxLayout *mlayout;
    QFont Bohemian;
};

#endif // SHOPITEM_H

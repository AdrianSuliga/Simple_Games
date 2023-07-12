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
    explicit ShopItem(QWidget* parent = nullptr, QString path = "", double price = 0.0);
    ~ShopItem();
    QLabel *priceLabel;
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
private slots:
    void setLayoutItemShop(QString path, double price);
    void setStyleItemShop();
private:
    QLabel *iconLabel;
    QVBoxLayout *mlayout;
    QFont Bohemian;
};

#endif // SHOPITEM_H

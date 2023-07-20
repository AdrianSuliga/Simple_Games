#ifndef GOODENDING_H
#define GOODENDING_H

#include <QDialog>

namespace Ui {
class GoodEnding;
}

class GoodEnding : public QDialog
{
    Q_OBJECT

public:
    explicit GoodEnding(QWidget *parent = nullptr);
    ~GoodEnding();
signals:
    void clickedButton();
private slots:
    void on_pushButton_clicked();

private:
    Ui::GoodEnding *ui;
};

#endif // GOODENDING_H

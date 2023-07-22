#ifndef BADENDING_H
#define BADENDING_H

#include <QDialog>

namespace Ui {
class BadEnding;
}

class BadEnding : public QDialog
{
    Q_OBJECT

public:
    explicit BadEnding(QWidget *parent = nullptr);
    ~BadEnding();
signals:
    void buttonClicked();

private slots:
    void on_pushButton_clicked();

private:
    Ui::BadEnding *ui;
};

#endif // BADENDING_H

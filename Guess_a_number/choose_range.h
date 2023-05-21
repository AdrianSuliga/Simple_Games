#ifndef CHOOSE_RANGE_H
#define CHOOSE_RANGE_H

#include <QDialog>


namespace Ui {
class Choose_Range;
}

class Choose_Range : public QDialog
{
    Q_OBJECT

public:
    explicit Choose_Range(QWidget *parent = nullptr);
    ~Choose_Range();

private slots:

    void on_QuitToTitleButton_clicked();

private:
    Ui::Choose_Range *ui;

};

#endif // CHOOSE_RANGE_H

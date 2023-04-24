#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_BeginButton_clicked();

    void on_quitButton_clicked();

    void on_secondNumSlider_valueChanged(int value);

    void on_firstNumSlider_valueChanged(int value);

    void on_SaveRangeButton_clicked();

    int randomize_number(int fst, int snd);

    void on_yGuessButton_clicked();

private:
    Ui::MainWindow *ui;
    int first, second, random_number;
};
#endif // MAINWINDOW_H

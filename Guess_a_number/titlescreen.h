#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TitleScreen; }
QT_END_NAMESPACE

class TitleScreen : public QMainWindow
{
    Q_OBJECT

public:
    TitleScreen(QWidget *parent = nullptr);
    ~TitleScreen();

private slots:
    void on_QuitButton_clicked();

    void on_BeginGameButton_clicked();

private:
    Ui::TitleScreen *ui;
};
#endif // TITLESCREEN_H

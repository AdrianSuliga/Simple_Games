#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }              //creates namespaces which is used in MainWindow class
QT_END_NAMESPACE

class MainWindow : public QMainWindow           //MainWindow class inherits from QMainWindow
{
    Q_OBJECT                                    //This macro converts all characteristic for QT commands and words (namespace
                                                //declared above) into C++ language

public:
    MainWindow(QWidget *parent = nullptr);      //Constructor for MainWindow objects
    ~MainWindow();                              //Destructor for MainWindow objects

private slots:
    void on_editTextButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::MainWindow *ui;                         //Creates pointer which we're going to use to access widgets in our Main Window
};
#endif // MAINWINDOW_H

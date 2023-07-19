#include "mainwindow.h"

#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("NULL");
    QCoreApplication::setApplicationName("FOOL'S GOLD");
    MainWindow w;
    w.show();
    return a.exec();
}

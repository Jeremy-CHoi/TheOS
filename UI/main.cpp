#include "mainwindow.h"
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
//    MainWindow m;
//    m.show();
    return a.exec();
}

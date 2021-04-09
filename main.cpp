#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    if( w.parseArgs(argc, argv) == false )
    {
      exit(1);
    }
    w.show();
    return a.exec();
}

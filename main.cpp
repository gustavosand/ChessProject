#include "mainwindow.h"
#include "homewindow.h"

#include <QApplication>
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    HomeWindow h;
    h.show();
    h.showFullScreen();
    //unsigned c=97;
    //char n=c;
    //std::cout<<n<<std::endl;
    return a.exec();
}

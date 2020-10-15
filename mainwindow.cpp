#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->board->setStyleSheet("border-color: rgb(53, 39, 255);");



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    /*int a, b;
    a=qrand()%8;
    b=qrand()%8;*/



    Pawn *p = new Pawn('b', &(ui->board->sq[0][0]));
    Pawn *p2 = new Pawn('w', &(ui->board->sq[0][0]));

    //qDebug()<<a<<b<<"\n";
}

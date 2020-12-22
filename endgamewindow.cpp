#include "endgamewindow.h"
#include "ui_endgamewindow.h"

EndGameWindow::EndGameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EndGameWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

EndGameWindow::~EndGameWindow()
{
    delete ui;
}

void EndGameWindow::whiteVictory()
{
    ui->cB->hide();
    ui->cW->show();
    ui->white->setStyleSheet("border: 10px solid GREEN;background-image: url(:/new/img/img/whitePawn.png);");
    ui->black->setStyleSheet("border: 3px solid RED;background-image: url(:/new/img/img/blackPawn.png);");
    ui->vb->hide();
    ui->vw->show();
    this->setWindowModality(Qt::ApplicationModal);
    this->show();
}

void EndGameWindow::blackVictory()
{
    ui->cW->hide();
    ui->cB->show();
    ui->white->setStyleSheet("border: 3px solid RED;background-image: url(:/new/img/img/whitePawn.png);");
    ui->black->setStyleSheet("border: 10px solid GREEN;background-image: url(:/new/img/img/blackPawn.png);");
    ui->vw->hide();
    ui->vb->show();
    this->setWindowModality(Qt::ApplicationModal);
    this->show();
}




void EndGameWindow::on_menu_clicked()
{
    this->hide();
    this->setWindowModality(Qt::NonModal);
    this->show();
    this->hide();
    this->parentWidget()->parentWidget()->show();
    this->parentWidget()->close();
}

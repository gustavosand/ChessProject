#include "promotewindow.h"
#include "ui_promotewindow.h"

PromoteWindow::PromoteWindow(QWidget *parent, bool c, Square* pieceP) :
    QMainWindow(parent),
    square{pieceP},
    color{c},
    ui(new Ui::PromoteWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);


    //ui->pushButton->

    if(c==Piece::BLACK){
        QPixmap pixmap(":/new/img/img/rook_b.png");
        ui->rook->setIcon(QIcon(pixmap));
        ui->rook->setIconSize(pixmap.rect().size());

        QPixmap pixmap2(":/new/img/img/bishop_b.png");
        ui->bishop->setIcon(QIcon(pixmap2));
        ui->bishop->setIconSize(pixmap2.rect().size());

        QPixmap pixmap3(":/new/img/img/knight_b.png");
        ui->knight->setIcon(QIcon(pixmap3));
        ui->knight->setIconSize(pixmap3.rect().size());

        QPixmap pixmap4(":/new/img/img/queen_b.png");
        ui->queen->setIcon(QIcon(pixmap4));
        ui->queen->setIconSize(pixmap4.rect().size());

    }else{
        QPixmap pixmap(":/new/img/img/rook_w.png");
        ui->rook->setIcon(QIcon(pixmap));
        ui->rook->setIconSize(pixmap.rect().size());

        QPixmap pixmap2(":/new/img/img/bishop_w.png");
        ui->bishop->setIcon(QIcon(pixmap2));
        ui->bishop->setIconSize(pixmap2.rect().size());

        QPixmap pixmap3(":/new/img/img/knight_w.png");
        ui->knight->setIcon(QIcon(pixmap3));
        ui->knight->setIconSize(pixmap3.rect().size());

        QPixmap pixmap4(":/new/img/img/queen_w.png");
        ui->queen->setIcon(QIcon(pixmap4));
        ui->queen->setIconSize(pixmap4.rect().size());

    }

}

PromoteWindow::~PromoteWindow()
{
    delete ui;
}


void PromoteWindow::on_rook_clicked()
{
    Rook *t1 = new Rook(color, square);
    t1->show();
    this->close();
}

void PromoteWindow::on_knight_clicked()
{
    Knight *t1 = new Knight(color, square);
    t1->show();
    this->close();
}

void PromoteWindow::on_bishop_clicked()
{
    Bishop *t1 = new Bishop(color, square);
    t1->show();
    this->close();
}

void PromoteWindow::on_queen_clicked()
{
    Queen *t1 = new Queen(color, square);
    t1->show();
    this->close();
}

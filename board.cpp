#include "board.h"
#include "ui_board.h"

void Board::allUnpaint()
{
    for (unsigned i=0;i<8;i++) {
        for (unsigned j=0;j<8;j++) {
            sq[i][j]->setStyleSheet("");
        }
    }
}

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
    QGridLayout *grid=new QGridLayout;
    for (unsigned i=0;i<8;i++) {

        for (unsigned j=0;j<8;j++) {
            sq[i][j]=new Square(this, playerBlack, playerWhite);
            sq[i][j]->setStyleSheet("border-image: null;");
            sq[i][j]->setPositionOnBoard(i, j);
            sq[i][j]->generatePositionName();


            grid->addWidget(sq[i][j], static_cast<int>(i), static_cast<int>(j));

        }
    }
    ui->frame->setLayout(grid);
    checkAlert=ui->checkAlert;

}


Board::~Board()
{
    delete ui;
}


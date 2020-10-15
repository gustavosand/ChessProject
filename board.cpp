#include "board.h"
#include "ui_board.h"

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
    QGridLayout *grid=new QGridLayout;
    for (int i=0;i<8;i++) {

        for (int j=0;j<8;j++) {
            sq[i][j].setStyleSheet("border-image: null;");
            grid->addWidget(&sq[i][j], i, j);

            qDebug()<<i<<" "<<j<<"\n";
        }
    }


    ui->frame->setLayout(grid);
}

Board::~Board()
{
    delete ui;
}

#include "pawn.h"


Pawn::Pawn(char team, Square *parent):Piece(parent)
{
    if(team=='b') this->setPixmap(QPixmap(":/new/img/img/pown_b.png"));
    else this->setPixmap(QPixmap(":/new/img/img/pown_w.png"));

    this->move(0, 0);
    this->show();
    this->setAttribute(Qt::WA_DeleteOnClose);
}

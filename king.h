#ifndef KING_H
#define KING_H

#include "square.h"
#include "piece.h"
#include "mainwindow.h"

class King : public Piece
{
public:
    bool firstMove=true;
    explicit King(bool team, Square *parent = nullptr);
    bool isMovementValid(unsigned px, unsigned py, Piece* child) override;
    void captured() override;
    std::shared_ptr<QList<QWidget *>> getValidMovements() override;
    bool isChecked()override;
    bool isCastlingPosibble(Square* rookSquare);
    unsigned int cantAllValidMovements() override;
    void promotion() override{}

};

#endif // KING_H

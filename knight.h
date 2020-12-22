#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#include "square.h"
#include "mainwindow.h"

class Knight : public Piece
{
public:
    explicit Knight(bool team, Square *parent = nullptr);
    bool isMovementValid(unsigned px, unsigned py, Piece* child) override;
    void captured() override;
    std::shared_ptr<QList<QWidget *>> getValidMovements() override;
    bool isChecked() override;
    unsigned int cantAllValidMovements() override;
    void promotion() override{}
};

#endif // KNIGHT_H

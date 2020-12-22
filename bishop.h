#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include "square.h"
#include "mainwindow.h"


class Bishop : public Piece
{
public:

    explicit Bishop(bool team, Square *parent = nullptr);
    bool isMovementValid(unsigned px, unsigned py, Piece* child) override;
    void captured() override;
    std::shared_ptr<QList<QWidget *>> getValidMovements() override;
    bool isChecked() override;
    unsigned int cantAllValidMovements() override;
    void promotion() override{}

};

#endif // BISHOP_H

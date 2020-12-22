#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include "square.h"
#include "mainwindow.h"

class Queen : public Piece
{
public:
    explicit Queen(bool team, Square *parent = nullptr);
    bool isMovementValid(unsigned px, unsigned py, Piece* child) override;
    void captured() override;
    std::shared_ptr<QList<QWidget *>> getValidMovements() override;
    bool isChecked() override;
    unsigned int cantAllValidMovements() override;
    void promotion() override{}
};

#endif // QUEEN_H

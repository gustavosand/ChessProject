#ifndef ROOK_H
#define ROOK_H
#include "piece.h"
#include "square.h"
#include "mainwindow.h"
#include "board.h"
#include <memory>

class Rook : public Piece
{
public:
    explicit Rook(bool team, Square *parent = nullptr);

    bool firstMove=true;
    bool isMovementValid(unsigned px, unsigned py, Piece* child) override;
    void captured() override;
    std::shared_ptr<QList<QWidget *>> getValidMovements() override;
    bool isChecked() override;
    unsigned int cantAllValidMovements() override;
    void promotion() override{}

};

#endif // ROOK_H

#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include "square.h"
#include "mainwindow.h"
#include "promotewindow.h"
#include <memory>

class Pawn : public Piece
{
    Q_OBJECT
public:

    bool firstMove=true;


    explicit Pawn(bool team, Square *parent = nullptr);
    bool isMovementValid(unsigned px, unsigned py, Piece* child) override;
    void captured() override;
    std::shared_ptr<QList<QWidget *>> getValidMovements() override;
    bool isChecked() override;
    void promotion() override;
    unsigned int cantAllValidMovements() override;

};

#endif // PAWN_H

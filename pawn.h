#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include "square.h"

class Pawn : public Piece
{
    Q_OBJECT
public:
    explicit Pawn(char team, Square *parent = nullptr);

signals:

public slots:
};

#endif // PAWN_H

#ifndef PIECE_H
#define PIECE_H

#include <QLabel>
#include "square.h"
#include <QWidget>

class Piece : public QLabel
{
    Q_OBJECT
public:
    explicit Piece(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // PIECE_H

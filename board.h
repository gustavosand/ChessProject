/**
  * @file board.h
  * @version 1.0
  * @author Huarca Thea Eder
  * @title Clase Board
  * @brief Clase que representa un tablero
  */

#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QFrame>
#include <square.h>
#include <QDebug>
#include <QLabel>
#include <player.h>

namespace Ui {
class Board;
}

class Board : public QWidget
{
    Q_OBJECT

public:


    Square* sq[8][8];

    Player* playerWhite;
    Player* playerBlack;
    QLabel* checkAlert;

    /**
     * @brief allUnpaint: Metodo que limpia el fondo de las casillas del tablero
     */
    void allUnpaint();

    /**
     * @brief Board: Constructor explicito de la clase Board
     * @param parent para colocar el tablero
     */
    explicit Board(QWidget *parent = nullptr);
    ~Board();

private:
    Ui::Board *ui;
};

#endif // BOARD_H

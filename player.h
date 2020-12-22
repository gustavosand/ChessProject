/**
  * @file player.h
  * @version 1.0
  * @author Huarca Thea Eder
  * @title Clase Player
  * @brief Clase que representa a un jugador
  */

#ifndef PLAYER_H
#define PLAYER_H
//#include "king.h"
#include <QWidget>

class Player
{
public:
    QWidget* king;
    bool color;

    /**
     * @brief Player: Constructor de la clase Player
     * @param c Para el color de piezas del jugador
     */
    Player(bool c);
};

#endif // PLAYER_H

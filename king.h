/**
  * @file king.h
  * @version 1.0
  * @author Huarca Thea Eder
  * @title Clase King
  * @brief Clase que representa un Rey
  */

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
    /**
     * @brief isMovementValid: realiza un movimiento de pieza verificando su validez
     * @param px coordenada x en el tablero
     * @param py coordenada x en el tablero
     * @param child hijo de la casilla
     * @return bool Si se ha realizado el movimiento
     */
    bool isMovementValid(unsigned px, unsigned py, Piece* child) override;

    /**
     * @brief captured Captura de una pieza
     */
    void captured() override;

    /**
     * @brief getValidMovements: Metodo para obtener los movimientos validos de una pieza
     * @return QList con los moviminetos validos
     */
    std::shared_ptr<QList<QWidget *>> getValidMovements() override;

    /**
     * @brief isChecked: Confirma si el rey del equipo al que pertence la ficha esta en jaque
     * @return bool: Si ests en jaque
     */
    bool isChecked() override;

    /**
     * @brief promotion: Realiza un promocion en caso la pieza sea un peon
     */
    void promotion() override{}

    /**
     * @brief cantAllValidMovements Metodo que cuenta todos los moviminetos validos de todas las piezas de un equipo
     * @return cantidad de movimientos totales
     */
    unsigned int cantAllValidMovements() override;

    /**
     * @brief isCastlingPosibble: Metodo que verifica si es posible realizar enrroque
     * @param rookSquare Casilla destino de posible enrroque
     * @return bool si es posible el enrroque
     */
    bool isCastlingPosibble(Square* rookSquare);

};

#endif // KING_H

/**
  * @file bishop.h
  * @version 1.0
  * @author Huarca Thea Eder
  * @title Clase Bishop
  * @brief Clase que representa un Alfil
  */

#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include "square.h"
#include "mainwindow.h"


class Bishop : public Piece
{
public:    

    /**
     * @brief Bishop: Constructor explicicto de la clase Bishop
     * @param team Para el color de su equipo
     * @param parent Para colocar y mostrar la ficha
     */
    explicit Bishop(bool team, Square *parent = nullptr);

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

};

#endif // BISHOP_H

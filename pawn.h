/**
  * @file pawn.h
  * @version 1.0
  * @author Huarca Thea Eder
  * @title Clase Pawn
  * @brief Clase que representa un Peon
  */

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


    /**
     * @brief Pawn: Constructor explicicto de la clase Pawn
     * @param team Para el color de su equipo
     * @param parent Para colocar y mostrar la ficha
     */
    explicit Pawn(bool team, Square *parent = nullptr);

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
    void promotion() override;

    /**
     * @brief cantAllValidMovements Metodo que cuenta todos los moviminetos validos de todas las piezas de un equipo
     * @return cantidad de movimientos totales
     */
    unsigned int cantAllValidMovements() override;


};

#endif // PAWN_H

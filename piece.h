/**
  * @file piece.h
  * @version 1.0
  * @author Huarca Thea Eder
  * @title Clase Piece
  * @brief Clase abstracta que representa una Pieza
  */

#ifndef PIECE_H
#define PIECE_H

#include <QLabel>
#include <QWidget>
#include <QDebug>
#include <memory>
#include <QtMultimedia/QMediaPlayer>

class Piece : public QLabel
{
    Q_OBJECT
public:

    static const bool BLACK=0;
    static const bool WHITE=1;
    static QMediaPlayer SOUNDMOVE;
    static QMediaPlayer SOUNDCHECKMATE;
    static QLabel* CHECKALERT;

    static int captureWhiteX;
    static int captureWhiteY;
    static int captureBlackX;
    static int captureBlackY;

    bool color;
    char name;

    /**
     * @brief Constructor de la clase Piece
     * @param parent para colocar la pieza
     */
    explicit Piece(QWidget *parent = nullptr);

    /**
     * @brief Sobrecarga del operator <<
     * @param s Referencia un QDataStream para guardar un puntero
     * @param piece_ptr puntero del objeto a guardar
     * @return QDataStream& con el puntero agregado
     */
    friend QDataStream& operator<< (QDataStream & s, const Piece* piece_ptr);

    /**
     * @brief Sobrecarga del operator >>
     * @param s Referencia un QDataStream para obtener un puntero
     * @param piece_ptr puntero del objeto pieza para asignar
     * @return QDataStream& para lo que queda guardado
     */
    friend QDataStream& operator>> (QDataStream & s, Piece*& piece_ptr);

    /**
     * @brief isMovementValid: realiza un movimiento de pieza verificando su validez
     * @param px coordenada x en el tablero
     * @param py coordenada x en el tablero
     * @param child hijo de la casilla
     * @return bool Si se ha realizado el movimiento
     */
    virtual bool isMovementValid(unsigned px, unsigned py, Piece* child)=0;

    /**
     * @brief captured Captura de una pieza
     */
    virtual void captured()=0;

    /**
     * @brief getValidMovements: Metodo para obtener los movimientos validos du una pieza
     * @return QList con los moviminetos validos
     */
    virtual std::shared_ptr<QList<QWidget *>> getValidMovements()=0;

    /**
     * @brief paintValidMovements: Metodo que pinta las casillas destino validas
     */
    void paintValidMovements();

    /**
     * @brief unpaintValidMovements: Metodo que limpia el color de fondo de todas las casillas
     */
    void unpaintValidMovements();

    /**
     * @brief isChecked: Confirma si el rey del equipo al que pertence la ficha esta en jaque
     * @return bool: Si ests en jaque
     */
    virtual bool isChecked()=0;

    /**
     * @brief cantAllValidMovements: Metodo que cuenta todos los moviminetos validos de todas las piezas de un equipo
     */
    virtual unsigned cantAllValidMovements()=0;

    /**
     * @brief promotion: Realiza un promocion en caso la pieza sea un peon
     */
    virtual void promotion()=0;

    /**
     * @brief moveCaptured: Para determinar la posicion donde aparecera en caso la pieza sea capturada
     */
    void moveCaptured();




};

#endif // PIECE_H

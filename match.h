/**
  * @file match.h
  * @version 1.0
  * @author Huarca Thea Eder
  * @title Clase Match
  * @brief Clase que guarda varibles staticas necesarias para el juego
  */

#ifndef MATCH_H
#define MATCH_H
#include "piece.h"
#include "endgamewindow.h"
#include <QTimer>
#include <QPlainTextEdit>

class Match
{
public:
    static bool TURN;
    static EndGameWindow* ENDGAME;
    static QTimer* bTimer;
    static QTimer* wTimer;
    static QLabel* bTurn;
     static QLabel* wTurn;
    static bool TIMERMODE;
    static QPlainTextEdit* LOGGAME;
    static unsigned MOVEMENTNUMBER;
    static QChar MOVEMENTCAPTURE;
    Match();


};

#endif // MATCH_H

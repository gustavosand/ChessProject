#include "match.h"

Match::Match()
{

}

bool Match::TURN=Piece::WHITE;
EndGameWindow* Match::ENDGAME = nullptr;
QTimer* Match::bTimer=nullptr;
QTimer* Match::wTimer=nullptr;
QLabel* Match::bTurn=nullptr;
QLabel* Match::wTurn=nullptr;
bool Match::TIMERMODE=false;
unsigned Match::MOVEMENTNUMBER=1;
QPlainTextEdit* Match::LOGGAME=nullptr;
QChar Match::MOVEMENTCAPTURE=0;

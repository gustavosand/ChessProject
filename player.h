#ifndef PLAYER_H
#define PLAYER_H
//#include "king.h"
#include <QWidget>

class Player
{
public:
    QWidget* king;
    bool color;

    Player(bool c);
};

#endif // PLAYER_H

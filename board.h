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

    void allUnpaint();

    explicit Board(QWidget *parent = nullptr);
    ~Board();

private:
    Ui::Board *ui;
};

#endif // BOARD_H

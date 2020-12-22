#ifndef SQUARE_H
#define SQUARE_H
#include <QFrame>
#include "piece.h"
#include "match.h"
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>
#include <QPainter>
#include <QDebug>
#include <cmath>
#include "player.h"
#include <QtMultimedia/QMediaPlayer>
#include <QThread>
#include "endgamewindow.h"
#include <QScrollBar>


class Square : public QFrame
{
    Q_OBJECT
public:
    explicit Square(QWidget *parent = nullptr, Player* b=nullptr, Player* w=nullptr);
    unsigned posX;
    unsigned posY;
    char nameX;
    char nameY;
    Player* playerB;
    Player* playerW;

    void setPositionOnBoard(unsigned i, unsigned j);
    void generatePositionName();
    void unpaint();
    double euclidianDistance(Square* other);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;


};


class AlertThread : public QThread
{
    Q_OBJECT

protected:
    QLabel* f;
    void run(){
        f->show();
        this->sleep(1);
        f->hide();
    }
public:
    AlertThread(QLabel* l, QString mess){
        f=l;
        f->setText(mess);
    }
};

#endif // SQUARE_H

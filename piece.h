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

    explicit Piece(QWidget *parent = nullptr);

    friend QDataStream& operator<< (QDataStream & s, const Piece* piece_ptr);
    friend QDataStream& operator>> (QDataStream & s, Piece*& piece_ptr);
    virtual bool isMovementValid(unsigned px, unsigned py, Piece* child)=0;
    virtual void captured()=0;
    virtual std::shared_ptr<QList<QWidget *>> getValidMovements()=0;
    void paintValidMovements();
    void unpaintValidMovements();
    virtual bool isChecked()=0;
    virtual unsigned cantAllValidMovements()=0;
    virtual void promotion()=0;
    void moveCaptured();




};

#endif // PIECE_H

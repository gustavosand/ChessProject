#include "piece.h"

Piece::Piece(QWidget *parent) :
    QLabel(parent)
{

}

void Piece::paintValidMovements()
{
 std::shared_ptr<QList<QWidget *>> lista=getValidMovements();
 if(lista==nullptr)return;
 for(auto e:*lista){
     e->setStyleSheet("background-color:rgb(166, 235, 145);");
 }
}

void Piece::unpaintValidMovements()
{
    std::shared_ptr<QList<QWidget *>> lista=getValidMovements();
    if(lista==nullptr)return;
    for(auto e:*lista){
        e->setStyleSheet("");
    }
}

void Piece::moveCaptured()
{
    if(color==Piece::BLACK){
        if(Piece::captureBlackX>149){
            Piece::captureBlackX=0;
            Piece::captureBlackY+=40;
        }
        this->move(Piece::captureBlackX, Piece::captureBlackY);
        Piece::captureBlackX+=25;
    }else{
        if(Piece::captureWhiteX>149){
            Piece::captureWhiteX=0;
            Piece::captureWhiteY+=40;
        }
        this->move(Piece::captureWhiteX, Piece::captureWhiteY);
        Piece::captureWhiteX+=25;
    }
}

QDataStream& operator>>(QDataStream &s, Piece *&piece_ptr){
    qulonglong ptrval;
    s>>ptrval;
    piece_ptr = reinterpret_cast<Piece*>(ptrval);
    return s;
}

QDataStream& operator<<(QDataStream &s, const Piece *piece_ptr){
    qulonglong ptrval=reinterpret_cast<qulonglong>(piece_ptr);
    return s<<ptrval;
}

QMediaPlayer Piece::SOUNDMOVE=QMediaPlayer();
QMediaPlayer Piece::SOUNDCHECKMATE=QMediaPlayer();
QLabel* Piece::CHECKALERT=nullptr;


int Piece::captureWhiteX=0;
int Piece::captureWhiteY=0;
int Piece::captureBlackX=0;
int Piece::captureBlackY=0;

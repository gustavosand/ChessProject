#include "pawn.h"


Pawn::Pawn(bool team, Square *parent):
    Piece(parent)
{
    if(team==BLACK) this->setPixmap(QPixmap(":/new/img/img/pown_b.png"));
    else this->setPixmap(QPixmap(":/new/img/img/pown_w.png"));

    this->color=team;
    this->move(0, 0);
    this->show();
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->name='P';
}

bool Pawn::isMovementValid(unsigned px, unsigned py, Piece* child)
{

    auto movements=this->getValidMovements();
    for(auto m:*movements){
        auto square=static_cast<Square*>(m);
        if(square->posX==px && square->posY==py)    {
            Board* board=static_cast<Board*>(this->parentWidget()->parentWidget()->parentWidget()->parentWidget());
            if(child!=nullptr)  {
                child->captured();
                child->moveCaptured();
                Match::MOVEMENTCAPTURE='x';
            }
            if(firstMove==true){
                firstMove=false;
            }
            board->allUnpaint();
            return true;
        }
    }
    return false;


}

void Pawn::captured()
{
    auto s=static_cast<MainWindow*>(this->parentWidget()->parentWidget()->parentWidget()->parentWidget()->parentWidget()->parentWidget());
    if(color==BLACK)    {
        this->setParent(s->blackCaptured);

    }
    if(color==WHITE)    this->setParent(s->whiteCaptured);
    this->show();

}

std::shared_ptr<QList<QWidget *> > Pawn::getValidMovements()
{
    auto list=std::make_shared<QList<QWidget*>>();
    Board* board=static_cast<Board*>(this->parentWidget()->parentWidget()->parentWidget()->parentWidget());
    auto* parent=static_cast<Square*>(this->parentWidget());
    auto* square=board->sq;

//list->append(board->sq[parent->posX][y]);

    if(color==WHITE){
        //
        auto child=square[parent->posX-1][parent->posY];
        if (child->childAt(0, 0)==nullptr){
            list->append(child);
            if(firstMove==true && square[parent->posX-2][parent->posY]->childAt(0, 0)==nullptr){
              list->append(square[parent->posX-2][parent->posY]);
            }
        }

        if(parent->posY!=0){
            child=square[parent->posX-1][parent->posY-1];
            auto childPiece=static_cast<Piece*>(child->childAt(0, 0));
            if(childPiece!=nullptr && childPiece->color==BLACK){
                list->append(child);
            }
        }

        if(parent->posY!=7){
            child=square[parent->posX-1][parent->posY+1];
            auto childPiece=static_cast<Piece*>(child->childAt(0, 0));
            if(childPiece!=nullptr && childPiece->color==BLACK){
                list->append(child);
            }
        }


     //ficha NEgra

    }else{
        auto child=square[parent->posX+1][parent->posY];
        if (child->childAt(0, 0)==nullptr){
            list->append(child);
            if(firstMove==true && square[parent->posX+2][parent->posY]->childAt(0, 0)==nullptr ){
              list->append(square[parent->posX+2][parent->posY]);
            }
        }

        if(parent->posY!=7){
            child=square[parent->posX+1][parent->posY+1];
            auto childPiece=static_cast<Piece*>(child->childAt(0, 0));
            if(childPiece!=nullptr && childPiece->color==WHITE){
                list->append(child);
            }
        }

        if(parent->posY!=0){
            child=square[parent->posX+1][parent->posY-1];
            auto childPiece=static_cast<Piece*>(child->childAt(0, 0));
            if(childPiece!=nullptr && childPiece->color==WHITE){
                list->append(child);
            }
        }

    }


    //Verificy in case movement cause auto jaque
    if(Match::TURN==this->color){

        King* myKing=nullptr;

        if(board->playerBlack->color==this->color){
            myKing=static_cast<King*>(board->playerBlack->king);
        }else{
            myKing=static_cast<King*>(board->playerWhite->king);
        }

        for(int i=0;i<list->size();++i){
            auto squareP=static_cast<Square*>(list->at(i));
            //square guarda la posicion original

            auto child=static_cast<Piece*>(squareP->childAt(0,0));
            if(child!=nullptr)  {
                child->captured();
            }
            this->setParent(squareP);
            this->show();
            if(myKing->isChecked()){
                list->removeAt(i);
                i--;
            }
            this->setParent(parent);
            this->show();
            if(child!=nullptr)  {
                child->setParent(squareP);
                child->show();
            }
        }
    }
    //end verification

    return list;

}

bool Pawn::isChecked()
{
    Board* board=static_cast<Board*>(this->parentWidget()->parentWidget()->parentWidget()->parentWidget());
    King* otherKing=nullptr;

    if(this->color==BLACK){
        otherKing=static_cast<King*>(board->playerWhite->king);
    }else{
        otherKing=static_cast<King*>(board->playerBlack->king);
    }
    return otherKing->isChecked();
}

void Pawn::promotion()
{
    this->hide();
    auto principal=this->parentWidget()->parentWidget()->parentWidget()->parentWidget()->parentWidget()->parentWidget();
    auto parent=static_cast<Square*>(this->parentWidget());
    auto promote=new PromoteWindow(principal, this->color, parent);
    promote->setWindowModality(Qt::ApplicationModal);
    promote->show();
}

unsigned int Pawn::cantAllValidMovements()
{
    Board* board=static_cast<Board*>(this->parentWidget()->parentWidget()->parentWidget()->parentWidget());
    King* otherKing=nullptr;

    if(this->color==BLACK){
        otherKing=static_cast<King*>(board->playerWhite->king);
    }else{
        otherKing=static_cast<King*>(board->playerBlack->king);
    }
    return otherKing->cantAllValidMovements();
}


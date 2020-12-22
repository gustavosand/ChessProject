#include "knight.h"

Knight::Knight(bool team, Square *parent):
    Piece(parent)
{
    if(team==BLACK) this->setPixmap(QPixmap(":/new/img/img/knight_b.png"));
    else this->setPixmap(QPixmap(":/new/img/img/knight_w.png"));

    this->color=team;
    this->move(0, 0);
    this->show();
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->name='N';
}


bool Knight::isMovementValid(unsigned px, unsigned py, Piece* child){
    auto movements=this->getValidMovements();
    for(auto m:*movements){
        auto square=static_cast<Square*>(m);
        if(square->posX==px && square->posY==py)    {
            if(child!=nullptr)  {
                child->captured();
                child->moveCaptured();
                Match::MOVEMENTCAPTURE='x';
            }
            return true;
        }
    }
    return false;
}

void Knight::captured()
{
    auto s=static_cast<MainWindow*>(this->parentWidget()->parentWidget()->parentWidget()->parentWidget()->parentWidget()->parentWidget());
    if(color==BLACK)    this->setParent(s->blackCaptured);
    if(color==WHITE)    this->setParent(s->whiteCaptured);
    this->show();
}

std::shared_ptr<QList<QWidget *> > Knight::getValidMovements()
{
    auto list=std::make_shared<QList<QWidget*>>();
    Board* board=static_cast<Board*>(this->parentWidget()->parentWidget()->parentWidget()->parentWidget());
    auto* parent=static_cast<Square*>(this->parentWidget());
    auto* square=board->sq;

    //horizontal
    //derecha
    if(parent->posY<6){
        //up
        if(parent->posX>0){
            auto to=square[parent->posX-1][parent->posY+2];
            if(to->childAt(0,0)==nullptr){
                list->append(to);
            }else if(static_cast<Piece*>(to->childAt(0,0))->color != this->color){
                list->append(to);
            }
        }

        //down
        if(parent->posX<7){
            auto to=square[parent->posX+1][parent->posY+2];
            if(to->childAt(0,0)==nullptr){
                list->append(to);
            }else if(static_cast<Piece*>(to->childAt(0,0))->color != this->color){
                list->append(to);
            }
        }

    }

    //izquierda
    if(parent->posY>1){
        //up
        if(parent->posX>0){
            auto to=square[parent->posX-1][parent->posY-2];
            if(to->childAt(0,0)==nullptr){
                list->append(to);
            }else if(static_cast<Piece*>(to->childAt(0,0))->color != this->color){
                list->append(to);
            }
        }

        //down
        if(parent->posX<7){
            auto to=square[parent->posX+1][parent->posY-2];
            if(to->childAt(0,0)==nullptr){
                list->append(to);
            }else if(static_cast<Piece*>(to->childAt(0,0))->color != this->color){
                list->append(to);
            }
        }

    }

    //Vertical
    //arriba
    if(parent->posX>1){
        //left
        if(parent->posY>0){
            auto to=square[parent->posX-2][parent->posY-1];
            if(to->childAt(0,0)==nullptr){
                list->append(to);
            }else if(static_cast<Piece*>(to->childAt(0,0))->color != this->color){
                list->append(to);
            }
        }

        //right
        if(parent->posY<7){
            auto to=square[parent->posX-2][parent->posY+1];
            if(to->childAt(0,0)==nullptr){
                list->append(to);
            }else if(static_cast<Piece*>(to->childAt(0,0))->color != this->color){
                list->append(to);
            }
        }

    }

    //abajo
    if(parent->posX<6){
        //left
        if(parent->posY>0){
            auto to=square[parent->posX+2][parent->posY-1];
            if(to->childAt(0,0)==nullptr){
                list->append(to);
            }else if(static_cast<Piece*>(to->childAt(0,0))->color != this->color){
                list->append(to);
            }
        }

        //rigth
        if(parent->posY<7){
            auto to=square[parent->posX+2][parent->posY+1];
            if(to->childAt(0,0)==nullptr){
                list->append(to);
            }else if(static_cast<Piece*>(to->childAt(0,0))->color != this->color){
                list->append(to);
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

bool Knight::isChecked()
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

unsigned int Knight::cantAllValidMovements()
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

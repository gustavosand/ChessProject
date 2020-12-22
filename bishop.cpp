#include "bishop.h"

Bishop::Bishop(bool team, Square *parent):
    Piece(parent)
{
    if(team==BLACK) this->setPixmap(QPixmap(":/new/img/img/bishop_b.png"));
    else this->setPixmap(QPixmap(":/new/img/img/bishop_w.png"));

    this->color=team;
    this->move(0, 0);
    this->show();
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->name='B';
}

bool Bishop::isMovementValid(unsigned px, unsigned py, Piece* child){
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

void Bishop::captured()
{
    auto s=static_cast<MainWindow*>(this->parentWidget()->parentWidget()->parentWidget()->parentWidget()->parentWidget()->parentWidget());
    if(color==BLACK)    this->setParent(s->blackCaptured);
    if(color==WHITE)    this->setParent(s->whiteCaptured);
    this->show();
}

std::shared_ptr<QList<QWidget *> > Bishop::getValidMovements()
{
    auto list=std::make_shared<QList<QWidget*>>();
    Board* board=static_cast<Board*>(this->parentWidget()->parentWidget()->parentWidget()->parentWidget());
    auto* parent=static_cast<Square*>(this->parentWidget());
    auto* square=board->sq;

    //rigth-top
    if(parent->posX>0){
        for(int y=parent->posY+1, x=parent->posX-1;y<8 && x>=0;++y, --x){
            auto child=static_cast<Piece*>(square[x][y]->childAt(0, 0));
            if(child==nullptr){
                list->append(square[x][y]);
            }else if(child->color!=this->color){
                list->append(square[x][y]);
                break;
            }else{
                break;
            }
        }
    }

    //rigth-both
    for(unsigned y=parent->posY+1, x=parent->posX+1;y<8 && x<8;++y, ++x){
        auto child=static_cast<Piece*>(square[x][y]->childAt(0, 0));
        if(child==nullptr){
            list->append(square[x][y]);
        }else if(child->color!=this->color){
            list->append(square[x][y]);
            break;
        }else{
            break;
        }
    }

    //left-top
    if(parent->posX>0 && parent->posY>0){
        for(int y=parent->posY-1, x=parent->posX-1;y>=0 && x>=0;--y, --x){
            auto child=static_cast<Piece*>(square[x][y]->childAt(0, 0));
            if(child==nullptr){
                list->append(square[x][y]);
            }else if(child->color!=this->color){
                list->append(square[x][y]);
                break;
            }else{
                break;
            }
        }
    }


    //left-both
    if(parent->posY>0){
        for(int y=parent->posY-1, x=parent->posX+1;y>=0 && x<8;--y, ++x){
            auto child=static_cast<Piece*>(square[x][y]->childAt(0, 0));
            if(child==nullptr){
                list->append(square[x][y]);
            }else if(child->color!=this->color){
                list->append(square[x][y]);
                break;
            }else{
                break;
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

bool Bishop::isChecked()
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

unsigned int Bishop::cantAllValidMovements()
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

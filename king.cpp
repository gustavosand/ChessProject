#include "king.h"

King::King(bool team, Square *parent):
    Piece(parent)
{
    if(team==BLACK) this->setPixmap(QPixmap(":/new/img/img/king_b.png"));
    else this->setPixmap(QPixmap(":/new/img/img/king_w.png"));

    this->color=team;
    this->move(0, 0);
    this->show();
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->name='K';

}

bool King::isMovementValid(unsigned px, unsigned py, Piece* child){


    auto movements=this->getValidMovements();


    for(auto m:*movements){
        auto square=static_cast<Square*>(m);
        if(square->posX==px && square->posY==py)    {
            Board* board=static_cast<Board*>(this->parentWidget()->parentWidget()->parentWidget()->parentWidget());
            if(firstMove==true){
                if(py==6 || py==2){
                    auto* square=board->sq;
                    Piece* rook;
                    if(this->color==WHITE){
                        if(py==6){
                            rook=static_cast<Piece*>(square[7][7]->childAt(0,0));
                            rook->setParent(square[7][5]);
                        }else if(py==2){
                            rook=static_cast<Piece*>(square[7][0]->childAt(0,0));
                            rook->setParent(square[7][3]);
                        }
                    }else{
                        if(py==6){
                            rook=static_cast<Piece*>(square[0][7]->childAt(0,0));
                            rook->setParent(square[0][5]);
                        }else if(py==2){
                            rook=static_cast<Piece*>(square[0][0]->childAt(0,0));
                            rook->setParent(square[0][3]);
                        }
                    }
                    rook->show();
                }

                firstMove=false;
            }
            if(child!=nullptr)  {
                child->captured();
                child->moveCaptured();
                Match::MOVEMENTCAPTURE='x';
            }
            board->allUnpaint();
            return true;
        }
    }
    return false;
}

void King::captured()
{
    auto s=static_cast<MainWindow*>(this->parentWidget()->parentWidget()->parentWidget()->parentWidget()->parentWidget()->parentWidget());
    if(color==BLACK)    this->setParent(s->blackCaptured);
    if(color==WHITE)    this->setParent(s->whiteCaptured);
    this->show();

}

std::shared_ptr<QList<QWidget *> > King::getValidMovements()
{
    auto list=std::make_shared<QList<QWidget*>>();
    Board* board=static_cast<Board*>(this->parentWidget()->parentWidget()->parentWidget()->parentWidget());
    auto* parent=static_cast<Square*>(this->parentWidget());
    auto* square=board->sq;


    //other king
    Square* otherKing=nullptr;

    if(board->playerBlack->color==this->color){
        otherKing=static_cast<Square*>(board->playerWhite->king->parentWidget());
    }else{
        otherKing=static_cast<Square*>(board->playerBlack->king->parentWidget());
    }

    //horizontal

    if(parent->posY>0){
        auto to=square[parent->posX][parent->posY-1];

        if(to->childAt(0,0)==nullptr){
            if(to->euclidianDistance(otherKing)>1.9)
                list->append(to);
        }else if(static_cast<Piece*>(to->childAt(0,0))->color != this->color){
            if(to->euclidianDistance(otherKing)>1.9)
                list->append(to);
        }

    }
    if(parent->posY<7){
        auto to=square[parent->posX][parent->posY+1];

        if(to->childAt(0,0)==nullptr){
            if(to->euclidianDistance(otherKing)>1.9)
                list->append(to);
        }else if(static_cast<Piece*>(to->childAt(0,0))->color != this->color){
            if(to->euclidianDistance(otherKing)>1.9)
                list->append(to);
        }
    }

    //Vertical

    if(parent->posX<7){
        auto to=square[parent->posX+1][parent->posY];
        if(to->childAt(0,0)==nullptr){
            if(to->euclidianDistance(otherKing)>1.9)
                list->append(to);
        }else if(static_cast<Piece*>(to->childAt(0,0))->color != this->color){
            if(to->euclidianDistance(otherKing)>1.9)
                list->append(to);
        }
    }
    if(parent->posX>0){
        auto to=square[parent->posX-1][parent->posY];
        if(to->childAt(0,0)==nullptr){
            if(to->euclidianDistance(otherKing)>1.9)
                list->append(to);
        }else if(static_cast<Piece*>(to->childAt(0,0))->color != this->color){
            if(to->euclidianDistance(otherKing)>1.9)
                list->append(to);
        }
    }

    //diagonal

    if(parent->posX<7){
        //abajo
        if(parent->posY<7){
            auto to=square[parent->posX+1][parent->posY+1];
            if(to->childAt(0,0)==nullptr){
                if(to->euclidianDistance(otherKing)>1.9)
                    list->append(to);
            }else if(static_cast<Piece*>(to->childAt(0,0))->color != this->color){
                if(to->euclidianDistance(otherKing)>1.9)
                    list->append(to);
            }
        }

        if(parent->posY>0){
            auto to=square[parent->posX+1][parent->posY-1];
            if(to->childAt(0,0)==nullptr){
                if(to->euclidianDistance(otherKing)>1.9)
                    list->append(to);
            }else if(static_cast<Piece*>(to->childAt(0,0))->color != this->color){
                if(to->euclidianDistance(otherKing)>1.9)
                    list->append(to);
            }
        }
        //arriba
    }
    if(parent->posX>0){

        if(parent->posY<7){
            auto to=square[parent->posX-1][parent->posY+1];
            if(to->childAt(0,0)==nullptr){
                if(to->euclidianDistance(otherKing)>1.9)
                    list->append(to);
            }else if(static_cast<Piece*>(to->childAt(0,0))->color != this->color){
                if(to->euclidianDistance(otherKing)>1.9)
                    list->append(to);
            }
        }


        if(parent->posY>0){
            auto to=square[parent->posX-1][parent->posY-1];
            if(to->childAt(0,0)==nullptr){
                if(to->euclidianDistance(otherKing)>1.9)
                    list->append(to);
            }else if(static_cast<Piece*>(to->childAt(0,0))->color != this->color){
                if(to->euclidianDistance(otherKing)>1.9)
                    list->append(to);
            }
        }

    }




    //Limpiar en caso de jaque


    for(int i=0;i<list->size();++i){
        auto square=static_cast<Square*>(list->at(i));
        //square guarda la posicion original

        auto child=static_cast<Piece*>(square->childAt(0,0));
        if(child!=nullptr)  {
            child->captured();
        }
        this->setParent(square);
        this->show();
        if(isChecked()){
            list->removeAt(i);
            i--;
        }
        this->setParent(parent);
        this->show();
        if(child!=nullptr)  {
            child->setParent(square);
            child->show();
        }

    }



    //Enroque
    if(firstMove==true){
        if(this->color==WHITE){
            Rook* r=dynamic_cast<Rook*>(square[7][7]->childAt(0,0));

            if (r!=nullptr && r->color==WHITE){
                if(r->firstMove && square[7][5]->childAt(0,0)==nullptr && square[7][6]->childAt(0,0)==nullptr){
                    if(isCastlingPosibble(square[7][6])) list->append(square[7][6]);
                }
            }

            Rook* l=dynamic_cast<Rook*>(square[7][0]->childAt(0,0));

            if (l!=nullptr && r->color==WHITE){
                if(l->firstMove && square[7][1]->childAt(0,0)==nullptr && square[7][2]->childAt(0,0)==nullptr && square[7][3]->childAt(0,0)==nullptr){
                    if(isCastlingPosibble(square[7][2])) list->append(square[7][2]);
                }
            }


        }else{

            Rook* r=dynamic_cast<Rook*>(square[0][7]->childAt(0,0));

            if (r!=nullptr && r->color==BLACK){
                if(r->firstMove && square[0][5]->childAt(0,0)==nullptr && square[0][6]->childAt(0,0)==nullptr){
                    if(isCastlingPosibble(square[0][6])) list->append(square[0][6]);
                }
            }
            Rook* l=dynamic_cast<Rook*>(square[0][0]->childAt(0,0));

            if (l!=nullptr && r->color==BLACK){
                if(l->firstMove && square[0][1]->childAt(0,0)==nullptr && square[0][2]->childAt(0,0)==nullptr && square[0][3]->childAt(0,0)==nullptr){
                    if(isCastlingPosibble(square[0][2])) list->append(square[0][2]);
                }
            }

        }
    }

    return list;



}

bool King::isChecked()
{

    Board* board=static_cast<Board*>(this->parentWidget()->parentWidget()->parentWidget()->parentWidget());
    auto* square=board->sq;

    for (unsigned i=0;i<8;i++) {
        for (unsigned j=0;j<8;j++) {

            auto piece=static_cast<Piece*>(square[i][j]->childAt(0,0));
            if(piece!=nullptr && piece->color!=this->color && piece->name!='K'){
                auto l=piece->getValidMovements();

                if(l==nullptr)  continue;

                for(auto jug:*l){
                    auto s=static_cast<Square*>(jug);
                    auto p=static_cast<Piece*>(s->childAt(0,0));
                    if(p!=nullptr && p->name=='K'){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool King::isCastlingPosibble(Square *rookSquare)
{
    Board* board=static_cast<Board*>(this->parentWidget()->parentWidget()->parentWidget()->parentWidget());
    auto* square=board->sq;
    Piece* rook;
     if(this->color==WHITE){
         if(rookSquare->posY==6){
             rook=static_cast<Piece*>(square[7][7]->childAt(0,0));
             rook->setParent(square[7][5]);
             rook->show();
             this->setParent(square[7][6]);
             this->show();
             if(isChecked()){
                 rook->setParent(square[7][7]);
                 rook->show();
                 this->setParent(square[7][4]);
                 this->show();
                 return false;
             }
             rook->setParent(square[7][7]);
             rook->show();
             this->setParent(square[7][4]);
             this->show();
         }else{
             rook=static_cast<Piece*>(square[7][0]->childAt(0,0));
             rook->setParent(square[7][3]);
             rook->show();
             this->setParent(square[7][2]);
             this->show();
             if(isChecked()){
                 rook->setParent(square[7][0]);
                 rook->show();
                 this->setParent(square[7][4]);
                 this->show();
                 return false;
             }
             rook->setParent(square[7][0]);
             rook->show();
             this->setParent(square[7][4]);
             this->show();
         }
     }else{

         if(rookSquare->posY==6){
             rook=static_cast<Piece*>(square[0][7]->childAt(0,0));
             rook->setParent(square[0][5]);
             rook->show();
             this->setParent(square[0][6]);
             this->show();
             if(isChecked()){
                 rook->setParent(square[0][7]);
                 rook->show();
                 this->setParent(square[0][4]);
                 this->show();
                 return false;
             }
             rook->setParent(square[0][7]);
             rook->show();
             this->setParent(square[0][4]);
             this->show();
         }else{
             rook=static_cast<Piece*>(square[0][0]->childAt(0,0));
             rook->setParent(square[0][3]);
             rook->show();
             this->setParent(square[0][2]);
             this->show();
             if(isChecked()){
                 rook->setParent(square[0][0]);
                 rook->show();
                 this->setParent(square[0][4]);
                 this->show();
                 return false;
             }
             rook->setParent(square[0][0]);
             rook->show();
             this->setParent(square[0][4]);
             this->show();
         }
     }
     return true;
}

unsigned int King::cantAllValidMovements()
{
    Board* board=static_cast<Board*>(this->parentWidget()->parentWidget()->parentWidget()->parentWidget());
    auto* square=board->sq;

    for (unsigned i=0;i<8;i++) {
        for (unsigned j=0;j<8;j++) {

            auto piece=static_cast<Piece*>(square[i][j]->childAt(0,0));
            if(piece!=nullptr && piece->color==this->color && piece->name!='K'){
                auto l=piece->getValidMovements();

                if(l==nullptr)  continue;
                auto c=l->size();
                if(c>0){
                    return static_cast<unsigned>(c);
                }
            }
        }
    }
    auto myMove=this->getValidMovements()->size();
    if(myMove==0){
        return 0;
    }
    return static_cast<unsigned>(myMove);
}


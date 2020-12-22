#include "square.h"


Square::Square(QWidget *parent, Player* b, Player* w)
    : QFrame(parent)
{
    this->setMaximumSize(70, 70);
    this->setAcceptDrops(true);
    setStyleSheet("background-color:green;");
    playerB=b;
    playerW=w;

}

void Square::setPositionOnBoard(unsigned i, unsigned j)
{
    posX=i;
    posY=j;
}

void Square::generatePositionName()
{
    int x=56-static_cast<int>(posX);
    int y=97+static_cast<int>(posY);
    nameX=static_cast<char>(x);
    nameY=static_cast<char>(y);
}

void Square::mousePressEvent(QMouseEvent *event)
{
    auto child=static_cast<Piece*>(childAt(event->pos()));
    if (!child)
        return;

    //Control turns
    if(!Match::TURN==child->color){
        return;
    }else{
        child->paintValidMovements();
    }

    //end control turns

    QPixmap pixmap = *(child)->pixmap();

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << child<<pixmap;

    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos() - child->pos());


    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();

    child->setPixmap(tempPixmap);

    QChar namePiece=child->name;
    if(namePiece=='P'){
        namePiece=' ';
    }
    unsigned movementNumber=Match::MOVEMENTNUMBER;
    if (!drag->exec(Qt::MoveAction)) {
       child->setPixmap(pixmap);
       child->unpaintValidMovements();
    }else{

        auto t=drag->target();
        auto s=static_cast<Square*>(t);
        QString fila;
        if(Match::TURN==Piece::WHITE){
            fila=QString::number(movementNumber)+". "+namePiece+Match::MOVEMENTCAPTURE+nameY+nameX+"   ";
            Match::LOGGAME->appendPlainText(fila);
        }else{
            fila=namePiece+QString(Match::MOVEMENTCAPTURE)+nameY+nameX+"\n";

            Match::LOGGAME->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
            Match::LOGGAME->insertPlainText(fila);
            Match::LOGGAME->verticalScrollBar()->setValue(Match::LOGGAME->verticalScrollBar()->maximum());
            Match::MOVEMENTNUMBER++;

        }
        Match::MOVEMENTCAPTURE=0;



        Match::TURN=(!child->color);

        if(Match::TURN==Piece::BLACK){
            Match::bTurn->show();
            Match::wTurn->hide();
        }else{
            Match::wTurn->show();
            Match::bTurn->hide();
        }

        if(Match::TIMERMODE){
            if(Match::TURN==Piece::WHITE){
                Match::bTimer->stop();
                Match::wTimer->start(1000);
            }else{
                Match::wTimer->stop();
                Match::bTimer->start(1000);
            }
        }


        if(child->cantAllValidMovements()==0){
            //qDebug()<<"JAQUE Mate"<<!child->color;
            Piece::SOUNDCHECKMATE.stop();
            Piece::SOUNDCHECKMATE.play();
            QLabel* sd=Piece::CHECKALERT;
            AlertThread* t=new AlertThread(sd, "JAQUEMATE");
            t->start();
            t->wait();
            Match::LOGGAME->insertPlainText("++");
            if(child->color==Piece::WHITE) Match::LOGGAME->appendPlainText("1-0");
            else Match::LOGGAME->appendPlainText("0-1");

            if(child->color==Piece::BLACK){
                Match::ENDGAME->blackVictory();


            }else{
                Match::ENDGAME->whiteVictory();
            }

        }else if(child->isChecked()){
            Piece::SOUNDMOVE.stop();
            Piece::SOUNDMOVE.play();
            //qDebug()<<"JAQUE PW PAPI: rey -> "<<!child->color;
            QLabel* sd=Piece::CHECKALERT;
            AlertThread* t=new AlertThread(sd, "JAQUE");
            t->start();

            Match::LOGGAME->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
            Match::LOGGAME->insertPlainText("+");

        }else{
            Piece::SOUNDMOVE.stop();
            Piece::SOUNDMOVE.play();
        }
    }

}

void Square::unpaint()
{
    this->setStyleSheet("");
}

double Square::euclidianDistance(Square *other)
{
    double x1=static_cast<double>(posX);
    double x2=static_cast<double>(other->posX);
    double y1=static_cast<double>(posY);
    double y2=static_cast<double>(other->posY);
    double dis=std::pow(x2-x1, 2)+std::pow(y2-y1,2);
    dis=std::sqrt(dis);
    return dis;
}




void Square::dropEvent(QDropEvent *event)
{

    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        Piece* piece;

        dataStream >> piece;
        dataStream >> pixmap;
        //Movement validator
        auto child=static_cast<Piece*>(childAt(0, 0));
        if(!piece->isMovementValid(this->posX, this->posY, child)){
            piece->unpaintValidMovements();
            event->ignore();
            return;
        }
        piece->unpaintValidMovements();
        piece->setParent(this);
        piece->setPixmap(pixmap);
        piece->show();

        if(piece->name=='P'){
            if(piece->color==Piece::BLACK && this->posX==7){
                piece->promotion();
            }else if(piece->color==Piece::WHITE && this->posX==0){
                piece->promotion();
            }
        }

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}
void Square::dragEnterEvent(QDragEnterEvent *event)
{

    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void Square::dragMoveEvent(QDragMoveEvent *event)
{

    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}


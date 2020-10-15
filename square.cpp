#include "square.h"

Square::Square(QWidget *parent)
    : QFrame(parent)
{
    this->setMaximumSize(70, 70);
    //this->setFrameStyle(QFrame::Sunken  | QFrame::StyledPanel);
    this->setAcceptDrops(true);
    dis=true;



}

void Square::mousePressEvent(QMouseEvent *event)
{
    Piece *child = static_cast<Piece*>(childAt(event->pos()));
    if (!child)
        return;

    QPixmap pixmap = *child->pixmap();

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << pixmap << QPoint(event->pos() - child->pos());
//! [1]

//! [2]
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);
//! [2]

//! [3]
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos() - child->pos());
//! [3]

    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();

    child->setPixmap(tempPixmap);

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::MoveAction) == Qt::MoveAction) {
        child->close();
        dis=true;
    } else {
        child->show();
        child->setPixmap(pixmap);
        dis=false;
    }
}


void Square::dropEvent(QDropEvent *event)
{
    if(dis==false) {
        event->ignore();
        return;
    }
    dis=false;
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;

        Piece *newIcon = new Piece(this);
        newIcon->setPixmap(pixmap);
        //newIcon->move(event->pos() - offset);
        newIcon->move(0, 0);
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);

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
    if(dis==false) {
        event->ignore();
        return;
    }
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
    if(dis==false) {
        event->ignore();
        return;
    }

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

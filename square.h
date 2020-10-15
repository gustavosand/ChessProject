#ifndef SQUARE_H
#define SQUARE_H
#include <QFrame>
#include "piece.h"
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>
#include <QPainter>
#include <QDebug>

class Square : public QFrame
{
    Q_OBJECT

public:
    explicit Square(QWidget *parent = nullptr);
    bool dis;

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // SQUARE_H

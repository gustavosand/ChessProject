/**
  * @file promotewindow.h
  * @version 1.0
  * @author Huarca Thea Eder
  * @title Clase PromoteWindow
  * @brief Clase para la interfaz de la promocion de un Peon
  */

#ifndef PROMOTEWINDOW_H
#define PROMOTEWINDOW_H

#include <QMainWindow>
#include "piece.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "queen.h"

namespace Ui {
class PromoteWindow;
}

class PromoteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PromoteWindow(QWidget *parent = nullptr, bool c=true, Square* pieceP=nullptr);
    Square* square;
    bool color;
    ~PromoteWindow();

private slots:

    void on_rook_clicked();

    void on_knight_clicked();

    void on_bishop_clicked();

    void on_queen_clicked();

private:
    Ui::PromoteWindow *ui;
};

#endif // PROMOTEWINDOW_H

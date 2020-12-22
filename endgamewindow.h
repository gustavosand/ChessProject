/**
  * @file endgamewindow.h
  * @version 1.0
  * @author Huarca Thea Eder
  * @title Clase EndGameWindow
  * @brief Clase para mostrar ventana final
  */

#ifndef ENDGAMEWINDOW_H
#define ENDGAMEWINDOW_H

#include <QMainWindow>

namespace Ui {
class EndGameWindow;
}

class EndGameWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * @brief EndGameWindow: Constructor especifico de la clase
     * @param parent para colocar la ventana en un QWidget
     */
    explicit EndGameWindow(QWidget *parent = nullptr);
    ~EndGameWindow();

    /**
     * @brief whiteVictory: Metodo que configura la ventana cuando ganan las blancas
     */
    void whiteVictory();

    /**
     * @brief blackVictory: Metodo que configura la ventana cuando ganan las negras
     */
    void blackVictory();

private slots:

    void on_menu_clicked();


private:
    Ui::EndGameWindow *ui;
};

#endif // ENDGAMEWINDOW_H

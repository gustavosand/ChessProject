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
    explicit EndGameWindow(QWidget *parent = nullptr);
    ~EndGameWindow();
    void whiteVictory();
    void blackVictory();

private slots:

    void on_menu_clicked();


private:
    Ui::EndGameWindow *ui;
};

#endif // ENDGAMEWINDOW_H

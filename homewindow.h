/**
  * @file homewindow.h
  * @version 1.0
  * @author Huarca Thea Eder
  * @title Clase HomeWindow
  * @brief Clase para la interfaz principal
  */

#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "mainwindow.h"
#include "timermodedialog.h"

namespace Ui {
class HomeWindow;
}

class HomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomeWindow(QWidget *parent = nullptr);
    ~HomeWindow();

private slots:
    void on_PlayNormalMode_clicked();

    void on_PlayTimerMode_clicked();

    void on_exit_clicked();

    void on_about_clicked();

private:
    Ui::HomeWindow *ui;
};

#endif // HOMEWINDOW_H

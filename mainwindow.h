/**
  * @file mainwindow.h
  * @version 1.0
  * @author Huarca Thea Eder
  * @title Clase MainWindow
  * @brief Clase para la interfaz del desarrollo juego
  */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QResource>
#include "pawn.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "queen.h"
#include "king.h"
#include <QScreen>
#include <QTimer>
#include <QDateTime>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    QWidget* whiteCaptured;
    QWidget* blackCaptured;
    QWidget* boardSquare;

    static int contB;
    static int contW;
    static int limit;

    MainWindow(QWidget *parent = nullptr, bool timerMode=false);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_resignW_clicked();

    void on_resignB_clicked();

    void on_menu_clicked();

public slots:
    void timerBlack();
    void timerWhite();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

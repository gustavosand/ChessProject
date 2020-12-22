/**
  * @file timermodedialog.h
  * @version 1.0
  * @author Huarca Thea Eder
  * @title Clase TimerModeDialog
  * @brief Clase para la interfaz del dialog de seleccion de tiempo
  */

#ifndef TIMERMODEDIALOG_H
#define TIMERMODEDIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class TimerModeDialog;
}

class TimerModeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TimerModeDialog(QWidget *parent = nullptr);
    ~TimerModeDialog();

private slots:

    void on_play_clicked();
    void on_cancel_clicked();

private:
    Ui::TimerModeDialog *ui;
};

#endif // TIMERMODEDIALOG_H

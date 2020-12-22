#include "timermodedialog.h"
#include "ui_timermodedialog.h"

TimerModeDialog::TimerModeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimerModeDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->t5->setChecked(true);
}

TimerModeDialog::~TimerModeDialog()
{
    delete ui;
}




void TimerModeDialog::on_cancel_clicked()
{
    this->close();
}

void TimerModeDialog::on_play_clicked()
{
    if(ui->t5->isChecked()){
        MainWindow::limit=5*60;
        Match::TIMERMODE=true;
    }else if(ui->t10->isChecked()){
        MainWindow::limit=10*60;
        Match::TIMERMODE=true;
    }else if(ui->t15->isChecked()){
        MainWindow::limit=15*60;
        Match::TIMERMODE=true;
    }else if(ui->t30->isChecked()){
        MainWindow::limit=30*60;
        Match::TIMERMODE=true;
    }
    this->close();
}

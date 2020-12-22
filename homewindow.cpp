#include "homewindow.h"
#include "ui_homewindow.h"

HomeWindow::HomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeWindow)
{
    ui->setupUi(this);
    QPixmap p = QPixmap(":/new/img/img/cursor.png");
    p=p.scaledToWidth(60);
    QCursor c = QCursor(p, 0, 0);
    setCursor(c);
}

HomeWindow::~HomeWindow()
{
    delete ui;
}

void HomeWindow::on_PlayNormalMode_clicked()
{
    MainWindow *w=new MainWindow(this);
    w->show();
    this->hide();
}

void HomeWindow::on_PlayTimerMode_clicked()
{

    auto time=new TimerModeDialog(this);
    time->exec();
    delete time;
    if(Match::TIMERMODE==false) return;
    MainWindow *w=new MainWindow(this, true);
    w->show();
    w->showFullScreen();
    this->hide();

}

void HomeWindow::on_exit_clicked()
{

    auto box = QMessageBox();
    box.setIcon(QMessageBox::Question);
    box.setWindowTitle("Ajedrez");
    box.setText("¿Desea salir del juego?");
    box.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    auto buttonY = box.button(QMessageBox::Yes);
    buttonY->setText("Si");
    auto buttonN = box.button(QMessageBox::No);
    buttonN->setText("No");
    box.exec();
    if (box.clickedButton() == buttonY)
        QApplication::quit();
    else if( box.clickedButton() == buttonN)
        return;

}

void HomeWindow::on_about_clicked()
{
    auto box = QMessageBox();
    box.setWindowFlags( ( Qt::Window | Qt::CustomizeWindowHint ) &~
                        ( Qt::WindowSystemMenuHint | Qt::WindowCloseButtonHint ) );
    box.setWindowTitle("Ajedrez");
    box.setText("Acerca de:\nAutor: HUARCA THEA DEDER GUSTAVO\nCorreo: ehuarcat@unsa.edu.pe\nDiciembre - 2020");
    box.setStandardButtons(QMessageBox::Yes);
    auto buttonY = box.button(QMessageBox::Yes);
    buttonY->setText("Aceptar");
    box.exec();
    if (box.clickedButton() == buttonY)
        return;
}

#include "mainwindow.h"
#include "./ui_mainwindow.h"


int MainWindow::contB=0;
int MainWindow::contW=0;
int MainWindow::limit=30;

void MainWindow::timerBlack(){
    if(contB==limit){
        Match::ENDGAME->whiteVictory();
        Match::bTimer->stop();
        Match::wTimer->stop();
        return;
    }
    ui->lcdNumberB->display(limit-contB);
    contB++;
}

void MainWindow::timerWhite(){
    if(contW==limit){
        Match::ENDGAME->blackVictory();
        Match::bTimer->stop();
        Match::wTimer->stop();
        return;
    }
    ui->lcdNumberW->display(limit-contW);
    contW++;
}


MainWindow::MainWindow(QWidget *parent, bool timerMode)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->board->setStyleSheet("border-color: rgb(53, 39, 255);");

    blackCaptured=ui->blackCaptured;
    whiteCaptured=ui->whiteCaptured;
    boardSquare=ui->board;
    ui->pushButton->hide();



    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    showFullScreen();



    Pawn *p1 = new Pawn(Piece::BLACK, ui->board->sq[1][0]);
    Pawn *p2 = new Pawn(Piece::BLACK, ui->board->sq[1][1]);
    Pawn *p3 = new Pawn(Piece::BLACK, ui->board->sq[1][2]);
    Pawn *p4 = new Pawn(Piece::BLACK, ui->board->sq[1][3]);
    Pawn *p5 = new Pawn(Piece::BLACK, ui->board->sq[1][4]);
    Pawn *p6 = new Pawn(Piece::BLACK, ui->board->sq[1][5]);
    Pawn *p7 = new Pawn(Piece::BLACK, ui->board->sq[1][6]);
    Pawn *p8 = new Pawn(Piece::BLACK, ui->board->sq[1][7]);

    Rook *t1 = new Rook(Piece::BLACK, ui->board->sq[0][0]);
    Knight *k1 = new Knight(Piece::BLACK, ui->board->sq[0][1]);
    Bishop *b1 = new Bishop(Piece::BLACK, ui->board->sq[0][2]);

    Queen *q = new Queen(Piece::BLACK, ui->board->sq[0][3]);
    King *k = new King(Piece::BLACK, ui->board->sq[0][4]);

    Rook *t2 = new Rook(Piece::BLACK, ui->board->sq[0][7]);
    Knight *k2 = new Knight(Piece::BLACK, ui->board->sq[0][6]);
    Bishop *b2 = new Bishop(Piece::BLACK, ui->board->sq[0][5]);


    Pawn *p1b = new Pawn(Piece::WHITE, ui->board->sq[6][0]);
    Pawn *p2b = new Pawn(Piece::WHITE, ui->board->sq[6][1]);
    Pawn *p3b = new Pawn(Piece::WHITE, ui->board->sq[6][2]);
    Pawn *p4b = new Pawn(Piece::WHITE, ui->board->sq[6][3]);
    Pawn *p5b = new Pawn(Piece::WHITE, ui->board->sq[6][4]);
    Pawn *p6b = new Pawn(Piece::WHITE, ui->board->sq[6][5]);
    Pawn *p7b = new Pawn(Piece::WHITE, ui->board->sq[6][6]);
    Pawn *p8b = new Pawn(Piece::WHITE, ui->board->sq[6][7]);

    Rook *t1b = new Rook(Piece::WHITE, ui->board->sq[7][0]);
    Knight *k1b = new Knight(Piece::WHITE, ui->board->sq[7][1]);
    Bishop *b1b = new Bishop(Piece::WHITE, ui->board->sq[7][2]);

    Queen *qb = new Queen(Piece::WHITE, ui->board->sq[7][3]);
    King *kb = new King(Piece::WHITE, ui->board->sq[7][4]);

    Rook *t2b = new Rook(Piece::WHITE, ui->board->sq[7][7]);
    Knight *k2b = new Knight(Piece::WHITE, ui->board->sq[7][6]);
    Bishop *b2b= new Bishop(Piece::WHITE, ui->board->sq[7][5]);
    ui->board->playerWhite=new Player(Piece::WHITE);
    ui->board->playerBlack=new Player(Piece::BLACK);
    ui->board->playerWhite->king=kb;
    ui->board->playerBlack->king=k;
    Piece::SOUNDMOVE.setMedia(QUrl("qrc:/new/sounds/sounds/move.wav"));
    Piece::SOUNDCHECKMATE.setMedia(QUrl("qrc:/new/sounds/sounds/checkmate.wav"));
    Piece::CHECKALERT=ui->board->checkAlert;
    Piece::CHECKALERT->hide();

    EndGameWindow* endGame=new EndGameWindow(this);
    Match::ENDGAME=endGame;
    Match::TIMERMODE=timerMode;
    Match::LOGGAME=ui->plainTextEdit;
    Match::LOGGAME->setReadOnly(true);
    Match::bTurn=ui->bT;
    Match::wTurn=ui->wT;
    Match::bTurn->hide();
    Match::TURN=Piece::WHITE;
    Match::MOVEMENTNUMBER=1;


    if(Match::TIMERMODE){
        ui->lcdNumberW->setFrameStyle(QFrame::NoFrame);
        ui->lcdNumberB->setFrameStyle(QFrame::NoFrame);
        Match::wTimer = new QTimer(this);
        Match::bTimer = new QTimer(this);
        connect(Match::wTimer, SIGNAL(timeout()),this,SLOT(timerWhite()));
        Match::wTimer->start(1000);
        connect(Match::bTimer, SIGNAL(timeout()),this,SLOT(timerBlack()));
    }else{
        ui->lcdNumberW->hide();
        ui->lcdNumberB->hide();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    /*int a, b;
    a=qrand()%8;
    b=qrand()%8;*/

    Pawn *p1 = new Pawn(Piece::BLACK, ui->board->sq[1][0]);
    Pawn *p2 = new Pawn(Piece::BLACK, ui->board->sq[1][1]);
    Pawn *p3 = new Pawn(Piece::BLACK, ui->board->sq[1][2]);
    Pawn *p4 = new Pawn(Piece::BLACK, ui->board->sq[1][3]);
    Pawn *p5 = new Pawn(Piece::BLACK, ui->board->sq[1][4]);
    Pawn *p6 = new Pawn(Piece::BLACK, ui->board->sq[1][5]);
    Pawn *p7 = new Pawn(Piece::BLACK, ui->board->sq[1][6]);
    Pawn *p8 = new Pawn(Piece::BLACK, ui->board->sq[1][7]);

    Rook *t1 = new Rook(Piece::BLACK, ui->board->sq[0][0]);
    Knight *k1 = new Knight(Piece::BLACK, ui->board->sq[0][1]);
    Bishop *b1 = new Bishop(Piece::BLACK, ui->board->sq[0][2]);

    Queen *q = new Queen(Piece::BLACK, ui->board->sq[0][3]);
    King *k = new King(Piece::BLACK, ui->board->sq[0][4]);

    Rook *t2 = new Rook(Piece::BLACK, ui->board->sq[0][7]);
    Knight *k2 = new Knight(Piece::BLACK, ui->board->sq[0][6]);
    Bishop *b2 = new Bishop(Piece::BLACK, ui->board->sq[0][5]);


    Pawn *p1b = new Pawn(Piece::WHITE, ui->board->sq[6][0]);
    Pawn *p2b = new Pawn(Piece::WHITE, ui->board->sq[6][1]);
    Pawn *p3b = new Pawn(Piece::WHITE, ui->board->sq[6][2]);
    Pawn *p4b = new Pawn(Piece::WHITE, ui->board->sq[6][3]);
    Pawn *p5b = new Pawn(Piece::WHITE, ui->board->sq[6][4]);
    Pawn *p6b = new Pawn(Piece::WHITE, ui->board->sq[6][5]);
    Pawn *p7b = new Pawn(Piece::WHITE, ui->board->sq[6][6]);
    Pawn *p8b = new Pawn(Piece::WHITE, ui->board->sq[6][7]);

    Rook *t1b = new Rook(Piece::WHITE, ui->board->sq[7][0]);
    Knight *k1b = new Knight(Piece::WHITE, ui->board->sq[7][1]);
    Bishop *b1b = new Bishop(Piece::WHITE, ui->board->sq[7][2]);

    Queen *qb = new Queen(Piece::WHITE, ui->board->sq[7][3]);
    King *kb = new King(Piece::WHITE, ui->board->sq[7][4]);

    Rook *t2b = new Rook(Piece::WHITE, ui->board->sq[7][7]);
    Knight *k2b = new Knight(Piece::WHITE, ui->board->sq[7][6]);
    Bishop *b2b= new Bishop(Piece::WHITE, ui->board->sq[7][5]);
    ui->board->playerWhite=new Player(Piece::WHITE);
    ui->board->playerBlack=new Player(Piece::BLACK);
    ui->board->playerWhite->king=kb;
    ui->board->playerBlack->king=k;
    Piece::SOUNDMOVE.setMedia(QUrl("qrc:/new/sounds/sounds/move.wav"));
    Piece::SOUNDCHECKMATE.setMedia(QUrl("qrc:/new/sounds/sounds/checkmate.wav"));

}


void MainWindow::on_resignW_clicked()
{
    Match::ENDGAME->blackVictory();
    Match::LOGGAME->appendPlainText("0-1");
}


void MainWindow::on_resignB_clicked()
{
    Match::ENDGAME->whiteVictory();
    Match::LOGGAME->appendPlainText("1-0");
}

void MainWindow::on_menu_clicked()
{
    auto box = QMessageBox();
    box.setIcon(QMessageBox::Question);
    box.setWindowTitle("Ajedrez");
    box.setText("¿Desea salir sin terminar\n la partida?");
    box.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    auto buttonY = box.button(QMessageBox::Yes);
    buttonY->setText("Si");
    auto buttonN = box.button(QMessageBox::No);
    buttonN->setText("No");
    box.exec();
    if (box.clickedButton() == buttonY){
        this->parentWidget()->show();
        this->close();
    }else if( box.clickedButton() == buttonN)
        return;



}

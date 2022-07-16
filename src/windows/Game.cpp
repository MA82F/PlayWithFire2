#include "Game.h"
#include <QList>
#include <ctime>
#include "../Controller.h"
#include "../views/Label.h"
#include "../views/Bomb_effect.h"
#include <QTimer>
//#include<cstdlib>

//using namespace std;
Game::Game(QString name1,QString name2): QGraphicsView() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();

    auto scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,width(),height());
    scene->setBackgroundBrush(QColor("#211C16"));
    setScene(scene);

    auto blockWidth = width() / 15;
    auto blockHeight = height() /15;
    auto playerWidth = width() /15;
    auto playerHeight = height() /15;

    auto player1 = new Player(name1,playerWidth,playerHeight);
    scene->addItem(player1);
    player1->setPos(playerWidth+10,playerHeight+3);
//    players.first()=player1;

    auto player2 = new Player(name2,playerWidth,playerHeight);
    scene->addItem(player2);
    player2->setPos(playerWidth*13+10,playerHeight*13+3);
//    players.last()=player2;
    players.append(player1);
    players.append(player2);
//    playerspictures* pPicture=new playerspictures();

//    auto Bomb1=new Bomb(width()/15,height()/15);
//    scene->addItem(Bomb1);
//    BombList.append(Bomb1);
//    auto Bomb2=new Bomb(width()/15,height()/15);
//    scene->addItem(Bomb2);
//    BombList.append(Bomb2);

//
//    boom = bomb_effect;

    for (int l = 0; l < 15; ++l) {
        for (int j = 0; j < 15; ++j) {
            if (l!=0 && l!=14 && j!=0 && j!=14 && (l%2!=0 || j%2!=0)){
                continue;
            }
            auto wall = new Wall(blockWidth, blockHeight);
            scene->addItem(wall);
            wall->setPos(blockWidth * l, blockHeight * j);
            blocks.append(wall);
        }
    }

    srand(time(0));
    Box_Place positionOfBoxes[224];
    for(int temp=0;temp<224;temp++){
        positionOfBoxes[temp].x=100;
        positionOfBoxes[temp].y=100;
    }
    numOfBox=0;
    for (int i = 0;numOfBox<50; ++i) {
        int ii = rand() % 15;
        int jj = rand() % 15;
        if ((ii != 0 && ii != 14 && jj != 0 && jj != 14 && (ii % 2 != 0 || jj % 2 != 0))) {
            if (((ii != 13 || jj != 13) && (ii != 1 || jj != 1) && (ii != 12 || jj != 13) &&
                 (ii != 13 || jj != 12) && (ii != 1 || jj != 2) && (ii != 2 || jj != 1)))// && (ii != 1 || jj != 3) &&
                 //(ii != 3 || jj != 1) && (ii != 11 || jj != 13) && (ii != 13 || jj != 11)))
                  {
                //positionOfBoxes[i].x=ii;
                // positionOfBoxes[i].y=jj;
                bool is_exist= false;
                for(int c=0;c<i+1;c++){
                    if(positionOfBoxes[c].x==ii){
                        if(positionOfBoxes[c].y==jj){is_exist= true;
                        }
                    }
                }
                if(is_exist== false){
                    auto box = new class Box(blockWidth, blockHeight);
                    scene->addItem(box);
                    box->setPos(blockWidth * ii, blockHeight * jj);
                    positionOfBoxes[i].x=ii;
                    positionOfBoxes[i].y=jj;
                    blocks.append(box);
                    ++numOfBox;
                }
            }
        }
    }
    auto n1player = new Label();
    n1player->setPlainText("Player1: " + name1);
    scene->addItem(n1player);
    n1player->setPos(blockWidth*1.5,blockHeight/5);
    auto n2player = new Label();
    n2player->setPlainText("Player2: " + name2);
    scene->addItem(n2player);
    n2player->setPos(blockWidth*11,blockHeight/5);
//    setFocus();
    auto controller=new Controller(players,blocks);
    scene->addItem(controller);
    controller->setFocus();
    connect(controller,&Controller::bomb1_called, this,&Game::boom);
    //connect(controller,&Controller::bomb2_called, this,&Game::boom);
    connect(controller,&Controller::player1_up, this,&Game::p1Up);
    connect(controller,&Controller::player2_up, this,&Game::p2Up);
    connect(controller,&Controller::player1_down, this,&Game::p1Down);
    connect(controller,&Controller::player2_down, this,&Game::p2Down);
    connect(controller,&Controller::player1_left, this,&Game::p1Left);
    connect(controller,&Controller::player2_left, this,&Game::p2Left);
    connect(controller,&Controller::player1_right, this,&Game::p1Right);
    connect(controller,&Controller::player2_right, this,&Game::p2Right);
  //  connect()
//    bombTimer =new QTimer();
//    bombTimer->setInterval(2000);
//    connect(bombTimer,&QTimer::timeout,&Controller::bomb1,&Game::boom);
//    bombTimer->start();
}
void Game::boom(){
auto tempBomb=new Bomb(75,75);
Bomb1=tempBomb;
scene()->addItem(tempBomb);
tempBomb->setPos(100,150);
bombTimer=new QTimer();
bombTimer->setInterval(2000);
    connect(bombTimer,&QTimer::timeout, this,&Game::bomb_remover);
//scene()->removeItem(tempBomb);
bombTimer->start();
}

void Game::p1Up() {
    players.at(0)->setPixmap(pPicture->ImagesPlayer1.at(0));

}

void Game::p2Up() {
    players.at(1)->setPixmap(pPicture->ImagesPlayer2.at(0));
}

void Game::p1Down() {
    players.at(0)->setPixmap(pPicture->ImagesPlayer1.at(1));

}

void Game::p2Down() {
    players.at(1)->setPixmap(pPicture->ImagesPlayer2.at(1));
}

void Game::p1Left() {
    players.at(0)->setPixmap(pPicture->ImagesPlayer1.at(2));
}

void Game::p2Left() {
    players.at(1)->setPixmap(pPicture->ImagesPlayer2.at(2));

}

void Game::p1Right() {
    players.at(0)->setPixmap(pPicture->ImagesPlayer1.at(3));

}

void Game::p2Right() {
    players.at(1)->setPixmap(pPicture->ImagesPlayer2.at(3));

}

void Game::bomb_remover() {
scene()->removeItem(Bomb1);
}

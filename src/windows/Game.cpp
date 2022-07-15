#include "Game.h"
#include <QList>
//#include <ctime>
#include "../Controller.h"
#include "../views/Label.h"
#include "../views/Bomb_effect.h"

Game::Game(QString name1,QString name2): QGraphicsView{} {
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

    auto Bomb1=new Bomb(width()/15,height()/15);
    scene->addItem(Bomb1);
    BombList.append(Bomb1);
    auto Bomb2=new Bomb(width()/15,height()/15);
    scene->addItem(Bomb2);
    BombList.append(Bomb2);

//    auto bomb_effect = new Bomb_effect(width()/15,height()/15);
//    scene->addItem(bomb_effect);
//    boom = bomb_effect;
//bomb_effect();
    auto controller=new Controller(players,blocks,BombList);
    scene->addItem(controller);
    controller->setFocus();
    QObject::connect( controller,&Controller::bomb1_called, this,&Game::bomb_effect);
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
//    bombTimer =new QTimer();
//    bombTimer->setInterval(2000);
//    connect(bombTimer,&QTimer::timeout,&Controller::bomb1,&Game::boom);
//    bombTimer->start();
}

void Game::bomb_effect() {
    bombTimer=new QTimer();
    bombTimer->setInterval(2000);
    bombTimer->start();
    auto bomb_Effect = new Bomb_effect(width()/15,height()/15);
    scene()->addItem(bomb_Effect);
    BombList.at(0)->setPos(players.at(0)->x(),players.at(0)->y());
    bomb_Effect->setPos(BombList.at(0)->x(),BombList.at(0)->y());
}

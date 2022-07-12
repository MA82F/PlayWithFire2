//
// Created by IHC on 7/11/2022.
//

#include "Game.h"
#include "../views/Wall.h"
#include "../views/Player.h"

Game::Game(QString name1,QString name2): QGraphicsView() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();

    auto scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,width(),height());
    scene->setBackgroundBrush(QColor("#2F2627"));
    setScene(scene);

    auto blockWidth = width() / 15;
    auto blockHeight = height() /15;
    auto playerWidth = width() /15;
    auto playerHeight = height() /15;
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            if (i!=0 && i!=14 && j!=0 && j!=14 && (i%2!=0 || j%2!=0)){
                if (i==1 && j==1){
                    auto player1 = new Player(name1);
                    scene->addItem(player1);
                    player1->setPos(playerWidth*i,playerHeight*j);
                }
                else if(i==13 && j==13){
                    auto player2 = new Player(name2);
                    scene->addItem(player2);
                    player2->setPos(playerWidth*i,playerHeight*j);
                }
                continue;
            }
            auto wall = new Wall(blockWidth, blockHeight);
            scene->addItem(wall);
            wall->setPos(blockWidth * i, blockHeight * j);
        }
    }

    auto player = new QGraphicsScene(this);
    scene->setSceneRect(0,0,width(),height());
    scene->setBackgroundBrush(QColor("#2F2627"));
    setScene(scene);


}

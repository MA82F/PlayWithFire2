//
// Created by IHC on 7/11/2022.
//

#include "Game.h"
#include "../views/Wall.h"
#include "../views/Player.h"
#include "../views/Box.h"
#include <QList>
#include <ctime>
#include <iostream>

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

    QList<Player*> players;

    auto player1 = new Player(name1,playerWidth,playerHeight);
    scene->addItem(player1);
    player1->setPos(playerWidth+10,playerHeight+3);

    auto player2 = new Player(name2,playerWidth,playerHeight);
    scene->addItem(player2);
    player2->setPos(playerWidth*13+10,playerHeight*13+3);

    players.append(player1);
    players.append(player2);

    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            if (i!=0 && i!=14 && j!=0 && j!=14 && (i%2!=0 || j%2!=0)){
                continue;
            }
            auto wall = new Wall(blockWidth, blockHeight);
            scene->addItem(wall);
            wall->setPos(blockWidth * i, blockHeight * j);
        }
    }

        box_position positionOfBoxes[35];
        for(int i=0;i<36;i++){
            positionOfBoxes[i].x=100;
            positionOfBoxes[i].y=100;
        }
        numOfBox=0;
        srand(time(0));
        for (int i = 0; i < 36; ++i) {
            int ii = rand() % 15;
            int jj = rand() % 15;
            if ((ii != 0 && ii != 14 && jj != 0 && jj != 14 && (ii % 2 != 0 || jj % 2 != 0))) {
                if (((ii != 13 || jj != 13) && (ii != 1 || jj != 1) && (ii != 12 || jj != 13) &&
                     (ii != 13 || jj != 12) && (ii != 1 || jj != 2) && (ii != 2 || jj != 1) && (ii != 1 || jj != 3) &&
                     (ii != 3 || jj != 1) && (ii != 11 || jj != 13) && (ii != 13 || jj != 11))) {
                    positionOfBoxes[i].x = ii;
                    positionOfBoxes[i].y = jj;
                    for (int j = 0; j < i + 1; ++j) {
                        for(int z=0;z<i+1;++z){
                        if (positionOfBoxes[j].x != positionOfBoxes[z].x) {
                            if (positionOfBoxes[j].y != positionOfBoxes[z].y) {
                                //--i;
                                //std::cout<<"hello world\n";
                                continue;
                                //    break;
                            }
                    auto box = new class Box(blockWidth, blockHeight);
                    scene->addItem(box);
                    box->setPos(blockWidth * ii, blockHeight * jj);
                    ++numOfBox;
                }}
            }}}
            else
                --i;
        }
        std::cout<<numOfBox<<std::endl;
}


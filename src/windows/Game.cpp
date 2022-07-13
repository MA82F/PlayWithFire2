#include "Game.h"
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
            blocks.append(wall);
        }
    }

    srand(time(0));
    int i=0;
    for (auto BOX:blocks) {
            int ii = rand() % 15;
            int jj = rand() % 15;
            if(ii!=0 && ii!=14 && jj!=0 && jj!=14 && (ii%2!=0 || jj%2!=0)) {
                auto boxx = new class Box(blockWidth, blockHeight);
                if (boxx->x() != BOX->x() && boxx->y() != BOX->y()) {
                    scene->addItem(boxx);
                    boxx->setPos(blockWidth * ii, blockHeight * jj);
                    blocks.append(boxx);
                    ++i;
                    if (i == 10) {
                        break;
                    }
                }
                else
                    --i;
            }
        }
}


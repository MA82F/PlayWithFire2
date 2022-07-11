//
// Created by IHC on 7/11/2022.
//

#include "Game.h"
#include "../views/Wall.h"

Game::Game(QString name): QGraphicsView() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();

    auto scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,width(),height());
    scene->setBackgroundBrush(QColor("#2F2627"));
    setScene(scene);

    auto blockWidth = width() / 15;
    auto blockHeight = height() /15;
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


}

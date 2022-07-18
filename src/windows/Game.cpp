#include "Game.h"
#include <QList>
#include <ctime>
#include "../views/Label.h"
#include "../views/Bomb_effect.h"
#include <QTimer>
Game::Game(QString name1, QString name2) : QGraphicsView() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();

    auto scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    scene->setBackgroundBrush(QColor("#211C16"));
    setScene(scene);

    auto blockWidth = width() / 15;
    auto blockHeight = height() / 15;
    auto playerWidth = width() / 15;
    auto playerHeight = height() / 15;

    auto player1 = new Player(name1, playerWidth, playerHeight);
    scene->addItem(player1);
    player1->setPos(playerWidth + 10, playerHeight + 3);
//    players.first()=player1;

    auto player2 = new Player(name2, playerWidth, playerHeight);
    scene->addItem(player2);
    player2->setPos(playerWidth * 13 + 10, playerHeight * 13 + 3);
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
            if (l != 0 && l != 14 && j != 0 && j != 14 && (l % 2 != 0 || j % 2 != 0)) {
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
    for (int temp = 0; temp < 224; temp++) {
        positionOfBoxes[temp].x = 100;
        positionOfBoxes[temp].y = 100;
    }
    numOfBox = 0;
    for (int i = 0; numOfBox < 50; ++i) {
        int ii = rand() % 15;
        int jj = rand() % 15;
        if ((ii != 0 && ii != 14 && jj != 0 && jj != 14 && (ii % 2 != 0 || jj % 2 != 0))) {
            if (((ii != 13 || jj != 13) && (ii != 1 || jj != 1) && (ii != 12 || jj != 13) &&
                 (ii != 13 || jj != 12) && (ii != 1 || jj != 2) && (ii != 2 || jj != 1)))// && (ii != 1 || jj != 3) &&
                //(ii != 3 || jj != 1) && (ii != 11 || jj != 13) && (ii != 13 || jj != 11)))
            {
                //positionOfBoxes[i].x=ii;
                // positionOfBoxes[i].y=jj;
                bool is_exist = false;
                for (int c = 0; c < i + 1; c++) {
                    if (positionOfBoxes[c].x == ii) {
                        if (positionOfBoxes[c].y == jj) {
                            is_exist = true;
                        }
                    }
                }
                if (is_exist == false) {
                    auto box = new class Box(blockWidth, blockHeight);
                    scene->addItem(box);
                    box->setPos(blockWidth * ii, blockHeight * jj);
                    positionOfBoxes[i].x = ii;
                    positionOfBoxes[i].y = jj;
                    blocks.append(box);
//                    boxes.append(box);
                    ++numOfBox;
                }
            }
        }
    }
    auto n1player = new Label();
    QString life1 = QString::number(players.at(0)->lifeCount);
    n1player->setPlainText("Player1: " + life1);
    scene->addItem(n1player);
    n1player->setPos(blockWidth * 1.5, blockHeight / 5);
    auto n2player = new Label();
    QString life2 = QString::number(players.at(1)->lifeCount);
    n2player->setPlainText("Player2: " + life2);
//    setAutoFillBackground(n2player);
    scene->addItem(n2player);
    n2player->setPos(blockWidth * 11, blockHeight / 5);
//    setFocus();
    auto controller = new Controller(players, &blocks);//,BombList
    scene->addItem(controller);
    controller->setFocus();
    connect(controller, &Controller::bomb1_called, this, &Game::boom1);
    connect(controller, &Controller::bomb2_called, this, &Game::boom2);
    connect(controller, &Controller::player1_up, this, &Game::p1Up);
    connect(controller, &Controller::player2_up, this, &Game::p2Up);
    connect(controller, &Controller::player1_down, this, &Game::p1Down);
    connect(controller, &Controller::player2_down, this, &Game::p2Down);
    connect(controller, &Controller::player1_left, this, &Game::p1Left);
    connect(controller, &Controller::player2_left, this, &Game::p2Left);
    connect(controller, &Controller::player1_right, this, &Game::p1Right);
    connect(controller, &Controller::player2_right, this, &Game::p2Right);
}

void Game::boom1() {
    bomb1 = new Bomb(width()/27, height()/18);
//BombList.append(bomb1);
    scene()->addItem(bomb1);
    bomb1->setPos(players.at(0)->x(), players.at(0)->y());
    bombTimer = new QTimer();
    bombTimer->setInterval(2000);
    connect(bombTimer, &QTimer::timeout, this, &Game::bombRemove1);
    bombTimer->start();
//scene()->removeItem(bomb1);
//delete bomb1;
//bombTimer->start();
}

void Game::boom2() {
//bomb2=new Bomb(91,51);
////BombList.append(bomb1);
//scene()->addItem(bomb2);
//bomb2->setPos(players.at(1)->x(),players.at(1)->y());
//bombTimer = new QTimer();
//bombTimer->setInterval(5000);
//connect(bombTimer,&QTimer::timeout,this,&Game::bombRemove2);
//bombTimer->start();
//bombTimer->stop();
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

void Game::bombRemove1() {
    bombTimer->stop();
    BoomTemplate.clear();
    //////////////////////////////////////
    auto boom1 = new Bomb_effect(width() / 30, height() / 25);
    scene()->addItem(boom1);
    boom1->setPos(bomb1->x(), bomb1->y());
    BoomTemplate.append(boom1);
////////////////////////////////////////
    auto boom2 = new Bomb_effect(width() / 25, height() / 25);
    BoomTemplate.append(boom2);
    scene()->addItem(boom2);
    boom2->setPos(bomb1->x() + bomb1->width, bomb1->y());
    connect(boom2, &Bomb_effect::clash, this, &Game::boomRemoverTest);
    connect(boom2, &Bomb_effect::Box_removed, this, &Game::Box_Remover);
    ///////////////////////////////////
    auto boom3 = new Bomb_effect(width() / 25, height() / 25);
    BoomTemplate.append(boom3);
    scene()->addItem(boom3);
    boom3->setPos(bomb1->x() - bomb1->width, bomb1->y());
    connect(boom3, &Bomb_effect::clash, this, &Game::boomRemoverTest);
    connect(boom3, &Bomb_effect::Box_removed, this, &Game::Box_Remover);
    /////////////////////////////////
    auto boom4 = new Bomb_effect(width() / 25, height() / 25);
    BoomTemplate.append(boom4);
    scene()->addItem(boom4);
    boom4->setPos(bomb1->x(), bomb1->y() + bomb1->height);
    connect(boom4, &Bomb_effect::clash, this, &Game::boomRemoverTest);
    connect(boom4, &Bomb_effect::Box_removed, this, &Game::Box_Remover);
    ////////////////////////////////////////////////
    auto boom5 = new Bomb_effect(width() / 25, height() / 25);
    BoomTemplate.append(boom5);
    scene()->addItem(boom5);
    boom5->setPos(bomb1->x(), bomb1->y() - bomb1->height);
    connect(boom5, &Bomb_effect::clash, this, &Game::boomRemoverTest);
    connect(boom5, &Bomb_effect::Box_removed, this, &Game::Box_Remover);
    //////////////////////////////////////////////
    scene()->removeItem(bomb1);
    delete bomb1;

    boomTimer = new QTimer();
    boomTimer->setInterval(2000);
    connect(boomTimer, &QTimer::timeout, this, &Game::allBoomRemover);
    boomTimer->start();
}

void Game::bombRemove2() {


}

//void Game::Box_Remover( Box(100,200)) {
//    //blocks.removeOne(tempBox);
//}

void Game::boomRemoverTest(Bomb_effect *tempBombeffect) {
    scene()->removeItem(tempBombeffect);
    tempBombeffect = nullptr;
}

void Game::allBoomRemover() {
    boomTimer->stop();
    for (int y = 0; y < 5; y++) {
        if (BoomTemplate[y] != nullptr) {
            scene()->removeItem(BoomTemplate[y]);
            BoomTemplate[y] = nullptr;
        }
    }
}

void Game::Box_Remover(Block* temp_box ) {
    if (temp_box->type==1){
        scene()->removeItem(temp_box);
        blocks.removeOne(temp_box);
    }
}





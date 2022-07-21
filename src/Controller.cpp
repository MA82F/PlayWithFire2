#include "Controller1.h"

bool Controller1::bombKey1 = {false};
bool Controller1::bombKey2 = {false};

Controller1::Controller1(QList <Player*> players, QList <Block*> *blocks) {
    setFlags(GraphicsItemFlag::ItemIsFocusable);
    speedplayers=players.at(0)->getSpeed();
    tempPlayers=players;
    tempBlocks=blocks;
}

void Controller1::Up1() {
    newY1 = tempPlayers.at(0)->y() -15;
    emit player1_up();
}

void Controller1::right1() {
    newX1 = tempPlayers.at(0)->x() +15;
    emit player1_right();
}

void Controller1::down1() {
    newY1 = tempPlayers.at(0)->y() +15;
    emit player1_down();
}

void Controller1::left1() {
    newX1 = tempPlayers.at(0)->x() -15;
    emit player1_left();
}

//----------------------------------------------------------------------------------------------------------------------

void Controller1::Up2() {
    newY2 = tempPlayers.at(1)->y() -15;
    emit player2_up();
}

void Controller1::right2() {
    newX2 = tempPlayers.at(1)->x() +15;
    emit player2_right();
}

void Controller1::down2() {
    newY2 = tempPlayers.at(1)->y() +15;
    emit player2_down();
}

void Controller1::left2() {
    newX2 = tempPlayers.at(1)->x() -15;
    emit player2_left();
}

//----------------------------------------------------------------------------------------------------------------------

void Controller1::bomb1() {
    emit bomb1_called();
    bombTimer1 = new QTimer();
    bombTimer1->setInterval(2000);
    connect(bombTimer1,&QTimer::timeout,this,&Controller1::bombTimerTime1);
    bombTimer1->start();
}

void Controller1::bombTimerTime1(){
    bombKey1 = false;
    bombTimer1->stop();
}

//----------------------------------------------------------------------------------------------------------------------

void Controller1::bomb2() {
    emit bomb2_called();
    bombTimer2 = new QTimer();
    bombTimer2->setInterval(5000);
    connect(bombTimer2,&QTimer::timeout,this,&Controller1::bombTimerTime2);
    bombTimer2->start();
}

void Controller1::bombTimerTime2(){
    bombKey2 = false;
    bombTimer2->stop();
}

//----------------------------------------------------------------------------------------------------------------------

void Controller1::keyPressEvent(QKeyEvent *event) {
    QGraphicsItem::keyPressEvent(event);
    auto player1Width = tempPlayers.at(0)->boundingRect().width();
    auto player1Height = tempPlayers.at(0)->boundingRect().height();
    auto player2Width = tempPlayers.at(1)->boundingRect().width();
    auto player2Height = tempPlayers.at(1)->boundingRect().height();
     newX1 = tempPlayers.at(0)->x();
     newY1 = tempPlayers.at(0)->y();
     newX2 = tempPlayers.at(1)->x();
     newY2 = tempPlayers.at(1)->y();
    if (event->key()==Qt::Key::Key_Space){
        if(!bombKey1){
            bombKey1 = true;
            bomb1();
        }
        else {
            event->ignore();
        }
    }
    if(event->key()==Qt::Key::Key_Delete){
        if(!bombKey2){
            bombKey2 = true;
            bomb2();
        }
        else {
            event->ignore();
        }
    }
    if(event->key()==Qt::Key::Key_W){
        Up1();
    }
    if(event->key()==Qt::Key::Key_D){
        right1();
    }
    if(event->key()==Qt::Key::Key_S){
        down1();
    }
    if(event->key()==Qt::Key::Key_A){
        left1();
    }

    if(event->key()==Qt::Key::Key_Up){
        Up2();
    }
    if(event->key()==Qt::Key::Key_Right){
        right2();
    }
    if(event->key()==Qt::Key::Key_Down){
        down2();
    }
    if(event->key()==Qt::Key::Key_Left){
        left2();
    }
    //collision player1 with Walls
    for (const auto block:*tempBlocks) {
        if(block->x()<newX1 && block->x() + block->boundingRect().width()>newX1
            && block->y()<newY1 && block->y() + block->boundingRect().height()>newY1){
            return;
        }
        if(block->x()<newX1 + player1Width && block->x() + block->boundingRect().width()>newX1 + player1Width
            && block->y()<newY1 && block->y() + block->boundingRect().height()>newY1){
            return;
        }
        if(block->x()<newX1 + player1Width && block->x() + block->boundingRect().width()>newX1 + player1Width
            && block->y()<newY1 + player1Height && block->y() + block->boundingRect().height()>newY1 + player1Height){
            return;
        }
        if(block->x()<newX1 && block->x() + block->boundingRect().width()>newX1
            && block->y()<newY1 + player1Height && block->y() + block->boundingRect().height()>newY1 + player1Height){
            return;
        }
    }
    //collision player2 with Walls
    for(const auto block:*tempBlocks){
        if(block->x()<newX2 && block->x() + block->boundingRect().width()>newX2
           && block->y()<newY2 && block->y() + block->boundingRect().height()>newY2){
            return;
        }
        if(block->x()<newX2 + player2Width && block->x() + block->boundingRect().width() > newX2 + player2Width
           && block->y()<newY2 && block->y() + block->boundingRect().height()>newY2){
            return;
        }
        if(block->x()<newX2 + player2Width && block->x() + block->boundingRect().width()>newX2 + player2Width
           && block->y()<newY2 + player2Height && block->y() + block->boundingRect().height()>newY2 + player2Height){
            return;
        }
        if(block->x()<newX2  && block->x() + block->boundingRect().width()>newX2
           && block->y()<newY2 + player2Height && block->y() + block->boundingRect().height()>newY2 + player2Height){
            return;
        }
    }

    tempPlayers.at(0)->setPos(newX1,newY1);
    tempPlayers.at(1)->setPos(newX2,newY2);
}
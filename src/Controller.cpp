
#include <QWidgetData>
#include <QWidget>
#include "Controller.h"
//#include <QGraphicsView>
Controller::Controller(QList <Player*> players,QList <Block*> blocks,QList<Bomb*>BombList,Bomb_effect *booom) {
    setFlags(GraphicsItemFlag::ItemIsFocusable);
    animator1 = new QPropertyAnimation(players.at(0), "height", players.at(0));
    animator2 = new QPropertyAnimation(players.at(0), "width", players.at(0));
    animator3=new QPropertyAnimation(players.at(1),"height",players.at(1));
    animator4=new QPropertyAnimation(players.at(1),"width",players.at(1));
//    yp1=players.at(0)->y();
//    yp2=players.at(1)->y();
//    xp1=players.at(0)->x();
//    xp2=players.at(1)->x();
    speedplayers=players.at(0)->getSpeed();
    tempPlayers=players;
    tempBlocks=blocks;
    tempBombList=BombList;
    boom = booom;
}

void Controller::down() {
    newY1 = tempPlayers.at(0)->y() +15;
//    animator1->stop();
//    animator1->setStartValue(tempPlayers.at(0)->y());
//    animator1->setEndValue(tempPlayers.at(0)->y()+75);
//    //yp1=yp1+75;
//    animator1->setDuration(200/speedplayers);
//    animator1->start();
}
void Controller::right() {
    newX1 = tempPlayers.at(0)->x() +15;
//    animator2->stop();
//    animator2->setStartValue( tempPlayers.at(0)->x());
//    animator2->setEndValue(tempPlayers.at(0)->x()+75);
//    xp1=xp1+75;
//    animator2->setDuration(200/speedplayers);
//    animator2->start();
}
void Controller::left() {
    newX1 = tempPlayers.at(0)->x() -15;
//    animator2->stop();
//    animator2->setStartValue( tempPlayers.at(0)->x());
//    animator2->setEndValue(tempPlayers.at(0)->x()-75);
//    animator2->setDuration(200/speedplayers);
//    animator2->start();
}




void Controller::Up() {
    newY1 = tempPlayers.at(0)->y() -15;
//    animator1->stop();
//    animator1->setStartValue( tempPlayers.at(0)->y());
//    animator1->setEndValue(tempPlayers.at(0)->y()-75);
//    animator1->setDuration(200/speedplayers);
//    animator1->start();

}
//----------------------------------------------------------------------------------------------------------------------

void Controller::down2() {
    newY2 = tempPlayers.at(1)->y() +15;
//    animator3->stop();
//    animator3->setStartValue(tempPlayers.at(1)->y());
//    animator3->setEndValue(tempPlayers.at(1)->y()+75);
//    //yp1=yp1+75;
//    animator3->setDuration(200/speedplayers);
//    animator3->start();
}
void Controller::right2() {
    newX2 = tempPlayers.at(1)->x() +15;
//    animator4->stop();
//    animator4->setStartValue( tempPlayers.at(1)->x());
//    animator4->setEndValue(tempPlayers.at(1)->x()+75);
//    //xp1=xp1+75;
//    animator4->setDuration(200/speedplayers);
//    animator4->start();
}
void Controller::left2() {
    newX2 = tempPlayers.at(1)->x() -15;
//    animator4->stop();
//    animator4->setStartValue( tempPlayers.at(1)->x());
//    animator4->setEndValue(tempPlayers.at(1)->x()-75);
//    animator4->setDuration(200/speedplayers);
//    animator4->start();
}




void Controller::Up2() {
    newY2 = tempPlayers.at(1)->y() -15;
//    animator3->stop();
//    animator3->setStartValue( tempPlayers.at(1)->y());
//    animator3->setEndValue(tempPlayers.at(1)->y()-75);
//    animator3->setDuration(200/speedplayers);
//    animator3->start();

}

void Controller::bomb1() {
    newX3 = tempPlayers.at(0)->x();
    newY3=tempPlayers.at(0)->y();
tempBombList.at(0)->setPos(newX3,newY3);
}

void Controller::bomb2() {
    newX4 = tempPlayers.at(1)->x();
    newY4=tempPlayers.at(1)->y();
    tempBombList.at(1)->setPos(newX4,newY4);
}


void Controller::keyPressEvent(QKeyEvent *event) {
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
        bomb1();
        bombTimer =new QTimer();
        bombTimer->setInterval(2000);
        connect(bombTimer,&QTimer::timeout,this,&Controller::bomb_effect);
        bombTimer->start();
    }
    if(event->key()==Qt::Key::Key_Delete){
        bomb2();
    }
    if(event->key()==Qt::Key::Key_S){
        down();
    }
    if(event->key()==Qt::Key::Key_W){
        Up();
    }
    if(event->key()==Qt::Key::Key_A){
        left();
    }
    if(event->key()==Qt::Key::Key_D){
        right();
    }
    if(event->key()==Qt::Key::Key_Down){
        down2();
    }
    if(event->key()==Qt::Key::Key_Up){
        Up2();
    }
    if(event->key()==Qt::Key::Key_Left){
        left2();
    }
    if(event->key()==Qt::Key::Key_Right){
        right2();
    }
    for (const auto block:tempBlocks) {
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
    for(const auto block:tempBlocks){
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
void Controller::bomb_effect(){
//    auto blockWidth = width() / 15;
//    auto blockHeight = height() / 15;
//    auto bomb_effect = new Bomb_effect(width()/15,height()/15);
//    scene()->addItem(bomb_effect);
    boom->setPos(tempBombList.at(0)->x(),tempBombList.at(0)->y());

}


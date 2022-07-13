
#include <QWidgetData>
#include <QWidget>
#include "Controller.h"
Controller::Controller(QList <Player*> players) {
    setFlags(GraphicsItemFlag::ItemIsFocusable);
    animator1 = new QPropertyAnimation(players.at(0), "height", players.at(0));
    animator2 = new QPropertyAnimation(players.at(0), "width", players.at(0));
    animator3=new QPropertyAnimation(players.at(1),"height",players.at(1));
    animator4=new QPropertyAnimation(players.at(1),"width",players.at(1));
    yp1=players.at(0)->y();
    yp2=players.at(1)->y();
    xp1=players.at(0)->x();
    xp2=players.at(1)->x();
    speedplayers=players.at(0)->getSpeed();
    tempPlayers=players;
}

void Controller::down() {
    animator1->stop();
    animator1->setStartValue(tempPlayers.at(0)->y());
    animator1->setEndValue(tempPlayers.at(0)->y()+75);
    //yp1=yp1+75;
    animator1->setDuration(200/speedplayers);
    animator1->start();
}
void Controller::right() {
    animator2->stop();
    animator2->setStartValue( tempPlayers.at(0)->x());
    animator2->setEndValue(tempPlayers.at(0)->x()+75);
    xp1=xp1+75;
    animator2->setDuration(200/speedplayers);
    animator2->start();
}
void Controller::left() {
    animator2->stop();
    animator2->setStartValue( tempPlayers.at(0)->x());
    animator2->setEndValue(tempPlayers.at(0)->x()-75);
    animator2->setDuration(200/speedplayers);
    animator2->start();
}




void Controller::Up() {
    animator1->stop();
    animator1->setStartValue( tempPlayers.at(0)->y());
    animator1->setEndValue(tempPlayers.at(0)->y()-75);
    animator1->setDuration(200/speedplayers);
    animator1->start();

}
////////////////////////////////////////

void Controller::down2() {
    animator3->stop();
    animator3->setStartValue(tempPlayers.at(1)->y());
    animator3->setEndValue(tempPlayers.at(1)->y()+75);
    //yp1=yp1+75;
    animator3->setDuration(200/speedplayers);
    animator3->start();
}
void Controller::right2() {
    animator4->stop();
    animator4->setStartValue( tempPlayers.at(1)->x());
    animator4->setEndValue(tempPlayers.at(1)->x()+75);
    //xp1=xp1+75;
    animator4->setDuration(200/speedplayers);
    animator4->start();
}
void Controller::left2() {
    animator4->stop();
    animator4->setStartValue( tempPlayers.at(1)->x());
    animator4->setEndValue(tempPlayers.at(1)->x()-75);
    animator4->setDuration(200/speedplayers);
    animator4->start();
}




void Controller::Up2() {
    animator3->stop();
    animator3->setStartValue( tempPlayers.at(1)->y());
    animator3->setEndValue(tempPlayers.at(1)->y()-75);
    animator3->setDuration(200/speedplayers);
    animator3->start();

}


void Controller::keyPressEvent(QKeyEvent *event) {
    QGraphicsItem::keyPressEvent(event);

    if(event->key()==Qt::Key::Key_S){
        down();
    }
    else if(event->key()==Qt::Key::Key_W){
        Up();
    }
    else if(event->key()==Qt::Key::Key_A){
        left();
    }
    else if(event->key()==Qt::Key::Key_D){
        right();
    }
    else if(event->key()==Qt::Key::Key_Down){
        down2();
    }
    else if(event->key()==Qt::Key::Key_Up){
        Up2();
    }
    else if(event->key()==Qt::Key::Key_Left){
        left2();
    }
    else if(event->key()==Qt::Key::Key_Right){
        right2();
    }

}



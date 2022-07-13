//
// Created by IHC on 7/11/2022.
//

#include "Controller.h"
Controller::Controller() {
    animator = new QPropertyAnimation(this, "height", this);
    animator2 = new QPropertyAnimation(this, "width", this);
    animator3=new QPropertyAnimation(,,);
    animator4=new QPropertyAnimation(,,);
}

void Controller::down() {
    animator->stop();
    animator->setStartValue( y());
    animator->setEndValue(y()+75);
    animator->setDuration(200/getSpeed());
    animator->start();
}
void Controller::right() {
    animator2->stop();
    animator2->setStartValue( x());
    animator2->setEndValue(x()+75);
    animator2->setDuration(200/getSpeed());
    animator2->start();
}
void Controller::left() {
    animator2->stop();
    animator2->setStartValue( x());
    animator2->setEndValue(x()-75);
    animator2->setDuration(200/getSpeed());
    animator2->start();
}




void Controller::Up() {
    animator->stop();
    animator->setStartValue( y());
    animator->setEndValue(y()-75);
    animator->setDuration(200/getSpeed());
    animator->start();

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

};


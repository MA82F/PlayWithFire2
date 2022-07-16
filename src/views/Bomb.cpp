//
// Created by Asus on 7/14/2022.
//

#include "Bomb.h"
bool Bomb::bombNumber{false};
Bomb::Bomb(int width, int height):width(width),height(height) {
    //QList<Bomb*> BombList;
    QPixmap pixmap2(":/images/Bomb2");
    if (!bombNumber) {
        QPixmap pixmap1(":/images/Bomb1");
        pixmap1 = pixmap1.scaled(width - 60, height - 7);
        setPixmap(pixmap1);
        bombNumber = true;
    }
    else {
        pixmap2 = pixmap2.scaled(width - 20, height - 7);
        setPixmap(pixmap2);
        bombNumber = false;
    }
    bombTimer = new QTimer();
    bombTimer->setInterval(2000);
    connect(bombTimer,&QTimer::timeout,this,&Bomb::boom);
    bombTimer->start();
}
void Bomb::boom(){
    QPixmap pixmap(":/images/boom");
    pixmap = pixmap.scaled(width-10, height-6 );
    setPixmap(pixmap);
}



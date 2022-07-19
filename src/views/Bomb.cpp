//
// Created by Asus on 7/14/2022.
//

#include "Bomb.h"
bool Bomb::bombNumber{false};
Bomb::Bomb(int width, int height,int counter):width(width),height(height) {
    //QList<Bomb*> BombList;
    if (counter==1){
    QPixmap pixmap2(":/images/Bomb2");
        pixmap2 = pixmap2.scaled(width - 20, height - 7);
        setPixmap(pixmap2);}
    if (counter==2) {
        QPixmap pixmap1(":/images/Bomb1");
        pixmap1 = pixmap1.scaled(width - 20, height - 7);
        setPixmap(pixmap1);
//        bombNumber = true;
    }
//    else {
//        bombNumber = false;
//    }
//    bombTimer = new QTimer();
//    bombTimer->setInterval(5000);
//    connect(bombTimer,&QTimer::timeout,this,&Bomb::boom);
//    bombTimer->start();
}
//void Bomb::boom(){
//    //QPixmap pixmap(":/images/boom");
//    //pixmap = pixmap.scaled(width-10, height-6 );
//    //setPixmap(pixmap);
//    bombTimer->stop();
//}



//
// Created by Asus on 7/14/2022.
//

#include "Bomb.h"
bool Bomb::bombNumber{false};
Bomb::Bomb(int width, int height) {
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
}



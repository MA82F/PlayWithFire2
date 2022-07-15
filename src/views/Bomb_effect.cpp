//
// Created by IHC on 7/14/2022.
//

#include "Bomb_effect.h"

Bomb_effect::Bomb_effect(int width, int height):QGraphicsPixmapItem() {
    QPixmap pixmap(":/images/boom");
    pixmap = pixmap.scaled(width,height);
    setPixmap(pixmap);
}

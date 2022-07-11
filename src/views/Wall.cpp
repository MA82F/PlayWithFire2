//
// Created by IHC on 7/11/2022.
//

#include "Wall.h"

Wall::Wall(int width, int height): QGraphicsPixmapItem() {
    QPixmap pixmap(":/images/wall");
    pixmap = pixmap.scaled(width,height);
    setPixmap(pixmap);
}

//
// Created by IHC on 7/14/2022.
//

#include "Bomb_effect.h"
#include "Block.h"
#include "Wall.h"

Bomb_effect::Bomb_effect(int width, int height) : QGraphicsPixmapItem() {
    QPixmap pixmap(":/images/boom");
    pixmap = pixmap.scaled(width, height);
    setPixmap(pixmap);

}

void Bomb_effect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QGraphicsPixmapItem::paint(painter, option, widget);
    for (QGraphicsItem *item: collidingItems()) {
        Wall *wall = dynamic_cast<Wall *>(item);
        Block *box=dynamic_cast<Block*>(item);
        if (wall != nullptr) {
            emit clash(this);
        }
         if(box!= nullptr){
            emit Box_removed(box);
           // scene()->removeItem(box);
//            delete box;
//            scene()->removeItem(this);
//            blocks.removeOne(block);
        }

    }
}

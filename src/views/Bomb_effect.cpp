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
        Block *block = dynamic_cast<Block *>(item);
        if (block != nullptr) {
            emit clash(this);
        }
    }
}

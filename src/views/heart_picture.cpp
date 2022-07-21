#include "heart_picture.h"

heart_picture::heart_picture(int width, int height) {
    QPixmap pixmap(":/images/heart");
    pixmap = pixmap.scaled(width,height);
    setPixmap(pixmap);
}

void heart_picture::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QGraphicsPixmapItem::paint(painter, option, widget);
    for (QGraphicsItem *item: collidingItems()) {
        Player* temp_player=dynamic_cast<Player*>(item);
            if(temp_player!= nullptr){
                ++(temp_player->lifeCount);
                name = temp_player->name;
                emit heart_clash(this);
            }

    }
}

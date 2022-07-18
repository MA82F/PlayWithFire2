//
// Created by IHC on 7/12/2022.
//

#include "Player.h"
#include "Bomb_effect.h"

bool Player::numPlayer{false};
Player::Player(QString name,int width, int height) {
    setFlags(GraphicsItemFlag::ItemIsFocusable);
    setFocus();
    QPixmap pixmap2(":/images/player2-1");
    if (!numPlayer) {
        QPixmap pixmap1(":/images/player1-1");
        pixmap1 = pixmap1.scaled(width - 20, height - 15);
        setPixmap(pixmap1);
        numPlayer = true;
    }
    else {
        pixmap2 = pixmap2.scaled(width - 20, height - 15);
        setPixmap(pixmap2);
        numPlayer = false;
    }
}

int Player::getSpeed() {
    return speed;
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QGraphicsPixmapItem::paint(painter, option, widget);
    for (QGraphicsItem *item: collidingItems()) {
        Bomb_effect *bombEf = dynamic_cast<Bomb_effect *>(item);
//        Block *box=dynamic_cast<Block*>(item);
        if (bombEf != nullptr) {
            emit check(this);
//            scene()->removeItem(this);
        }
//        if(box!= nullptr){
//            emit Box_removed(box);
//            // scene()->removeItem(box);
////            delete box;
////            scene()->removeItem(this);
////            blocks.removeOne(block);
//        }

    }
}

//
// Created by IHC on 7/12/2022.
//

#include "Player.h"
#include "Bomb_effect.h"
bool Player::checkLife{false};
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
        if(checkLife == false){
            if (bombEf != nullptr) {
                checkLife = true;
                emit check(this);
            }
        }
    }
}

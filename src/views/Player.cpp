#include "Player.h"

bool Player::checkLife{false};
bool Player::numPlayer{false};
bool Player::checkCountLife{false};

Player::Player(QString name,QString heart,QString sp,int width, int height):name(name) {
    setFlags(GraphicsItemFlag::ItemIsFocusable);
    setFocus();

    lifeCount = heart.toInt();
    speed = sp.toDouble();

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
        else if(lifeCount == 0){
            if(checkCountLife == false){
                checkCountLife = true;
                emit gameOver(this);
            }
        }
    }
}

//
// Created by IHC on 7/12/2022.
//

#include "Player.h"

bool Player::numPlayer{false};
Player::Player(QString name,int width, int height) {
    QPixmap pixmap2(":/images/player2-1");
    if (!numPlayer) {
        QPixmap pixmap1(":/images/player1-1");
        pixmap1 = pixmap1.scaled(width - 20, height - 7);
        setPixmap(pixmap1);
        numPlayer = true;
    }
    else {
        pixmap2 = pixmap2.scaled(width - 20, height - 7);
        setPixmap(pixmap2);
        numPlayer = false;
    }
}

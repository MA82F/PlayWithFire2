//
// Created by Asus on 7/16/2022.
//

#include "playerspictures.h"

playerspictures::playerspictures(int width,int height) {
    QPixmap UP(":/images/cahr1_to_up_2");
    UP = UP.scaled(width - 20, height - 7);
    QPixmap DOWN(":/images/cahr1_to_down_2");
    DOWN = DOWN.scaled(width - 20, height - 7);
    QPixmap LEFT(":/images/cahr1_to_right_2");
    LEFT = LEFT.scaled(width - 20, height - 7);
    QPixmap RIGHT(":/images/cahr1_to_left_2");
    RIGHT = RIGHT.scaled(width - 20, height - 7);
    setPixmap(UP);
    setPixmap(DOWN);
    setPixmap(LEFT);
    setPixmap(RIGHT);
    ImagesPlayer1.append(UP);
    ImagesPlayer1.append(DOWN);
    ImagesPlayer1.append(RIGHT);
    ImagesPlayer1.append(LEFT);
    //////////////////////////////////////////////////
    QPixmap UP2(":/images/char2_to_up_2");
    UP2 = UP2.scaled(width - 20, height - 7);
    QPixmap DOWN2(":/images/char2_to_down_2");
    DOWN2= DOWN2.scaled(width - 20, height - 7);
    QPixmap LEFT2(":/images/char2_to_right_1");
    LEFT2 = LEFT2.scaled(width - 20, height - 7);
    QPixmap RIGHT2(":/images/char2_to_left_1");
    RIGHT2 = RIGHT2.scaled(width - 20, height - 7);
    setPixmap(UP2);
    setPixmap(DOWN2);
    setPixmap(LEFT2);
    setPixmap(RIGHT2);
    ImagesPlayer2.append(UP2);
    ImagesPlayer2.append(DOWN2);
    ImagesPlayer2.append(RIGHT2);
    ImagesPlayer2.append(LEFT2);

}

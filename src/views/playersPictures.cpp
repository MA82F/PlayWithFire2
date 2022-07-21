#include "playersPictures.h"

playersPictures::playersPictures(int width, int height) {
    QPixmap UP1(":/images/char1_to_up_2");
    UP1 = UP1.scaled(width - 20, height - 7);

    QPixmap RIGHT1(":/images/char1_to_left_2");
    RIGHT1 = RIGHT1.scaled(width - 20, height - 7);

    QPixmap DOWN1(":/images/char1_to_down_2");
    DOWN1 = DOWN1.scaled(width - 20, height - 7);

    QPixmap LEFT1(":/images/char1_to_right_2");
    LEFT1 = LEFT1.scaled(width - 20, height - 7);

    setPixmap(UP1);
    setPixmap(RIGHT1);
    setPixmap(DOWN1);
    setPixmap(LEFT1);

    ImagesPlayer1.append(UP1);
    ImagesPlayer1.append(DOWN1);
    ImagesPlayer1.append(RIGHT1);
    ImagesPlayer1.append(LEFT1);

//----------------------------------------------------------------------------------------------------------------------

    QPixmap UP2(":/images/char2_to_up_2");
    UP2 = UP2.scaled(width - 20, height - 7);

    QPixmap RIGHT2(":/images/char2_to_left_1");
    RIGHT2 = RIGHT2.scaled(width - 20, height - 7);

    QPixmap DOWN2(":/images/char2_to_down_2");
    DOWN2= DOWN2.scaled(width - 20, height - 7);

    QPixmap LEFT2(":/images/char2_to_right_1");
    LEFT2 = LEFT2.scaled(width - 20, height - 7);

    setPixmap(UP2);
    setPixmap(DOWN2);
    setPixmap(LEFT2);
    setPixmap(RIGHT2);

    ImagesPlayer2.append(UP2);
    ImagesPlayer2.append(DOWN2);
    ImagesPlayer2.append(RIGHT2);
    ImagesPlayer2.append(LEFT2);
}

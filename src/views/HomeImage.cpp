#include "HomeImage.h"

HomeImage::HomeImage(int width, int height) {
    QPixmap pixmap(":/images/home_image");
    pixmap = pixmap.scaled(width,height);
    setPixmap(pixmap)
    ;}

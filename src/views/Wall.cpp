#include "Wall.h"

Wall::Wall(int width, int height): Block() {
    QPixmap pixmap(":/images/wall");
    pixmap = pixmap.scaled(width,height);
    setPixmap(pixmap);
    type = 0;
}

#include "Box.h"

Box::Box(int width,int height): Block() {
    QPixmap pixmap(":/images/box");
    pixmap = pixmap.scaled(width,height);
    setPixmap(pixmap);
    type = 1;
}

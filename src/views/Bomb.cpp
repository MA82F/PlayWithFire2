#include "Bomb.h"

Bomb::Bomb(int width, int height,int counter):width(width),height(height) {
    if (counter==1){
    QPixmap pixmap2(":/images/Bomb2");
        pixmap2 = pixmap2.scaled(width - 20, height - 7);
        setPixmap(pixmap2);}
    if (counter==2) {
        QPixmap pixmap1(":/images/Bomb1");
        pixmap1 = pixmap1.scaled(width - 20, height - 7);
        setPixmap(pixmap1);
    }
}

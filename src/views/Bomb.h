#ifndef PLAYWITHFIRE2_BOMB_H
#define PLAYWITHFIRE2_BOMB_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>
#include "Block.h"

class Bomb :public QObject,public  QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bomb(int width, int height,int counter);

    int width;
    int height;
};


#endif //PLAYWITHFIRE2_BOMB_H

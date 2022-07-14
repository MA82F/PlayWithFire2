//
// Created by Asus on 7/14/2022.
//

#ifndef PLAYWITHFIRE2_BOMB_H
#define PLAYWITHFIRE2_BOMB_H
#include <QGraphicsPixmapItem>

class Bomb :public  QGraphicsPixmapItem{
    static bool bombNumber;
public:
    Bomb(int width, int height);
    //QList<Bomb*> BombList;
};


#endif //PLAYWITHFIRE2_BOMB_H

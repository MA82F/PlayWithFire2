//
// Created by Asus on 7/14/2022.
//

#ifndef PLAYWITHFIRE2_BOMB_H
#define PLAYWITHFIRE2_BOMB_H
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>
#include "Block.h"

class Bomb :public QObject,public  QGraphicsPixmapItem{
    Q_OBJECT
    static bool bombNumber;
public:
    Bomb(int width, int height,int counter);
    QTimer *bombTimer;


    int width;
    int height;
//public slots:
//    void boom();
};


#endif //PLAYWITHFIRE2_BOMB_H

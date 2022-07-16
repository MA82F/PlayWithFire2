//
// Created by Asus on 7/14/2022.
//

#ifndef PLAYWITHFIRE2_BOMB_H
#define PLAYWITHFIRE2_BOMB_H
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>

class Bomb :public QObject,public  QGraphicsPixmapItem{
    Q_OBJECT
    static bool bombNumber;
public:
    int width;
    int height;
    Bomb(int width, int height);
    QTimer *bombTimer;
public slots:
    void boom();
};


#endif //PLAYWITHFIRE2_BOMB_H

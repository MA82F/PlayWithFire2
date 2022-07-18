//
// Created by IHC on 7/14/2022.
//

#ifndef PLAYWITHFIRE2_BOMB_EFFECT_H
#define PLAYWITHFIRE2_BOMB_EFFECT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsView>
//#include "../windows/Game.h"
#include <QList>

class Bomb_effect : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
public:
    Bomb_effect(int width, int height);


    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    Bomb_effect *tempBoom;
signals:
    void clash(Bomb_effect *tempBomb_effect);

};


#endif //PLAYWITHFIRE2_BOMB_EFFECT_H

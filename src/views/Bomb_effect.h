//
// Created by IHC on 7/14/2022.
//

#ifndef PLAYWITHFIRE2_BOMB_EFFECT_H
#define PLAYWITHFIRE2_BOMB_EFFECT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QList>
#include "Block.h"
#include "Wall.h"
#include "Box.h"

class Bomb_effect : public QObject, public QGraphicsPixmapItem {
Q_OBJECT

public:
    Bomb_effect(int width, int height);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

signals:
    void clash(Bomb_effect *tempBomb_effect);
    void Box_removed(Block* box_remove);

};


#endif //PLAYWITHFIRE2_BOMB_EFFECT_H

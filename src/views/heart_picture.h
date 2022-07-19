//
// Created by Asus on 7/19/2022.
//

#ifndef PLAYWITHFIRE2_HEART_PICTURE_H
#define PLAYWITHFIRE2_HEART_PICTURE_H
#include <QGraphicsPixmapItem>
#include "playerspictures.h"
#include "Player.h"
#include <QObject>

class heart_picture:public QObject,public QGraphicsPixmapItem {
Q_OBJECT
public:
    heart_picture(int width,int height);
    QString name;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    signals:
    void heart_clash(heart_picture*);
};


#endif //PLAYWITHFIRE2_HEART_PICTURE_H

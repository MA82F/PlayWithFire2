//
// Created by Asus on 7/16/2022.
//

#ifndef PLAYWITHFIRE2_PLAYERSPICTURES_H
#define PLAYWITHFIRE2_PLAYERSPICTURES_H
#include <QGraphicsPixmapItem>
//#include <QPixmap>
#include <QList>

class playerspictures: public QGraphicsPixmapItem{
public:
    playerspictures(int width,int height);
    QList<QPixmap>ImagesPlayer1;
    QList<QPixmap>ImagesPlayer2;
};


#endif //PLAYWITHFIRE2_PLAYERSPICTURES_H

//
// Created by Asus on 7/12/2022.
//

#include "Result.h"

Result::Result(){
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();

    auto scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,width(),height());
    scene->setBackgroundBrush(QBrush("#211C16"));
    setScene(scene);

    auto ImageWidth = width() / 5;
    auto ImageHeight = height() /5;

    auto cupImage = new cup_image(ImageWidth, ImageHeight);
    scene->addItem(cupImage);
    cupImage->setPos((width()-ImageWidth)/2,0);

    auto winner = new you_win(ImageWidth, ImageHeight);
    scene->addItem(winner);
    winner->setPos((width()-ImageWidth)/2,(width()-ImageWidth)/7);

    auto label = new Label();
    label->setPlainText("NAME:");
    scene->addItem(label);
    label->setPos(width()/8,height()/2 - label->boundingRect().height());

    auto label2 = new Label();
    label2->setPlainText("SCORE:");
    scene->addItem(label2);
    label2->setPos(width()/1.5,height()/2 - label2->boundingRect().height());

//if(){
//    auto label3 = new Label();
//    label3->setPlainText("");
//    scene->addItem(label3);
//    label3->setPos(width()/2,height()/2 - label3->boundingRect().height());
//}
}
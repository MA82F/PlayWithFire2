//
// Created by IHC on 7/11/2022.
//

#include "Home.h"
#include "../views/TextField.h"
#include "../views/Label.h"
#include "../views/Button.h"
#include "Game.h"
#include "../SaveToFile.h"

Home::Home() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();

    auto scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,width(),height());
    scene->setBackgroundBrush(QBrush("#211C16"));
    setScene(scene);
    auto ImageWidth = width() / 2;
    auto ImageHeight = height() /2;
    auto homeImage = new HomeImage(ImageWidth, ImageHeight);
    scene->addItem(homeImage);
    homeImage->setPos((width()-ImageWidth)/2,0);

    textField1 = new TextField(400,50);
//    textField1->setPlainText();
    scene->addItem(textField1);
    textField1->setPos(width()/2-200,height()/2);

    auto label = new Label();
    label->setPlainText("Name no.1 player:");
    scene->addItem(label);
    label->setPos(width()/2-200,height()/2 - label->boundingRect().height());

    textField2 = new TextField(400,50);
    textField2->setPlainText("saved name");
    scene->addItem(textField2);
    textField2->setPos(width()/2-200,height()/2+85);

    auto label2 = new Label();
    label2->setPlainText("Name no.2 player:");
    scene->addItem(label2);
    label2->setPos(width()/2-200,height()/2 - label->boundingRect().height()+90);

    auto button = new Button(400,150);
    button->setPlainText("");
    scene->addItem(button);
    button->setPos(width()/2-200,height()/2 + button->boundingRect().height()+25);
    connect(button,&Button::onPress,this,&Home::onGameStart);
}

void Home::onGameStart() {
    auto name1 = textField1->toPlainText();
    auto name2=textField2->toPlainText();
    SaveToFile file(name1,name2);
    close();
    (new Game(name1,name2))->show();
}

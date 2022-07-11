//
// Created by IHC on 7/11/2022.
//

#include "Home.h"
#include "../views/TextField.h"
#include "../views/Label.h"
#include "../views/Button.h"
#include "Game.h"

Home::Home() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();

    auto scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,width(),height());
    scene->setBackgroundBrush(QColor("#2F2627"));
    setScene(scene);

    textField = new TextField(400,150);
    textField->setPlainText("saved name");
    scene->addItem(textField);
    textField->setPos(width()/2,height()/2);

    auto label = new Label();
    label->setPlainText("Name:");
    scene->addItem(label);
    label->setPos(width()/2,height()/2 - label->boundingRect().height());

    auto button = new Button(400,150);
    button->setPlainText("      Start Game:");
    scene->addItem(button);
    button->setPos(width()/2,height()/2 + button->boundingRect().height()+15);
    connect(button,&Button::onPress,this,&Home::onGameStart);
}

void Home::onGameStart() {
    auto name = textField->toPlainText();
    close();
    (new Game(name))->show();
}

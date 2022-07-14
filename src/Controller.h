#ifndef PLAYWITHFIRE2_CONTROLLER_H
#define PLAYWITHFIRE2_CONTROLLER_H
#include "../src/views/Player.h"
#include <QObject>
#include <QList>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include "views/Block.h"
#include "views/Bomb.h"
#include "windows/Game.h"

class Controller: public QObject,public QGraphicsPixmapItem{
Q_OBJECT
protected:
    Q_PROPERTY(qreal height READ y WRITE setY);
    Q_PROPERTY(qreal width READ x WRITE setX);
public:
    qreal newX1, newY1, newX2, newY2,newX3,newY3,newX4,newY4;
    int speedplayers;
    QList <Player*> tempPlayers{};
    QList <Block*> tempBlocks{};
    QList<Bomb*>tempBombList;
    Controller(QList<Player *> players,QList <Block*> blocks,QList<Bomb*>BombList);
private:
    QPropertyAnimation *animator1;
protected:
//    void keyReleaseEvent(QKeyEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
private:
    QPropertyAnimation *animator2;
    QPropertyAnimation *animator3;
    QPropertyAnimation *animator4;
public slots:
    void down();

    void Up();

    void right();

    void left();
    void down2();

    void Up2();

    void right2();

    void left2();

    void bomb1();

    void bomb2();
};

#endif //PLAYWITHFIRE2_CONTROLLER_H

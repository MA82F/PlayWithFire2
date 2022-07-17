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
#include <QTimer>
#include "views/Bomb_effect.h"

class Controller: public QObject,public QGraphicsPixmapItem{
Q_OBJECT
public:
    QTimer* bombTimer;
protected:
    Q_PROPERTY(qreal height READ y WRITE setY);
    Q_PROPERTY(qreal width READ x WRITE setX);
public:
    static bool bombKey1;
    qreal newX1, newY1, newX2, newY2,newX3,newY3,newX4,newY4;
    int speedplayers;
    QList <Player*> tempPlayers{};
    QList <Block*> tempBlocks{};
    QList<Bomb*>tempBombList;
    //QList<Bomb_effect*>tempBooms;
    Bomb_effect *boom;
    Controller(QList<Player *> players,QList <Block*> blocks);
private:
    QPropertyAnimation *animator1;
protected:
//    void keyReleaseEvent(QKeyEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
private:
    QPropertyAnimation *animator2;
    QPropertyAnimation *animator3;
    QPropertyAnimation *animator4;
public :
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
public slots:
    void bombTimerTime();
    signals:
    void bomb1_called();
    void bomb2_called();
    void player1_up();
    void player2_up();
    void player1_down();
    void player2_down();
    void player1_left();
    void player2_left();
    void player1_right();
    void player2_right();
};

#endif //PLAYWITHFIRE2_CONTROLLER_H

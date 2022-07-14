#ifndef PLAYWITHFIRE2_CONTROLLER_H
#define PLAYWITHFIRE2_CONTROLLER_H
#include "../src/views/Player.h"
#include <QObject>
#include <QList>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include "views/Block.h"

class Controller: public QObject,public QGraphicsPixmapItem {
Q_OBJECT
protected:
    void keyPressEvent(QKeyEvent *event) override;
    Q_PROPERTY(qreal height READ y WRITE setY);
    Q_PROPERTY(qreal width READ x WRITE setX);
public:
    qreal yp1, yp2, xp1, xp2;
    int speedplayers;
    QList <Player*> tempPlayers{};
    QList <Block*> tempBlocks{};
    Controller(QList<Player *> players,QList <Block*> blocks);
private:
    QPropertyAnimation *animator1;
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
};

#endif //PLAYWITHFIRE2_CONTROLLER_H

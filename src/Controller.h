#ifndef PLAYWITHFIRE2_CONTROLLER_H
#define PLAYWITHFIRE2_CONTROLLER_H

#include "../src/views/Player.h"
#include <QList>
#include <QTimer>
#include <QWidget>
#include <QObject>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QWidgetData>
#include "views/Block.h"
#include "views/Bomb.h"
#include "views/Bomb_effect.h"
#include "windows/Game.h"

class Controller: public QObject, public QGraphicsPixmapItem{
Q_OBJECT
public:
    Controller(QList<Player *> players, QList <Block*> *blocks);

    QTimer* bombTimer1;
    QTimer* bombTimer2;

    static bool bombKey1;
    static bool bombKey2;

    qreal newX1, newY1,newX2, newY2;

    double speedPlayers;

    QList <Player*> tempPlayers{};
    QList <Block*>  *tempBlocks{};
    QList <Bomb*>   tempBombList;

protected:
    void keyPressEvent(QKeyEvent *event) override;

public :
    void Up1();
    void down1();
    void right1();
    void left1();

    void Up2();
    void right2();
    void down2();
    void left2();

    void bomb1();
    void bomb2();

public slots:
    void bombTimerTime1();
    void bombTimerTime2();

signals:
    void bomb1_called();
    void bomb2_called();

    void player1_up();
    void player1_right();
    void player1_down();
    void player1_left();

    void player2_up();
    void player2_right();
    void player2_down();
    void player2_left();
};

#endif //PLAYWITHFIRE2_CONTROLLER_H

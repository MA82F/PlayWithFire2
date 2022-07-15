#ifndef PLAYWITHFIRE2_GAME_H
#define PLAYWITHFIRE2_GAME_H
#include <QGraphicsView>
#include "../views/Wall.h"
#include "../views/Player.h"
#include "../views/Box.h"
#include "../views/Block.h"
#include "../views/Box_Place.h"
#include "../views/Bomb.h"
#include "../views/Bomb_effect.h"
//#include <QTimer>

class Game: public QGraphicsView{
    Q_OBJECT
//private:
//    QTimer* bombTimer;
public:
    QList <Player*> players{};
    QList <Block*> blocks{};
    QList<Bomb*>BombList;
    QList<Bomb_effect*> booms;
    int numOfBox;
    Game(QString name1,QString name2);
//public slots:
//    void boom();
};


#endif //PLAYWITHFIRE2_GAME_H

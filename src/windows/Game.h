#ifndef PLAYWITHFIRE2_GAME_H
#define PLAYWITHFIRE2_GAME_H

#include <QGraphicsView>
#include "../views/Wall.h"
#include "../views/Player.h"
#include "../views/Box.h"
#include "../views/Block.h"
#include "../views/Box_Place.h"

class Game: public QGraphicsView{
public:
    QList <Player*> players{};
    QList <Block*> blocks{};
    int numOfBox;
    Game(QString name1,QString name2);
};


#endif //PLAYWITHFIRE2_GAME_H

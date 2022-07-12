#ifndef PLAYWITHFIRE2_GAME_H
#define PLAYWITHFIRE2_GAME_H

#include <QGraphicsView>
#include "../views/box_position.h"

class Game: public QGraphicsView{
public:
    int numOfBox;
    Game(QString name1,QString name2);
};


#endif //PLAYWITHFIRE2_GAME_H

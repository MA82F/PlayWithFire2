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
#include "../views/playerspictures.h"
//#include <iostream>

class Game: public QGraphicsView{
    Q_OBJECT
//private:
//    QTimer* bombTimer;
public:
    QList <Player*> players{};
    QList <Block*> blocks{};
    Bomb*Bomb1;
    QList<Bomb_effect*> booms;
    int numOfBox;
    Game(QString name1,QString name2);
    playerspictures* pPicture=new playerspictures(70,50);
    QTimer* bombTimer;

public slots:
    void boom();
    void p1Up();
    void p2Up();
    void p1Down();
    void p2Down();
    void p1Left();
    void p2Left();
    void p1Right();
    void p2Right();
    void bomb_remover();
};


#endif //PLAYWITHFIRE2_GAME_H

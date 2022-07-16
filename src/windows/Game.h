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
#include <QTimer>
#include <QList>
#include "../views/playerspictures.h"

class Game: public QGraphicsView{
    Q_OBJECT
//private:
public:
    QList <Player*> players{};
    QList <Block*> blocks{};
    QList<Bomb*>BombList;
    Bomb * bomb1;
//    QList<Bomb_effect*> booms;
    QTimer* bombTimer;
    int numOfBox;
    Game(QString name1,QString name2);
    playerspictures* pPicture=new playerspictures(60,40);
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
    void bombRemove();
};


#endif //PLAYWITHFIRE2_GAME_H

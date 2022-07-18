#ifndef PLAYWITHFIRE2_GAME_H
#define PLAYWITHFIRE2_GAME_H

#include <QGraphicsView>
#include "../views/Wall.h"
#include "../views/Player.h"
#include "../views/Block.h"
#include "../views/Box_Place.h"
#include "../views/Bomb.h"
#include "../views/Bomb_effect.h"
#include "../Controller.h"
#include <QTimer>
#include <QList>
#include "../views/playerspictures.h"
#include "../views/Box.h"
#include "../views/Label.h"

class Game : public QGraphicsView {
Q_OBJECT
public:
    QList<Player *> players{};
    QList<Block *> blocks{};
    QList<Bomb *> BombList;
//    QList<Box*>*boxese{};
    Label *playerLife;
    Label *playerScore;
//    QString *life1;
    Bomb *bomb1{nullptr};
    Bomb *bomb2{nullptr};
    QTimer *bombTimer{};
    QTimer *boomTimer{};
    int numOfBox;
//    Box* temprory{nullptr};
    Game(QString name1, QString name2);

    playerspictures *pPicture = new playerspictures(60, 40);

//    bool bomb1X();

    //* tempBoom;
    QList<Bomb_effect *> BoomTemplate;
public slots:
    void boom1();
    void boom2();
    void p1Up();
    void p2Up();
    void p1Down();
    void p2Down();
    void p1Left();
    void p2Left();
    void p1Right();
    void p2Right();
    void gameOver1();
    void gameOver2();
    void bombRemove1();
    void bombRemove2();
    void Box_Remover(Block* temp_Box);
    void boomRemoverTest(Bomb_effect *tempBombeffect);
    void lowHeart(Player *tempPlayer);
//    void lowLife();
    void allBoomRemover();
//    signals:
//    void life();

};


#endif //PLAYWITHFIRE2_GAME_H

#ifndef PLAYWITHFIRE2_GAME_H
#define PLAYWITHFIRE2_GAME_H

#include <QGraphicsView>
#include <QTimer>
#include <QList>
#include <QList>
#include <ctime>
#include <QTimer>
#include <QWidget>
#include "Result.h"
#include "../Controller.h"
#include "../views/Wall.h"
#include "../views/Player.h"
#include "../views/Block.h"
#include "../views/Bomb_effect.h"
#include "../views/Bomb.h"
#include "../views/Bomb_effect.h"
#include "../views/Box.h"
#include "../views/Box_Place.h"
#include "../views/playersPictures.h"
#include "../views/Label.h"
#include "../views/heart_picture.h"

class Game : public QGraphicsView {
Q_OBJECT
public:
    int numOfBoxes{50};
    QList<Player *> players{};
    QList<Block *> blocks{};
    QList<Bomb *> BombList;

    QList<heart_picture*>hearts;

    Label *playerLife1;
    Label *playerLife2;

    Label *playerScore1;
    Label *playerScore2;

    Bomb *bomb1{nullptr};
    Bomb *bomb2{nullptr};

    QTimer *bombTimer1{};
    QTimer *bombTimer2{};

    QTimer *boomTimer1{};
    QTimer *boomTimer2{};

    int numOfBox;

    Game(QString name1, QString name2);

    playersPictures *pPicture = new playersPictures(60, 40);

    QList<Bomb_effect *> BoomTemplate;
    QList<Bomb_effect *> BoomTemplate2;

public slots:
    void boom1();
    void boom2();

    void p1Up();
    void p1Right();
    void p1Down();
    void p1Left();

    void p2Up();
    void p2Right();
    void p2Down();
    void p2Left();

    void gameOver1();
    void gameOver2();

    void bombRemove1();
    void bombRemove2();

    void Box_Remover1(Block* temp_Box);
    void Box_Remover2(Block* temp_Box);

    void boomRemoverTest(Bomb_effect *tempBombEffect);

    void lowHeart(Player *tempPlayer);

    void allBoomRemover();
    void allBoomRemover2();

    void checkNumOfBoxes();

    void heart_remover(heart_picture*);

};


#endif //PLAYWITHFIRE2_GAME_H

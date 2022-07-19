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
#include "../views/heart_picture.h"

class Game : public QGraphicsView {
Q_OBJECT
public:
    int numOfBoxes{50};
    QList<Player *> players{};
    QList<Block *> blocks{};
    QList<Bomb *> BombList;
    QList<heart_picture*>hearts;
//    QList<Box*>*boxese{};
    Label *playerLife1;
    Label *playerLife2;
    Label *playerScore1;
    Label *playerScore2;
//    QString *life1;
    Bomb *bomb1{nullptr};
    Bomb *bomb2{nullptr};
    QTimer *bombTimer{};
    QTimer *bombTimer2{};
    QTimer *boomTimer{};
    QTimer *boomTimer2{};
    int numOfBox;
//    Box* temprory{nullptr};
    Game(QString name1, QString name2);

    playerspictures *pPicture = new playerspictures(60, 40);

//    bool bomb1X();

    //* tempBoom;
    QList<Bomb_effect *> BoomTemplate;
    QList<Bomb_effect *> BoomTemplate2;

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
//    void gameOver1();
//    void gameOver2();
    void bombRemove1();
    void bombRemove2();
    void Box_Remover1(Block* temp_Box);
    void Box_Remover2(Block* temp_Box);
    void boomRemoverTest(Bomb_effect *tempBombeffect);
    void lowHeart(Player *tempPlayer);
    void allBoomRemover();
    void allBoomRemover2();
    void checkNumOfBoxes();
    void heart_remover(heart_picture*);

};


#endif //PLAYWITHFIRE2_GAME_H

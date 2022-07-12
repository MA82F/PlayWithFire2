#ifndef PLAYWITHFIRE2_PLAYER_H
#define PLAYWITHFIRE2_PLAYER_H

#include <QGraphicsPixmapItem>
#include <QString>

class Player :public QGraphicsPixmapItem{
private:
    static bool numPlayer;
    QString name{};
    int score{0};
    int bombCount{10};
    int lifeCount{3};
//    int speed;
    int bombRadius{3};

public:
    Player(QString name,int width, int height);
};
#endif //PLAYWITHFIRE2_PLAYER_H

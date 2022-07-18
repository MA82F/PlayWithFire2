#ifndef PLAYWITHFIRE2_PLAYER_H
#define PLAYWITHFIRE2_PLAYER_H

#include <QGraphicsPixmapItem>
#include <QString>
#include <QPropertyAnimation>
#include <QObject>
#include <QKeyEvent>
class Player :public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
    Q_PROPERTY(qreal height READ y WRITE setY);
    Q_PROPERTY(qreal width READ x WRITE setX);
private:
    static bool numPlayer;
    int bombCount{10};
    int speed{10};
    int bombRadius{3};
public:
    int lifeCount{3};
    int score{0};
    QString name{};
    static bool checkLife;


public:
    QPropertyAnimation *animator;
    QPropertyAnimation *animator2;
    Player(QString name,int width, int height);
    int getSpeed();
    int getScore();
    int setScore();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
signals:
    void check(Player *tempBomb_effect);
    void gameOver();
public slots:

};
#endif //PLAYWITHFIRE2_PLAYER_H

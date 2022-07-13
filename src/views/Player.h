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
    QString name{};
    int score{0};
    int bombCount{10};
    int lifeCount{3};
    int speed{1};
    int bombRadius{3};


public:
    QPropertyAnimation *animator;
    QPropertyAnimation *animator2;
    Player(QString name,int width, int height);
    int getSpeed();
public slots:
    void down();
    void Up();
    void right();
    void left();

};
#endif //PLAYWITHFIRE2_PLAYER_H

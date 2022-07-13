#ifndef PLAYWITHFIRE2_CONTROLLER_H
#define PLAYWITHFIRE2_CONTROLLER_H
#include "../src/views/Player.h"
#include <QObject>
#include <QKeyEvent>
class Controller: public QObject,public Player{
Q_OBJECT
    Q_PROPERTY(qreal height READ y WRITE setY);
    Q_PROPERTY(qreal width READ x WRITE setX);
public:
    Controller(QList <Player*> players);
    QPropertyAnimation *animator1;
    QPropertyAnimation *animator2;
    QPropertyAnimation *animator3;
    QPropertyAnimation *animator4;
    void down();
    void Up();
    void right();
    void left();

protected:
    void keyPressEvent(QKeyEvent *event) override;
}




#endif //PLAYWITHFIRE2_CONTROLLER_H

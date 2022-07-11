#ifndef PLAYWITHFIRE2_BUTTON_H
#define PLAYWITHFIRE2_BUTTON_H

#include <QGraphicsTextItem>

class Button:public QGraphicsTextItem {
    Q_OBJECT
private:
    int width{};
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    Button(int width,int height);
private:
    int height{};
signals:
    void onPress();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};


#endif //PLAYWITHFIRE2_BUTTON_H

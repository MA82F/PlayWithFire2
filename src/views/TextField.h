//
// Created by IHC on 7/11/2022.
//

#ifndef PLAYWITHFIRE2_TEXTFIELD_H
#define PLAYWITHFIRE2_TEXTFIELD_H

#include <QGraphicsTextItem>

class TextField: public QGraphicsTextItem{
private:
    int width{};
    int height{};
public:
    TextField(int width,int height);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};


#endif //PLAYWITHFIRE2_TEXTFIELD_H

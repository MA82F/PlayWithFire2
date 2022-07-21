#ifndef PLAYWITHFIRE2_TEXTFIELD_H
#define PLAYWITHFIRE2_TEXTFIELD_H

#include <QGraphicsTextItem>
#include <QFont>
#include <QPainter>
#include <QTextDocument>
#include <QStyleOptionGraphicsItem>

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
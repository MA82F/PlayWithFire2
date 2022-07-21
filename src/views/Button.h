#ifndef PLAYWITHFIRE2_BUTTON_H
#define PLAYWITHFIRE2_BUTTON_H

#include <QGraphicsTextItem>
#include <QFont>
#include <QTextDocument>
#include <QPainter>

class Button:public QGraphicsTextItem {
    Q_OBJECT

public:
    Button(int width,int height);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int width{};
    int height{};

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void onPress();
};


#endif //PLAYWITHFIRE2_BUTTON_H

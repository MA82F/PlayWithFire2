//
// Created by Asus on 7/12/2022.
//

#ifndef PLAYWITHFIRE2_RESULT_H
#define PLAYWITHFIRE2_RESULT_H
#include <QGraphicsView>
#include <QString>
#include "../views/cup_image.h"
#include "../views/you_win.h"
#include"../views/Label.h"

class Result: public QGraphicsView{
public:
    Result(QString name1,int score1,QString name2,int score2);
};


#endif

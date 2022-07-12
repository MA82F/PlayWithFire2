//
// Created by IHC on 7/11/2022.
//

#ifndef PLAYWITHFIRE2_HOME_H
#define PLAYWITHFIRE2_HOME_H
#include <QGraphicsView>
#include "../views/TextField.h"
#include "../views/HomeImage.h"

class Home:public QGraphicsView{
    Q_OBJECT
private:
    TextField *textField;
public:
    Home();
public slots:
    void onGameStart();
};


#endif //PLAYWITHFIRE2_HOME_H

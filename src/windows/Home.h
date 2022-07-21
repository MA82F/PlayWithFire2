#ifndef PLAYWITHFIRE2_HOME_H
#define PLAYWITHFIRE2_HOME_H

#include <QGraphicsView>
#include "../views/TextField.h"
#include "../views/HomeImage.h"
#include "../views/TextField.h"
#include "../views/Label.h"
#include "../views/Button.h"
#include "Game.h"

class Home:public QGraphicsView{
    Q_OBJECT

private:
    TextField *textField1;
    TextField *textField2;

public:
    Home();

public slots:
    void onGameStart();
};


#endif //PLAYWITHFIRE2_HOME_H

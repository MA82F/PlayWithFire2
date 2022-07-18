#include <QApplication>
#include <QPushButton>
#include "src/windows/Home.h"
#include "src/windows/Result.h"
#include "src/Controller.h"
#include "src/windows/Game.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    (new Home())->show();
    (new Result())->show();
//    (new Result())->show();
//    QObject::connect(Controller,&Controller::bomb1,Game,&Game::bomb_effect);

return QApplication::exec();
}

#include <QApplication>
#include <QPushButton>
#include "src/windows/Home.h"
#include "src/Controller.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    (new Home())->show();

return QApplication::exec();
}

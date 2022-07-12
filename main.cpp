#include <QApplication>
#include <QPushButton>
#include "src/windows/Home.h"
#include "src/windows/result.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    (new Home())->show();
    (new result())->show();
    return QApplication::exec();
}

//
// Created by IHC on 7/11/2022.
//

#include "SaveToFile.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
SaveToFile::SaveToFile(QString name1,QString name2) {
    QFile file("Last input.txt");
    file.open(QIODevice::ReadWrite);
    file.write("salam");
    file.flush();
    file.close();
    if(file.open(QIODevice::ReadWrite)) {
        QTextStream out(&file);
        out << name1 << "\n";
        out << name2 << "\n";
        file.flush();
        file.close();
    }
}

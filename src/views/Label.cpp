//
// Created by IHC on 7/11/2022.
//

#include "Label.h"
#include <Qfont>
#include <QTextDocument>

Label::Label() {
    setDefaultTextColor((QColor("white")));
    QFont font;
    font.setPixelSize(76);
    font.setBold(true);
    setFont(font);
    document()->setDocumentMargin(10);

}

#include "Label.h"

Label::Label() {
    setDefaultTextColor((QColor("white")));

    QFont font;
    font.setPixelSize(20);
    font.setBold(true);
    setFont(font);

    document()->setDocumentMargin(10);
}

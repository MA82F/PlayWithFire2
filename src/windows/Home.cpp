#include "Home.h"

Home::Home() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();

    auto scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,width(),height());
    scene->setBackgroundBrush(QBrush("#211C16"));
    setScene(scene);
    auto ImageWidth = width() / 2;
    auto ImageHeight = height() /2;
    auto homeImage = new HomeImage(ImageWidth, ImageHeight);
    scene->addItem(homeImage);
    homeImage->setPos((width()-ImageWidth)/2,0);

    //READ FROM FILE---------------------------------------
    QString name1;
    QString name2;
    QFile file("Lastinput.txt");
    if(file.exists()){
        file.open(QIODevice::ReadWrite);
        name1 = file.readLine();
        name2 = file.readLine();
        if(name2 =="\n")
            name2 = file.readLine();
        file.close();
    }
    //----------------------------------------------------
    textField1 = new TextField(400,50);
    textField1->setPlainText(name1);
    scene->addItem(textField1);
    textField1->setPos(width()/2-200,height()/2);

    auto label = new Label();
    label->setPlainText("Name no.1 player:");
    scene->addItem(label);
    label->setPos(width()/2-200,height()/2 - label->boundingRect().height());

    textField2 = new TextField(400,50);
    textField2->setPlainText(name2);
    scene->addItem(textField2);
    textField2->setPos(width()/2-200,height()/2+85);

    auto label2 = new Label();
    label2->setPlainText("Name no.2 player:");
    scene->addItem(label2);
    label2->setPos(width()/2-200,height()/2 - label->boundingRect().height()+90);

    auto button = new Button(400,150);
    button->setPlainText("");
    scene->addItem(button);
    button->setPos(width()/2-200,height()/2 + button->boundingRect().height()+25);
    connect(button,&Button::onPress,this,&Home::onGameStart);
}

void Home::onGameStart() {
    auto name1 = textField1->toPlainText();
    auto name2=textField2->toPlainText();
    //WRITE IN FILE-----------------------------------
    QFile file("Lastinput.txt");
    file.open(QIODevice::ReadWrite);
    file.write(name1.toUtf8());
    file.write("\n");
    file.write(name2.toUtf8());
    file.flush();
    file.close();
    //------------------------------------------------
    close();
    (new Game(name1,name2))->show();
}

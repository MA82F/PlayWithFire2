#include "Result.h"

Result::Result(QString name1,int score1,QString name2,int score2){
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();

    auto scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,width(),height());
    scene->setBackgroundBrush(QBrush("#211C16"));
    setScene(scene);

    auto ImageWidth = width() / 5;
    auto ImageHeight = height() /5;

    auto cupImage = new cup_image(ImageWidth, ImageHeight);
    scene->addItem(cupImage);
    cupImage->setPos((width()-ImageWidth)/2,0);

    auto winner = new you_win(ImageWidth, ImageHeight);
    scene->addItem(winner);
    winner->setPos((width()-ImageWidth)/2,(width()-ImageWidth)/7);

    if(score1 == score2){
        auto same = new Label();
        same->setPlainText(name1 + "="+ name2);
        scene->addItem(same);
        same->setPos(width()/8,height()/2 - same->boundingRect().height());
        auto score = new Label();
        score->setPlainText("SCORE: " + QString::number(score1));
        scene->addItem(score);
        score->setPos(width()/1.5,height()/2 - same->boundingRect().height());
    }
    else if(score2 > score1){
        std::swap(score1,score2);
        swap(name1,name2);
    }

    auto first = new Label();
    first->setPlainText("1ST: " + name1);
    scene->addItem(first);
    first->setPos(width()/8,height()/2 - first->boundingRect().height());
    auto firstScore = new Label();
    firstScore->setPlainText("SCORE: " + QString::number(score1));
    scene->addItem(firstScore);
    firstScore->setPos(width()/1.5,height()/2 - first->boundingRect().height());

    Sleep(1000);

    auto second = new Label();
    second->setPlainText("2ND: " + name2);
    scene->addItem(second);
    second->setPos(width()/8,height()/2 - second->boundingRect().height());
    auto secondScore = new Label();
    secondScore->setPlainText("SCORE: " + QString::number(score2));
    scene->addItem(secondScore);
    secondScore->setPos(width()/1.5,height()/2 - second->boundingRect().height());

    auto winnerName = new Label();
    winnerName->font().setPixelSize(72);
    winnerName->setPlainText("WINNER IS: \"" + name1 + "\"");
    scene->addItem(winnerName);
    winnerName->setPos(width()/3,height()-150);

}
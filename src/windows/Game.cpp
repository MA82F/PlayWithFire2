#include "Game.h"

Game::Game(QString name1, QString name2,QString heart,QString speed) : QGraphicsView() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();

    auto scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    scene->setBackgroundBrush(QColor("#211C16"));
    setScene(scene);

    auto blockWidth = width() / 15;
    auto blockHeight = height() / 15;
    auto playerWidth = width() / 15;
    auto playerHeight = height() / 15;

    auto player1 = new Player(name1,heart,speed, playerWidth, playerHeight);
    scene->addItem(player1);
    player1->setPos(playerWidth + 10, playerHeight + 3);

    auto player2 = new Player(name2,heart,speed, playerWidth, playerHeight);
    scene->addItem(player2);
    player2->setPos(playerWidth * 13 + 10, playerHeight * 13 + 3);

    players.append(player1);
    players.append(player2);

    for (int l = 0; l < 15; ++l) {
        for (int j = 0; j < 15; ++j) {
            if (l != 0 && l != 14 && j != 0 && j != 14 && (l % 2 != 0 || j % 2 != 0)) {
                continue;
            }
            auto wall = new Wall(blockWidth, blockHeight);
            scene->addItem(wall);
            wall->setPos(blockWidth * l, blockHeight * j);
            blocks.append(wall);
        }
    }

    srand(time(0));
    Box_Place positionOfBoxes[224];
    for (int temp = 0; temp < 224; temp++) {
        positionOfBoxes[temp].x = 100;
        positionOfBoxes[temp].y = 100;
    }
    numOfBox = 0;
    for (int i = 0; numOfBox < numOfBoxes+2; ++i) {
        int ii = rand() % 15;
        int jj = rand() % 15;
        if ((ii != 0 && ii != 14 && jj != 0 && jj != 14 && (ii % 2 != 0 || jj % 2 != 0))) {
            if (((ii != 13 || jj != 13) && (ii != 1 || jj != 1) && (ii != 12 || jj != 13) &&
                 (ii != 13 || jj != 12) && (ii != 1 || jj != 2) && (ii != 2 || jj != 1))){
                bool is_exist = false;
                for (int c = 0; c < i + 1; c++) {
                    if (positionOfBoxes[c].x == ii) {
                        if (positionOfBoxes[c].y == jj) {
                            is_exist = true;
                        }
                    }
                }
                if (is_exist == false) {
                    if (numOfBox != 48 && numOfBox != 49) {
                        auto box = new class Box(blockWidth, blockHeight);
                        scene->addItem(box);
                        box->setPos(blockWidth * ii, blockHeight * jj);
                        positionOfBoxes[i].x = ii;
                        positionOfBoxes[i].y = jj;
                        blocks.append(box);
                        ++numOfBox;
                    }
                    else {
                        auto heart = new heart_picture(blockWidth, blockHeight);
                        scene->addItem(heart);
                        heart->setPos(blockWidth * ii, blockHeight * jj);
                        positionOfBoxes[i].x = ii;
                        positionOfBoxes[i].y = jj;
                        hearts.append(heart);
                        ++numOfBox;
                    }
                }
            }
        }
    }

    playerLife1 = new Label();
    auto life1 =new QString(QString::number(players.
            at(0)->lifeCount));
    playerLife1->setPlainText("Player1: " + *life1);
    scene->addItem(playerLife1);
    playerLife1->setPos(blockWidth * 1.5, blockHeight / 5);

    playerScore1 = new Label();
    auto score1 = new QString(QString::number(players.at(0)->score));
    playerScore1->setPlainText("Player1 Score: " + *score1);
    scene->addItem(playerScore1);
    playerScore1->setPos(blockWidth * 1.5, height()- 50);

    playerLife2 = new Label();
    auto life2 =new QString(QString::number(players.at(1)->lifeCount));
    playerLife2->setPlainText("Player2: " + *life2);
    scene->addItem(playerLife2);
    playerLife2->setPos(blockWidth * 11, blockHeight / 5);

    playerScore2 = new Label();
    auto score2 = new QString(QString::number(players.at(1)->score));
    playerScore2->setPlainText("Player2 Score: " + *score2);
    scene->addItem(playerScore2);
    playerScore2->setPos(blockWidth * 11, height() - 50);

    auto controller = new Controller(players, &blocks);
    scene->addItem(controller);
    controller->setFocus();

    connect(controller, &Controller::bomb1_called, this, &Game::boom1);
    connect(controller, &Controller::bomb2_called, this, &Game::boom2);

    connect(controller, &Controller::player1_up, this, &Game::p1Up);
    connect(controller, &Controller::player1_right, this, &Game::p1Right);
    connect(controller, &Controller::player1_down, this, &Game::p1Down);
    connect(controller, &Controller::player1_left, this, &Game::p1Left);

    connect(controller, &Controller::player2_up, this, &Game::p2Up);
    connect(controller, &Controller::player2_right, this, &Game::p2Right);
    connect(controller, &Controller::player2_down, this, &Game::p2Down);
    connect(controller, &Controller::player2_left, this, &Game::p2Left);

    connect(players.at(0),&Player::check,this,&Game::lowHeart);
    connect(players.at(1),&Player::check,this,&Game::lowHeart);
    connect(players[0],&Player::gameOver,this,&Game::gameOver);
    connect(players[1],&Player::gameOver,this,&Game::gameOver);
    connect(hearts[0],&heart_picture::heart_clash, this, &Game::heart_remover);
    connect(hearts[1],&heart_picture::heart_clash, this, &Game::heart_remover);

}

void Game::gameOver(Player* temp){
    close();
    (new Result(temp->name,temp->score,players.at(1)->name,players.at(1)->score))->show();
}

//----------------------------------------------------------------------------------------------------------------------

void Game::p1Up() {
    players.at(0)->setPixmap(pPicture->ImagesPlayer1.at(0));

}

void Game::p1Right() {
    players.at(0)->setPixmap(pPicture->ImagesPlayer1.at(3));

}

void Game::p1Down() {
    players.at(0)->setPixmap(pPicture->ImagesPlayer1.at(1));

}

void Game::p1Left() {
    players.at(0)->setPixmap(pPicture->ImagesPlayer1.at(2));
}

//----------------------------------------------------------------------------------------------------------------------

void Game::p2Up() {
    players.at(1)->setPixmap(pPicture->ImagesPlayer2.at(0));
}

void Game::p2Right() {
    players.at(1)->setPixmap(pPicture->ImagesPlayer2.at(3));

}

void Game::p2Down() {
    players.at(1)->setPixmap(pPicture->ImagesPlayer2.at(1));
}

void Game::p2Left() {
    players.at(1)->setPixmap(pPicture->ImagesPlayer2.at(2));

}

//----------------------------------------------------------------------------------------------------------------------

void Game::boom1() {
    bomb1 = new Bomb(width() / 27, height() / 18, 2);
    scene()->addItem(bomb1);
    bomb1->setPos(players.at(0)->x(), players.at(0)->y());
    bombTimer1 = new QTimer();
    bombTimer1->setInterval(2000);
    connect(bombTimer1, &QTimer::timeout, this, &Game::bombRemove1);
    bombTimer1->start();
}

void Game::boom2() {
    bomb2 = new Bomb(width() / 27, height() / 18, 1);
    scene()->addItem(bomb2);
    bomb2->setPos(players.at(1)->x(), players.at(1)->y());
    bombTimer2 = new QTimer();
    bombTimer2->setInterval(2000);
    connect(bombTimer2, &QTimer::timeout, this, &Game::bombRemove2);
    bombTimer2->start();
}

void Game::bombRemove1() {
    bombTimer1->stop();
    BoomTemplate.clear();

    auto boom1 = new Bomb_effect(width() / 30, height() / 25);
    scene()->addItem(boom1);
    boom1->setPos(bomb1->x(), bomb1->y());
    BoomTemplate.append(boom1);
    //---------------------------------
    auto boom2 = new Bomb_effect(width() / 25, height() / 25);
    BoomTemplate.append(boom2);
    scene()->addItem(boom2);
    boom2->setPos(bomb1->x() + bomb1->width, bomb1->y());

    connect(boom2, &Bomb_effect::clash, this, &Game::boomRemoverTest);
    connect(boom2, &Bomb_effect::Box_removed, this, &Game::Box_Remover1);
    //--------------------------------
    auto boom3 = new Bomb_effect(width() / 25, height() / 25);
    BoomTemplate.append(boom3);
    scene()->addItem(boom3);
    boom3->setPos(bomb1->x() - bomb1->width, bomb1->y());

    connect(boom3, &Bomb_effect::clash, this, &Game::boomRemoverTest);
    connect(boom3, &Bomb_effect::Box_removed, this, &Game::Box_Remover1);
    //---------------------------------
    auto boom4 = new Bomb_effect(width() / 25, height() / 25);
    BoomTemplate.append(boom4);
    scene()->addItem(boom4);
    boom4->setPos(bomb1->x(), bomb1->y() + bomb1->height);

    connect(boom4, &Bomb_effect::clash, this, &Game::boomRemoverTest);
    connect(boom4, &Bomb_effect::Box_removed, this, &Game::Box_Remover1);
    //---------------------------------
    auto boom5 = new Bomb_effect(width() / 25, height() / 25);
    BoomTemplate.append(boom5);
    scene()->addItem(boom5);
    boom5->setPos(bomb1->x(), bomb1->y() - bomb1->height);

    connect(boom5, &Bomb_effect::clash, this, &Game::boomRemoverTest);
    connect(boom5, &Bomb_effect::Box_removed, this, &Game::Box_Remover1);
    //---------------------------------
    scene()->removeItem(bomb1);
    delete bomb1;

    boomTimer1 = new QTimer();
    boomTimer1->setInterval(2000);
    connect(boomTimer1, &QTimer::timeout, this, &Game::allBoomRemover);
    boomTimer1->start();
}

void Game::bombRemove2() {
    bombTimer2->stop();
    BoomTemplate2.clear();

    auto boom1 = new Bomb_effect(width() / 30, height() / 25);
    scene()->addItem(boom1);
    boom1->setPos(bomb2->x(), bomb2->y());
    BoomTemplate2.append(boom1);
    //---------------------------------
    auto boom2 = new Bomb_effect(width() / 25, height() / 25);
    BoomTemplate2.append(boom2);
    scene()->addItem(boom2);
    boom2->setPos(bomb2->x() + bomb2->width, bomb2->y());

    connect(boom2, &Bomb_effect::clash, this, &Game::boomRemoverTest);
    connect(boom2, &Bomb_effect::Box_removed, this, &Game::Box_Remover2);
    //---------------------------------
    auto boom3 = new Bomb_effect(width() / 25, height() / 25);
    BoomTemplate2.append(boom3);
    scene()->addItem(boom3);
    boom3->setPos(bomb2->x() - bomb2->width, bomb2->y());

    connect(boom3, &Bomb_effect::clash, this, &Game::boomRemoverTest);
    connect(boom3, &Bomb_effect::Box_removed, this, &Game::Box_Remover2);
    //---------------------------------
    auto boom4 = new Bomb_effect(width() / 25, height() / 25);
    BoomTemplate2.append(boom4);
    scene()->addItem(boom4);
    boom4->setPos(bomb2->x(), bomb2->y() + bomb2->height);

    connect(boom4, &Bomb_effect::clash, this, &Game::boomRemoverTest);
    connect(boom4, &Bomb_effect::Box_removed, this, &Game::Box_Remover2);
    //---------------------------------
    auto boom5 = new Bomb_effect(width() / 25, height() / 25);
    BoomTemplate2.append(boom5);
    scene()->addItem(boom5);
    boom5->setPos(bomb2->x(), bomb2->y() - bomb2->height);

    connect(boom5, &Bomb_effect::clash, this, &Game::boomRemoverTest);
    connect(boom5, &Bomb_effect::Box_removed, this, &Game::Box_Remover2);
    //---------------------------------
    scene()->removeItem(bomb2);
    delete bomb2;

    boomTimer2 = new QTimer();
    boomTimer2->setInterval(2000);
    connect(boomTimer2, &QTimer::timeout, this, &Game::allBoomRemover2);
    boomTimer2->start();
}

void Game::boomRemoverTest(Bomb_effect *tempBombEffect) {
    scene()->removeItem(tempBombEffect);
    tempBombEffect = nullptr;
}

void Game::allBoomRemover() {
    boomTimer1->stop();
    for (int y = 0; y < 5; y++) {
        if (BoomTemplate[y] != nullptr) {
            scene()->removeItem(BoomTemplate[y]);
            BoomTemplate[y] = nullptr;
        }
    }
    players.at(0)->checkLife = false;
}

void Game::allBoomRemover2() {
    boomTimer2->stop();
    for (int y = 0; y < 5; y++) {
        if (BoomTemplate2[y] != nullptr) {
            scene()->removeItem(BoomTemplate2[y]);
            BoomTemplate2[y] = nullptr;
        }
    }
    players.at(1)->checkLife = false;
}

void Game::Box_Remover1(Block *temp_box) {
    if (temp_box->type == 1) {
        scene()->removeItem(temp_box);
        numOfBoxes--;
        blocks.removeOne(temp_box);
        players.at(0)->score += 5;
        scene()->removeItem(playerScore1);

        playerScore1 = new Label();
        auto score1 = new QString(QString::number(players.at(0)->score));
        playerScore1->setPlainText("Player1 Score: " + *score1);
        scene()->addItem(playerScore1);
        playerScore1->setPos((width() / 15) * 1.5, height() - 50);

        if(numOfBoxes == 0){
            checkNumOfBoxes();
        }
    }
}
void Game::Box_Remover2(Block *temp_box) {
    if (temp_box->type == 1) {
        scene()->removeItem(temp_box);
        numOfBoxes--;
        blocks.removeOne(temp_box);
        players.at(1)->score += 5;
        scene()->removeItem(playerScore2);

        playerScore2 = new Label();
        auto score2 = new QString(QString::number(players.at(1)->score));
        playerScore2->setPlainText("Player2 Score: " + *score2);
        scene()->addItem(playerScore2);
        playerScore2->setPos((width() / 15) * 11, height() - 50);

        if(numOfBoxes == 0){
            checkNumOfBoxes();
        }
    }
}

void Game::lowHeart(Player *tempPlayer) {
    --(tempPlayer->lifeCount);
    if(tempPlayer->name == players.at(0)->name){
        scene()->removeItem(playerLife1);
        playerLife1= new Label();
        auto life1 =new QString(QString::number(tempPlayer->lifeCount));
        playerLife1->setPlainText("Player1: " + *life1);
        scene()->addItem(playerLife1);
        playerLife1->setPos((width() / 15) * 1.5, (height() / 15) / 5);
    }
    else {
        scene()->removeItem(playerLife2);
        playerLife2 = new Label();
        auto life2 = new QString(QString::number(tempPlayer->lifeCount));
        playerLife2->setPlainText("Player2: " + *life2);
        scene()->addItem(playerLife2);
        playerLife2->setPos((width() / 15) * 11, (height() / 15) / 5);
    }
}

void Game::heart_remover(heart_picture* temp) {
    scene()->removeItem(temp);
    if(temp->name == players.at(0)->name){
        scene()->removeItem(playerLife1);
        playerLife1= new Label();
        auto life1 =new QString(QString::number(players.at(0)->lifeCount));
        playerLife1->setPlainText("Player1: " + *life1);
        scene()->addItem(playerLife1);
        playerLife1->setPos((width() / 15) * 1.5, (height() / 15) / 5);
    }
    else {
        scene()->removeItem(playerLife2);
        playerLife2 = new Label();
        auto life2 = new QString(QString::number(players.at(1)->lifeCount));
        playerLife2->setPlainText("Player2: " + *life2);
        scene()->addItem(playerLife2);
        playerLife2->setPos((width() / 15) * 11, (height() / 15) / 5);
    }
    hearts.removeOne(temp);
}

void Game::checkNumOfBoxes(){
    if(players.at(1)->score > players.at(0)->score){
        close();
        (new Result(players.at(0)->name,players.at(0)->score,players.at(1)->name,players.at(1)->score))->show();
    }
    else if(players.at(0)->score > players.at(1)->score){
        close();
        (new Result(players.at(0)->name,players.at(0)->score,players.at(1)->name,players.at(1)->score))->show();
    }
    else{
        close();
        (new Result(players.at(0)->name+players.at(1)->name,players.at(0)->score,players.at(1)->name + players.at(0)->name,players.at(1)->score))->show();
    }
}

Game::~Game() {
    qDeleteAll(players);
    qDeleteAll(blocks);
    qDeleteAll(BombList);
    qDeleteAll(hearts);
    delete playerLife1;
    delete playerLife2;
    delete playerScore1;
    delete playerScore2;
    delete bomb1;
    delete bomb2;
    delete bombTimer1;
    delete bombTimer2;
    delete boomTimer1;
    delete boomTimer2;
    delete pPicture;
    qDeleteAll(BoomTemplate);
    qDeleteAll(BoomTemplate2);
}

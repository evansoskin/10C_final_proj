#include "dot_game.h"
#include "ui_dot_game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Dot_Game::Dot_Game(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::Dot_Game), score(0)
{
    ui->setupUi(this);

    // The starting point of player
    this->Player.x = 490;
    this->Player.y = 490;

    srand(time(NULL));
    Enemies.resize(25);
    int e_size = Enemies.size();
    for(int i = 0; i < e_size; i++)
    {
        (Enemies[i]).x = (rand() % 78 + 10) * 10;
        (Enemies[i]).y = (rand() % 78 + 10) * 10;
    }
}

Dot_Game::~Dot_Game()
{
    delete ui;
}

void Dot_Game::paintEvent(QPaintEvent* e){

    QPainter painter(this);
    double width = 20.0;
    double height = 20.0;

    painter.setBrush(QBrush(Qt::black));
    int e_size = Enemies.size();
    for(int i = 0; i < e_size; i++)
    {
        QRect current_enemy((Enemies[i]).x, (Enemies[i]).y, width, height);
        painter.drawEllipse(current_enemy);
    }

    painter.setBrush(QBrush(Qt::green));
    QRect Player( this->Player.x, this->Player.y, width, height );
    painter.drawEllipse(Player);
    return;
}

void Dot_Game::keyPressEvent(QKeyEvent* event)
{
    switch (event->key()){
        case Qt::Key_Left :
            this->moveLeft();
            break;
        case Qt::Key_Right :
            this->moveRight();
            break;
        case Qt::Key_Up :
            this->moveUp();
            break;
        case Qt::Key_Down :
            this->moveDown();
            break;
        default:
            QWidget::keyPressEvent(event);
    }
    return;
}

void Dot_Game::updateScore(int n)
{
    score += n;
    ui->ScoreLabel_2->setNum(score);
}

void Dot_Game::removeDeadEnemies()
{
    int i = 0;
    while(i < Enemies.size())
    {
        if(Player.x == (Enemies[i]).x && Player.y == (Enemies[i].y))
        {
            Enemies.erase(Enemies.begin()+i);
            updateScore(100);
        }
        else
            i++;
    }

    return;
}

void Dot_Game::handleEventsAndRepaint()
{
    QCoreApplication::processEvents();
    removeDeadEnemies();

    this->repaint();
    return;
}

void Dot_Game::moveRight()
{
    if (this->Player.x < 880)
    {
        this->Player.x += 10.0;
        updateScore(-1);
    }
    this->handleEventsAndRepaint();
    return;
}

void Dot_Game::moveLeft()
{
    if (this->Player.x > 100)
    {
        this->Player.x -= 10.0;
        updateScore(-1);
    }
    this->handleEventsAndRepaint();
    return;
}

void Dot_Game::moveUp()
{
    if (this->Player.y > 100)
    {
        this->Player.y -= 10.0;
        updateScore(-1);
    }
    this->handleEventsAndRepaint();
    return;
}

void Dot_Game::moveDown()
{
    if (this->Player.y < 880)
    {
        this->Player.y += 10.0;
        updateScore(-1);
    }
    this->handleEventsAndRepaint();
    return;
}

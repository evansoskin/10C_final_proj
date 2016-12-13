#include "dot_game.h"
#include "ui_dot_game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Dot_Game::Dot_Game(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::Dot_Game)
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
        (Enemies[i]).x = rand() % 780 + 100;
        (Enemies[i]).y = rand() % 780 + 100;
    }
}

Dot_Game::~Dot_Game()
{
    delete ui;
}


// Player is Green dot
void Dot_Game::paintEvent(QPaintEvent* e){

    QPainter painter(this);
    painter.setBrush(QBrush(Qt::green));

    double width = 20.0;
    double height = 20.0;
    QRect Player( this->Player.x, this->Player.y, width, height );
    painter.drawEllipse(Player);

    painter.setBrush(QBrush(Qt::black));
    int e_size = Enemies.size();
    for(int i = 0; i < e_size; i++)
    {
        QRect current_enemy((Enemies[i]).x, (Enemies[i]).y, width, height);
        painter.drawEllipse(current_enemy);
    }

    return;
}


// Arrow keys move dot, others ignored.
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

void Dot_Game::handleEventsAndRepaint() {

    QCoreApplication::processEvents();

    this->repaint();
    return;
}


// Update x & y coordinates accordingly and repaint the widget.

void Dot_Game::moveRight()
{
    if (this->Player.x < 880)
        this->Player.x += 10.0;
    this->handleEventsAndRepaint();
    return;
}

void Dot_Game::moveLeft()
{
    if (this->Player.x > 100)
        this->Player.x -= 10.0;
    this->handleEventsAndRepaint();
    return;
}

void Dot_Game::moveUp()
{
    if (this->Player.y > 100)
        this->Player.y -= 10.0;
    this->handleEventsAndRepaint();
    return;
}

void Dot_Game::moveDown()
{
    if (this->Player.y < 880)
        this->Player.y += 10.0;
    this->handleEventsAndRepaint();
    return;
}

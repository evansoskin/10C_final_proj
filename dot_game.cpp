#include "main_menu.h"
#include "dot_game.h"
#include "ui_dot_game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Dot_Game::Dot_Game(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::Dot_Game), score(0)
{
    ui->setupUi(this);

    //Couldnt get styling working for game window, dots were being painted behind frames
    //ui->background->setStyleSheet("background-color: black;");
    //ui->Title->setStyleSheet("color: white;");
    //ui->ScoreLabel->setStyleSheet("color: white;");
    //ui->ScoreLabel_2->setStyleSheet("color: white;");
    //ui->Esc->setStyleSheet("color: white;");
    //ui->frame->setStyleSheet("background-color: white;");

    //hide game complete screen
    ui->game_over->setVisible(false);

    // The starting point of player
    this->Player.x = 490;
    this->Player.y = 490;

    //Randomize black dot starting points
    srand(time(NULL));
    Enemies.resize(25);
    size_t e_size = Enemies.size();
    for(int i = 0; i < e_size; i++)
    {
        //limit dot starting points to inside frame and multiple of ten
        (Enemies[i]).x = (rand() % 78 + 10) * 10;
        (Enemies[i]).y = (rand() % 78 + 10) * 10;
    }
}

Dot_Game::~Dot_Game()
{
    delete ui;
}

void Dot_Game::paintEvent(QPaintEvent* e)
{
    //create painter to this dot game
    QPainter painter(this);
    //set height and width of dots
    double width = 20.0;
    double height = 20.0;

    //make brush black for dots
    painter.setBrush(QBrush(Qt::black));
    size_t e_size = Enemies.size();
    for(int i = 0; i < e_size; i++)
    {
        QRect current_enemy((Enemies[i]).x, (Enemies[i]).y, width, height);
        painter.drawEllipse(current_enemy);
    }

    //make player dot green
    painter.setBrush(QBrush(Qt::green));
    QRect Player( this->Player.x, this->Player.y, width, height );
    painter.drawEllipse(Player);

    return;
}

void Dot_Game::keyPressEvent(QKeyEvent* event)
{
    //dont take keyboard input if game is over
    if(Enemies.size() > 0)
    {
        //Move player with arrow keys or quit game with esc
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
        case Qt::Key_Escape :
            this->close_DG();
            break;
        default:
            QWidget::keyPressEvent(event);
        }
    }
    return;
}

//update score
void Dot_Game::updateScore(int n)
{
    score += n;
    //display current score at top of game window
    ui->ScoreLabel_2->setNum(score);
}

void Dot_Game::removeDeadEnemies()
{
    //remove dot if player moves over it
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
    //display game complete screen if no dots remain
    if(Enemies.size() == 0)
    {
        //hide game text
        ui->Title->setVisible(false);
        ui->ScoreLabel->setVisible(false);
        ui->ScoreLabel_2->setVisible(false);
        ui->Esc->setVisible(false);
        //show game complete screen
        ui->game_over->setVisible(true);
        //connect close function to exit to menu function
        connect(ui->exit_to_menu, SIGNAL(released()), this, SLOT(close_DG()));
        //styling game complete screen
        ui->game_over->setStyleSheet("background-color: black; border-radius: 10px;");
        ui->GameComplete->setStyleSheet("color: white;");
        ui->ScoreLabel_eog->setStyleSheet("color: white;");
        ui->ScoreLabel_2_eog->setStyleSheet("color: white;");
        ui->ScoreLabel_2_eog->setNum(score);
        ui->exit_to_menu->setStyleSheet("background-color: white; border-style: outset; border-width: 2px; border-radius: 10px; border-color: grey;");
        ui->game_over->show();
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

//close window when exit to menu button is clicked
void Dot_Game::close_DG()
{
    this->close();
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

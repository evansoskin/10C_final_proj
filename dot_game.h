#ifndef DOT_GAME_H
#define DOT_GAME_H

#include <QMainWindow>
#include <QPainter>
#include <QKeyEvent>
#include <QPushButton>

class Main_Menu;

namespace Ui
{class Dot_Game;}

class Dot_Game : public QMainWindow
{
    Q_OBJECT

public:
    //Constructor/Destructor
    explicit Dot_Game(QWidget* parent = 0);
    ~Dot_Game();
    //
    void paintEvent(QPaintEvent* e);
    void keyPressEvent(QKeyEvent* event);
    //Player movement functions
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

private:
    Ui::Dot_Game* ui;
    void handleEventsAndRepaint();
    //removes black dots when player goes over them
    void removeDeadEnemies();
    //changes score on player movement and when dot is removed
    void updateScore(int n);
    //basic class to use for grid coordinates for dots
    class Point{
    public:
        double x;
        double y;
    };
    //Player coordinate
    Point Player;
    //Vector of black dots coordinates
    std::vector<Point> Enemies;
    int score;

private slots:
    //function call for game complete screen push button
    void close_DG();
};

#endif // DOT_GAME_H

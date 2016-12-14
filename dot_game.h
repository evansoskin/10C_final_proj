#ifndef DOT_GAME_H
#define DOT_GAME_H

#include <QMainWindow>
#include <QPainter>
#include <QKeyEvent>
//#include <vector>

namespace Ui
{class Dot_Game;}

class Dot_Game : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dot_Game(QWidget* parent = 0);
    ~Dot_Game();
    void paintEvent(QPaintEvent* e);
    void keyPressEvent(QKeyEvent* event);
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

private:
    Ui::Dot_Game* ui;
    void handleEventsAndRepaint();
    void removeDeadEnemies();
    void updateScore(int n);
    class Point{
    public:
        double x;
        double y;
    };
    Point Player;
    std::vector<Point> Enemies;
    int score;
};

#endif // DOT_GAME_H

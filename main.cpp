#include "dot_game.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QMainWindow menu;

    Dot_Game game_window;
    game_window.setFixedSize(1000,1000);
    game_window.show();

    return a.exec();
}

#include "dot_game.h"
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dot_Game display_window;
    display_window.setFixedSize(1000,1000);
    display_window.show();

    return a.exec();
}

#include "main_menu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Main_Menu menu_window;
    menu_window.show();

    return a.exec();
}

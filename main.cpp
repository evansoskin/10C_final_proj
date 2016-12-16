#include "main_menu.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    //check for memory leaks
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    QApplication a(argc, argv);

    //create main menu window which creates a dot game window
    Main_Menu menu_window;
    menu_window.show();

    return a.exec();
}

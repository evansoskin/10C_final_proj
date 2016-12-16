#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "dot_game.h"
#include <QMainWindow>
#include <QPushButton>

namespace Ui
{class Main_Menu;}

class Main_Menu : public QMainWindow
{
    Q_OBJECT

public:
    //Constructor/Destructor
    explicit Main_Menu(QWidget* parent = 0);
    ~Main_Menu();

private:
    Ui::Main_Menu* ui;
    //Pointers to main menu push buttons
    QPushButton* start;
    QPushButton* exit;
    //Pointer to game window
    Dot_Game* game_window;

private slots:
    //functions called when push buttons released
    void start_game();
    void close_exe();
};

#endif // MAIN_MENU_H

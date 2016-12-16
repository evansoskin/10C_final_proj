#include "main_menu.h"
#include "ui_main_menu.h"
#include "dot_game.h"

Main_Menu::Main_Menu(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::Main_Menu), game_window(nullptr)
{
    ui->setupUi(this);

    //styling main menu window
    ui->background->setStyleSheet("background-color: black;");
    ui->frame->setStyleSheet("background-color: white; border-radius: 10px;");
    ui->start_button->setStyleSheet("background-color: white; border-style: outset; border-width: 2px; border-radius: 10px; border-color: grey;");
    ui->exit_button->setStyleSheet("background-color: white; border-style: outset; border-width: 2px; border-radius: 10px; border-color: grey;");

    //Point pointers to push buttons
    start = ui->start_button;
    exit = ui->exit_button;

    //connect buttons to functions
    connect(start, SIGNAL(released()), this, SLOT(start_game()));
    connect(exit, SIGNAL(released()), this, SLOT(close_exe()));
}

Main_Menu::~Main_Menu()
{
    delete ui;
    delete start;
    delete exit;
    delete game_window;
}

void Main_Menu::start_game()
{
    //delete the old game so if game is closed mid-game a new one is started each time
    delete game_window;
    //Not great by using 'new' keyword outside of constructor, but preceding delete removes memory leaks
    game_window = new Dot_Game;
    game_window->setFixedSize(1000,1000);
    game_window->show();
}

void Main_Menu::close_exe()
{
    this->close();
}

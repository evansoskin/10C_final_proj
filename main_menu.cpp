#include "main_menu.h"
#include "ui_main_menu.h"
#include "dot_game.h"

Main_Menu::Main_Menu(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::Main_Menu), game_window(nullptr)
{
    ui->setupUi(this);

    ui->background->setStyleSheet("background-color: black;");
    ui->frame->setStyleSheet("background-color: white; border-radius: 10px;");
    ui->start_button->setStyleSheet("background-color: white; border-style: outset; border-width: 2px; border-radius: 10px; border-color: grey;");
    ui->exit_button->setStyleSheet("background-color: white; border-style: outset; border-width: 2px; border-radius: 10px; border-color: grey;");

    start = ui->start_button;
    exit = ui->exit_button;
    start_b = false;
    exit_b = false;

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
    delete game_window;
    game_window = new Dot_Game;
    game_window->setFixedSize(1000,1000);
    game_window->show();
}

void Main_Menu::close_exe()
{
    this->close();
}

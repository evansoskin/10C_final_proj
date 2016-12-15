#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui
{class Main_Menu;}

class Main_Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Main_Menu(QWidget* parent = 0);
    ~Main_Menu();
    bool start_b;
    bool exit_b;

private:
    Ui::Main_Menu* ui;
    QPushButton* start;
    QPushButton* exit;

private slots:
    void start_game();
    void close_exe();
};

#endif // MAIN_MENU_H

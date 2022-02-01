#include "controllers/masterController.hpp"
#include <iostream>
#include <ncurses.h>

/*

Точка входу в программу.
Создает MC, запускает в нем игровой цикл,
  а после выхода из игрового цикла запускает
  деструктор.

*/
int main() {
    MasterController *mc = new MasterController();
    mc->runGameCycle();
    delete mc;
}
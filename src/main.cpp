#include <ncurses.h>

#include <iostream>

#include "controllers/masterController.hpp"

/*

Точка входу в программу.
Создает MC, запускает в нем игровой цикл,
    а после выхода из игрового цикла запускает
    деструктор.

*/
int main() {
  MasterController* mc = new MasterController();
  mc->runGameCycle();
  delete mc;
}

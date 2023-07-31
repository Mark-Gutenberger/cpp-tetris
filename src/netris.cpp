#include <ncurses.h>

#include <iostream>

#include "controllers/masterController.hpp"

int main() {
	MasterController* mc = new MasterController();
	mc->runGameCycle();
	delete mc;
}

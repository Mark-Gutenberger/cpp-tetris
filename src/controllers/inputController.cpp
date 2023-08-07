#include "inputController.hpp"

#include <ncurses.h>

#include "gameController.hpp"
#include "graphicsController.hpp"
#include "masterController.hpp"

InputController::InputController(MasterController* mc) {
  masterController = mc;
  noecho();
  curs_set(0);
  keypad(masterController->getGraphicsController()->getWindow(), true);
  nodelay(masterController->getGraphicsController()->getWindow(), true);
}

void InputController::tick() {
  int input = getch();
  while (input != ERR) {
	if (input == KEY_UP) {
	  masterController->getGameController()->rotate();
	}
	if (input == KEY_LEFT) {
	  masterController->getGameController()->moveLeft();
	}
	if (input == KEY_RIGHT) {
	  masterController->getGameController()->moveRight();
	}
	if (input == KEY_DOWN) {
	  masterController->getGameController()->moveDown();
	}
	if (input == 'X' || input == 'x') {
	  masterController->getGameController()->setGameStatus(GAME_ENDED);
	}
	input = getch();
  }
}

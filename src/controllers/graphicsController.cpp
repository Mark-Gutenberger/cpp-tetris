#include "graphicsController.hpp"

#include <ncurses.h>
#include <unistd.h>

#include <cstdlib>

#include "../defines.hpp"
#include "../figure.hpp"
#include "gameController.hpp"
#include "masterController.hpp"

GraphicsController::GraphicsController(MasterController* mc) {
	this->masterController = mc;
	win = initscr();
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_RED);
	init_pair(2, COLOR_BLACK, COLOR_GREEN);
	init_pair(3, COLOR_BLACK, COLOR_YELLOW);
	init_pair(4, COLOR_BLACK, COLOR_BLUE);
	init_pair(5, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(6, COLOR_BLACK, COLOR_CYAN);
	init_pair(7, COLOR_BLACK, COLOR_WHITE);
	init_pair(8, COLOR_BLUE, COLOR_BLACK);
}

void GraphicsController::tick() {
	drawGameField(masterController->getGameController()->getGameField());
	drawFigure(masterController->getGameController()->getCurrentFigure());
	drawUI(masterController->getGameController()->getScore());

	refresh();
}

void GraphicsController::drawUI(int score) {
	move(1, GAME_FIELD_WIDHT * 2 + 2);
	printw("Score: %05d", score);
	move(3, GAME_FIELD_WIDHT * 2 + 7);
	printw("Controls:");
	move(4, GAME_FIELD_WIDHT * 2 + 3);
	printw("Upper arrow - rotate");
	move(5, GAME_FIELD_WIDHT * 2 + 3);
	printw("Left and right arrows - move");
	move(6, GAME_FIELD_WIDHT * 2 + 3);
	printw("Down arrow - speed up falling");
	move(7, GAME_FIELD_WIDHT * 2 + 3);
	printw("X - exit the game");
}

void GraphicsController::drawGameField(const int** gameField) {
	for (int n = 0; n < GAME_FIELD_HEIGHT; n++) {
		for (int m = 0; m < GAME_FIELD_WIDHT; m++) {
			if (gameField[n][m]) {
				attron(COLOR_PAIR(gameField[n][m]));
				mvaddch(GAME_FIELD_HEIGHT - n - 1, m * 2, ' ');
				mvaddch(GAME_FIELD_HEIGHT - n - 1, m * 2 + 1, ' ');
				attroff(COLOR_PAIR(gameField[n][m]));
			} else {
				attron(COLOR_PAIR(8));
				mvaddch(GAME_FIELD_HEIGHT - n - 1, m * 2, '~');
				mvaddch(GAME_FIELD_HEIGHT - n - 1, m * 2 + 1, '~');
				attroff(COLOR_PAIR(8));
			}
		}
	}
}

void GraphicsController::drawFigure(Figure* fig) {
	if (fig == NULL)
		return;
	attron(COLOR_PAIR(fig->getColor()));
	for (int n = 0; n < 4; n++) {
		for (int m = 0; m < 4; m++) {
			if (!fig->getForm())
				exit(5);
			if (!fig->getForm()[n][m])
				continue;
			int new_x = fig->getX() + m;
			int new_y = fig->getY() + n;

			if (new_x < 0 || new_x >= GAME_FIELD_WIDHT || new_y < 0 ||
				new_y >= GAME_FIELD_HEIGHT) {
				continue;
			}
			mvaddch(GAME_FIELD_HEIGHT - new_y - 1, new_x * 2, 'X');
			mvaddch(GAME_FIELD_HEIGHT - new_y - 1, new_x * 2 + 1, 'X');
		}
	}
	attroff(COLOR_PAIR(fig->getColor()));
}

WINDOW* GraphicsController::getWindow() {
	return win;
}

GraphicsController::~GraphicsController() {
	endwin();
}

void GraphicsController::displayGameEnd() {
	clear();
	printw("Game ended! You got %d points. Press enter to exit.",
		   masterController->getGameController()->getScore());
	refresh();
	while (getch() != '\n')
		usleep(25000);
}
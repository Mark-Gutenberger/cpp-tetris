#pragma once

#include <ncurses.h>
class MasterController;
class Figure;

class GraphicsController {
   private:
	MasterController* masterController;
	WINDOW* win;
	void drawUI(int score);
	void drawGameField(const int** gameField);
	void drawFigure(Figure* fig);

   public:
	GraphicsController(MasterController* mc);
	~GraphicsController();
	void tick();
	void displayGameEnd();
	WINDOW* getWindow();
};
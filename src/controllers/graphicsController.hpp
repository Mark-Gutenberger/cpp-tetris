#pragma once

#include <ncurses.h>
class MasterController;
class Figure;

/*

Контроллер, отвечающий за отрисовку игры
Имеет 2 важных функции
tick - отрисовывает поле
displayGameEnd - показывает конец игры и ожидает нажатия на любую кнопку

*/

class GraphicsController {
  private:
    MasterController *masterController;
    WINDOW *win;
    void drawUI(int score);
    void drawGameField(const int **gameField);
    void drawFigure(Figure *fig);

  public:
    GraphicsController(MasterController *mc);
    ~GraphicsController();
    void tick();
    void displayGameEnd();
    WINDOW *getWindow();
};
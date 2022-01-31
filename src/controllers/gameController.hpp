#pragma once

#include "../defines.hpp"

class Figure;
class MasterController;

/*

Статусы игры
IN_GAME - игра идет, необходимо выводить игру на экран
GAME_ENDED - игра окончилась, необходимо прервать
  игровой цикл и вывести на экран итоговый счет

*/
enum GameStatus {
  IN_GAME,
  GAME_ENDED
};


/*

Контроллер состояния игры
Может получать сигналы от других контроллеров для управления
игрой

tick - пробуждает контроллер, заставляя его обработать падение фигурки вниз

Также есть функции, обрабатывающие сигналы пользователя
moveLeft, moveRight, moveDown и rotate
А также setGameStatus для выхода из игры

Также для рендеринга есть возможность получить
счет, игровое поле и текущую фигуру

*/

class GameController {
private:
  MasterController* masterController;

  int score;
  int** gameField;
  Figure* currentFigure;

  int physics_delay = DEFAULT_FALL_DELAY;

  void freezeFigure();
  void generateNewFigure();
  void removeFullRows();
  void addScore();

  void removeRow(int rowNumber);
  GameStatus status = IN_GAME;
public:
  GameController(MasterController* mc);
  ~GameController();

  int getScore();
  const int** getGameField();
  Figure* getCurrentFigure();

  void tick();

  void moveRight();
  void moveLeft();
  void moveDown();
  void rotate();

  void setGameStatus(GameStatus gs);
  GameStatus getGameStatus();

  int getPhysicsDelay();
};
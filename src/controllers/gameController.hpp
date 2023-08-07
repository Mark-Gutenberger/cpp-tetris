#pragma once

#include "../defines.hpp"

class Figure;
class MasterController;

enum GameStatus { IN_GAME, GAME_ENDED };

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

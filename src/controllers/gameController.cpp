#include "gameController.hpp"
#include <iostream>
#include "../defines.hpp"
#include "../figure.hpp"
#include "../figureTypes.hpp"
#include "graphicsController.hpp"
#include "masterController.hpp"

void GameController::freezeFigure() {
  const int** form = currentFigure->getForm();
  int x = currentFigure->getX();
  int y = currentFigure->getY();

  int color = currentFigure->getColor();

  if (currentFigure->isOutOfBounds())
    return;

  for (int n = 0; n < 4; n++) {
    for (int m = 0; m < 4; m++) {
      if (!form[n][m])
        continue;
      gameField[y + n][x + m] = currentFigure->getColor();
    }
  }

  for (int i = 0; i < GAME_FIELD_WIDHT; i++) {
    if (gameField[GAME_FIELD_HEIGHT - 1][i]) {
      setGameStatus(GAME_ENDED);
    }
  }
}

void GameController::generateNewFigure() {
  int color = rand() % 7 + 1;
  int x = (GAME_FIELD_WIDHT - 3) / 2;
  int y = (GAME_FIELD_HEIGHT - 3);
  int form_type = rand() % 7;
  Figure* f;

  if (form_type == 0) {
    f = new OFigure(color, x, y);
  } else if (form_type == 1) {
    f = new IFigure(color, x, y);
  } else if (form_type == 2) {
    f = new LFigure(color, x, y);
  } else if (form_type == 3) {
    f = new JFigure(color, x, y);
  } else if (form_type == 4) {
    f = new ZFigure(color, x, y);
  } else if (form_type == 5) {
    f = new SFigure(color, x, y);
  } else if (form_type == 6) {
    f = new TFigure(color, x, y);
  }

  if (currentFigure != NULL) {
    delete currentFigure;
    currentFigure = f;
    this->masterController->getGraphicsController()->tick();
  } else {
    currentFigure = f;
  }
}

void GameController::removeRow(int rowNumber) {
  addScore();

  for (int n = rowNumber + 1; n < GAME_FIELD_HEIGHT; n++) {
    for (int m = 0; m < GAME_FIELD_WIDHT; m++) {
      gameField[n - 1][m] = gameField[n][m];
    }
  }

  for (int m = 0; m < GAME_FIELD_WIDHT; m++) {
    gameField[GAME_FIELD_HEIGHT - 1][m] = 0;
  }
}

void GameController::removeFullRows() {
  for (int n = 0; n < GAME_FIELD_HEIGHT; n++) {
    bool isRowFull = true;
    for (int m = 0; m < GAME_FIELD_WIDHT; m++) {
      if (!gameField[n][m])
        isRowFull = false;
    }
    if (isRowFull) {
      this->removeRow(n);
      n--;
    }
  }
}

GameController::GameController(MasterController* mc) {
  this->masterController = mc;
  this->currentFigure = NULL;

  gameField = new int*[GAME_FIELD_HEIGHT];
  for (int i = 0; i < GAME_FIELD_HEIGHT; i++) {
    gameField[i] = new int[GAME_FIELD_WIDHT];
  }

  generateNewFigure();
}

int GameController::getScore() {
  return this->score;
}

const int** GameController::getGameField() {
  return (const int**)this->gameField;
}

Figure* GameController::getCurrentFigure() {
  return this->currentFigure;
}

void GameController::tick() {
  this->moveDown();
}

void GameController::rotate() {
  if (currentFigure->safeRotate(this->getGameField())) {
    this->masterController->getGraphicsController()->tick();
  }
}

void GameController::moveRight() {
  if (currentFigure->safeRight(this->getGameField())) {
    this->masterController->getGraphicsController()->tick();
  }
}

void GameController::moveLeft() {
  if (currentFigure->safeLeft(this->getGameField())) {
    this->masterController->getGraphicsController()->tick();
  }
}

void GameController::moveDown() {
  bool falled = currentFigure->safeFall(this->getGameField());

  if (!falled) {
    this->freezeFigure();
    this->removeFullRows();
    this->generateNewFigure();
  }

  this->masterController->getGraphicsController()->tick();
}

GameController::~GameController() {
  for (int i = 0; i < GAME_FIELD_HEIGHT; i++) {
    delete gameField[i];
  }
  delete gameField;
  delete currentFigure;
}

void GameController::setGameStatus(GameStatus gs) {
  status = gs;
}

GameStatus GameController::getGameStatus() {
  return status;
}

int GameController::getPhysicsDelay() {
  return physics_delay;
}

void GameController::addScore() {
  score += ROW_REWARD;
  if (score % LEVEL_COST == 0) {
    physics_delay = physics_delay / SPEEDUP_PER_LEVEL;
  }
}
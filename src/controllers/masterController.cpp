#include "masterController.hpp"
#include "../defines.hpp"
#include "gameController.hpp"
#include "graphicsController.hpp"
#include "inputController.hpp"

#include <cstdlib>
#include <ctime>
#include <unistd.h>

MasterController::MasterController() {
    srand(time(0));
    gameController = new GameController(this);
    graphicsController = new GraphicsController(this);
    inputController = new InputController(this);
}

void MasterController::runGameCycle() {
    int tickCounter = 0;
    while (true) {
        if (gameController->getGameStatus() == GAME_ENDED) {
            graphicsController->displayGameEnd();
            break;
        }

        inputController->tick();
        if (++tickCounter == gameController->getPhysicsDelay()) {
            gameController->tick();
            tickCounter = 0;
        }
        usleep(TICK_LEN);
    }
}

GameController *MasterController::getGameController() {
    return this->gameController;
}

GraphicsController *MasterController::getGraphicsController() {
    return this->graphicsController;
}

InputController *MasterController::getInputController() {
    return this->inputController;
}

MasterController::~MasterController() {
    delete inputController;
    delete graphicsController;
    delete gameController;
}
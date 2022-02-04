#pragma once
class GameController;
class GraphicsController;
class InputController;

class MasterController {
   private:
	GameController* gameController;
	GraphicsController* graphicsController;
	InputController* inputController;

   public:
	MasterController();
	~MasterController();
	void runGameCycle();

	GameController* getGameController();
	GraphicsController* getGraphicsController();
	InputController* getInputController();
};
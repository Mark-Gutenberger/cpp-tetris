#pragma once
class GameController;
class GraphicsController;
class InputController;

/*

Мастер-контроллер, он же главный контроллер.
Отвечает за обработку игрового цикла, вызывая в нужные
моменты tick() у других контроллеров

Также является связующим звеном между разными контроллерами,
позволяя им отправлять друг другу сообщения.

По факту реализует Actor-based OOP.

*/

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
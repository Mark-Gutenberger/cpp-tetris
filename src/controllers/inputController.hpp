#pragma once

class MasterController;

/*

Контроллер отвечающий за обработку ввода пользователя

tick - обрабатывает весь буфферизированный ввод пользователя и отправляет
соответствующие сигналы другим контроллерам

*/

class InputController {
  private:
    MasterController *masterController;

  public:
    InputController(MasterController *mc);
    void tick();
};
#pragma once

class MasterController;

class InputController {
   private:
	MasterController* masterController;

   public:
	InputController(MasterController* mc);
	void tick();
};
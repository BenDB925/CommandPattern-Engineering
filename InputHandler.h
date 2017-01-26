#pragma once
#include <map>
#include "Command.h"
#include <SDL.h>
#include "MacroCommand.h"
#include "DerivedCommands.h"

class InputHandler
{
public:
	
	InputHandler();
	
	void handleInput(Uint32 pInput);
	



private:
	MacroCommand *_macro;

	JumpCommand* _jump;
	CrouchCommand* _crouch;
	LeftCommand* _left;
	RightCommand* _right;
	UndoCommand* _undo;

	map<int, Command*> _inputMap;
};

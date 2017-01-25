#include "InputHandler.h"


InputHandler::InputHandler()
{
	_macro = new MacroCommand();
	_jump = new JumpCommand(_macro);
	_left = new LeftCommand(_macro);
	_right = new RightCommand(_macro);
	_crouch = new CrouchCommand(_macro);
	_undo = new UndoCommand(_macro);

	_inputMap.insert_or_assign(static_cast<Uint32>(SDLK_UP),	_jump);
	_inputMap.insert_or_assign(static_cast<Uint32>(SDLK_DOWN),	_crouch);
	_inputMap.insert_or_assign(static_cast<Uint32>(SDLK_LEFT),	_left);
	_inputMap.insert_or_assign(static_cast<Uint32>(SDLK_RIGHT), _right);
	_inputMap.insert_or_assign(static_cast<Uint32>(SDLK_w),		_jump);
	_inputMap.insert_or_assign(static_cast<Uint32>(SDLK_s),		_crouch);
	_inputMap.insert_or_assign(static_cast<Uint32>(SDLK_a),		_left);
	_inputMap.insert_or_assign(static_cast<Uint32>(SDLK_d),		_right);
	_inputMap.insert_or_assign(static_cast<Uint32>(SDLK_r),		_undo);
}

void InputHandler::handleInput(Uint32 pInput)
{
	Command * inputCommand = _inputMap.find(pInput)->second;

	if(inputCommand != nullptr)
	{
		inputCommand->execute();
	}
}

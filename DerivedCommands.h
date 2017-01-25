#pragma once
#include "MacroCommand.h"
#include <iostream>

class JumpCommand : public Command
{
public:
	MacroCommand * _commandParent;
	JumpCommand(MacroCommand * pParentCommand) { _commandParent = pParentCommand;}
	void execute() override { cout << "Jumping" << endl; _commandParent->add(&*this);}

	~JumpCommand() override {}
};

class CrouchCommand : public Command
{
public:
	MacroCommand * _commandParent;
	CrouchCommand(MacroCommand * pParentCommand) { _commandParent = pParentCommand; }
	void execute() override { cout << "Crouching" << endl; _commandParent->add(&*this);}
	~CrouchCommand() override{}
};

class LeftCommand : public Command
{
public:
	MacroCommand * _commandParent;
	LeftCommand(MacroCommand * pParentCommand) { _commandParent = pParentCommand;}
	void execute() override { cout << "Moving Left" << endl; _commandParent->add(&*this);}
	~LeftCommand() override{}
};

class RightCommand : public Command
{
public:
	MacroCommand * _commandParent;
	RightCommand(MacroCommand * pParentCommand) { _commandParent = pParentCommand; }
	void execute() override { cout << "Moving Right" << endl; _commandParent->add(&*this);}
	~RightCommand() override{}
};

class UndoCommand : public Command
{
public:
	MacroCommand * _commandParent;
	UndoCommand(MacroCommand * pParentCommand) { _commandParent = pParentCommand;}

	void execute() override
	{
		vector<Command *> doneCommands  = *_commandParent->commands;
		while (doneCommands.size() != 0)
		{
			Command * command = doneCommands.at(doneCommands.size() - 1);
			doneCommands.erase(doneCommands.begin() + doneCommands.size() - 1);
			command->execute();
		}
		_commandParent->commands->clear();
	}
};


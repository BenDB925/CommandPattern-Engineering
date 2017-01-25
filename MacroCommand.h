#pragma once
#include <vector>
#include "Command.h"

using namespace std;

class MacroCommand : public Command 
{
public:
	MacroCommand();
	~MacroCommand();
	virtual void add(Command*);
	virtual void remove(Command*);
	void execute() override;
	vector<Command*>* commands;
};

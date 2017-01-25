#include "MacroCommand.h"


MacroCommand::MacroCommand()
	:commands(new vector<Command *>())
{
}


MacroCommand::~MacroCommand()
{
}

void MacroCommand::add(Command *c) 
{
	commands->push_back(c);
}

void MacroCommand::remove(Command *c) 
{
	auto itr = find(commands->begin(), commands->end(), c);

	commands->erase(itr);
}


void MacroCommand::execute()
{
	for (int i = 0; i < commands->size(); ++i)
	{
		commands->at(i)->execute();
	}
}

#pragma once
#include "State.h"
class Animation;

class Climbing : public State
{
public:
	Climbing();
	~Climbing();
	void idle(Animation* a) override;
};

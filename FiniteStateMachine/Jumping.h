#pragma once
#include "State.h"
class Animation;

class Jumping : public State
{
public:
	Jumping();
	~Jumping();
	void idle(Animation* a) override;
};

#include "stdafx.h"
#include "Climbing.h"
#include "Idle.h"

Climbing::Climbing()
{
}


Climbing::~Climbing()
{
}

void Climbing::idle(Animation* a)
{
	cout << "Going from Climbing to Idling" << endl;
	a->setCurrent(new Idle());
	delete this;
}

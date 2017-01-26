
#include "stdafx.h"
#include <thread>
#include "Animation.h"

using namespace std;

int main()
{
	Animation fsm; int i = 0;
	while (true)
	{
		if (i == 0)
		{
			fsm.jumping();
			this_thread::sleep_for(chrono::milliseconds(1000));
			i++;
		}
		else if(i == 1)
		{
			fsm.idle();
			this_thread::sleep_for(chrono::milliseconds(1000));
			i++;
		}
		else if (i == 2)
		{
			fsm.climbing();
			this_thread::sleep_for(chrono::milliseconds(1000));
			i++;
		}
		else
		{
			fsm.idle();
			this_thread::sleep_for(chrono::milliseconds(1000));
			i = 0;
		}
	}

	return 0;
}

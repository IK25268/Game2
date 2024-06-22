#include "AI.hpp"



void AI::move(Memory& memory)
{
}

void AI::turn(Memory& memory)
{
}

void AI::calcChance(Memory& memory)
{
	if ((tickMove == 0)&&(rand() % 10 == 1))
	{
		tickMove = rand() % 100;
		speedMove = rand() % 3 + 2;
	}
	if ((tickTurn == 0) && (rand() % 10 == 1))
	{
		tickMove = rand() % 100;
		speedMove = rand() % 3 + 2;
	}
}

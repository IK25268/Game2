#pragma once
#include "Character.hpp"
#include "Memory.hpp"


class AI final {
public:
	int tickMove;
	int speedMove;
	int tickTurn;
	int speedTurn;
	char direct;
	bool enStrafe;
	void move(Memory& memory);
	void turn(Memory& memory);
	void calcChance(Memory& memory);
};

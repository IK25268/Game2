#pragma once
#include "Memory.hpp"

class Device {
public:
	virtual void Use(Memory& memory) = 0;
	virtual void TakeDamage(int damage, Memory& memory) = 0;
	virtual void Drawing() = 0;
	sf::RectangleShape texture;
	int hp;
	int posX;
	int posY;
	long unsigned int* currPlacedDev;
};

#pragma once
#include "Memory.hpp"
#include <array>

class SolidWall {
public:
	int posX;
	int posY;
	unsigned char part;
	bool reinforced;
	unsigned int hp;
	bool existence;
	sf::RectangleShape texture;
	SolidWall(int x, int y);
	virtual void Reinforce(Memory& memory);
	virtual void TakeDamage(unsigned int damage);
	virtual void Destroy(bool typeBreach);
	virtual void Drawing();
};

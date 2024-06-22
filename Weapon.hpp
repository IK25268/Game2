#pragma once
#include "Memory.hpp"

class Weapon {
public:
	virtual void Shoot(bool keyFlag) = 0;
	virtual void Reload() = 0;
	unsigned int capacity;
	unsigned int damage;
};

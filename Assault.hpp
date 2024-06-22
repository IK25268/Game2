#pragma once
#include "Weapon.hpp"

class Assault final : public Weapon {
public:
	Assault();
	void Shoot(bool keyPressed);
	void Reload();
	int timeReload;
};


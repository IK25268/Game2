#pragma once
#include "Weapon.hpp"

class ShotGun final : public Weapon{
public:
	ShotGun();
	void Shoot(bool keyFlag) override;
	void Reload() override;
	int angleFire;
	int reductDist;
	int timeReload;
};

#pragma once
#include "Weapon.hpp"
#include "Device.hpp"
#include "HardBreach.hpp"
#include "SoftBreach.hpp"
#include "ShotGun.hpp"
#include "Assault.hpp"

class Character {
public:
	std::array <std::array<int, 3>, 3> dangle = {{
		{315, 0, 45},
		{270, 360, 90},
		{225, 180, 135}
	}};
	float speed;
	bool keyMouse;
	int hp;
	float posX;
	float posY;
	float angle;
	std::list<Weapon*> weapons;
	bool currWeapon;
	long unsigned int currPlacedDev; //pos установленного устройства
	char countDev0;
	char countDev1;
	char countReinforce;
	sf::RectangleShape texture;
	virtual void Drawing() = 0;
	virtual void Reinforce(Memory& memory) = 0;
	virtual void Shoot() = 0;
	virtual void Reload() = 0;
	virtual void ChangeWeapon() = 0;
	virtual void PutDevice0(Memory& memory) = 0;
	virtual void PutDevice1(Memory& memory) = 0;
	virtual void UseDevice(Memory& memory) = 0;
	virtual void Move(sf::Event ev) = 0;
	virtual void Turn(Memory& memory) = 0;
	virtual void TakeDamage(int damage, Memory& memory) = 0;
	virtual void Death(Memory& memory) = 0;
};

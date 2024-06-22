#pragma once
#include "Character.hpp"

class Player final : public Character {
public:
	Player();
	void Drawing();
	void Reinforce(Memory& memory);
	void Shoot();
	void Reload();
	void ChangeWeapon();
	void PutDevice0(Memory& memory);
	void PutDevice1(Memory& memory);
	void UseDevice(Memory& memory);
	void Move(sf::Event ev);
	void Turn(Memory& memory);
	void TakeDamage(int damage, Memory& memory);
	void Death(Memory& memory);
};

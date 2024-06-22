#pragma once
#include "Memory.hpp"
#include "SolidWall.hpp"

class Wall final : public SolidWall  {

public:
	std::array<char, 5>iterX = { 0, 1, -1, 0, 0 };
	std::array<char, 5>iterY = { 0, 0, 0, -1, 1 };
	void Reinforce(Memory& memory) override;
	void TakeDamage(unsigned int damage) override;
	void Destroy(bool typeBreach) override;
	void Drawing() override;
};

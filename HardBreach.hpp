#pragma once
#include "Device.hpp"

class HardBreach final : public Device {
public:
	HardBreach(int y, int x, long unsigned int* _currPlacedDev, int angle);
	void Use(Memory& memory) override;
	void TakeDamage(int damage, Memory& memory) override;
	void Drawing() override;
	char orient;
};


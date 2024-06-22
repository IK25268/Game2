#pragma once
#include "Memory.hpp"

static class GUI final {
private:
public:
	GUI();
	~GUI();
	static void Render(Memory& memory);
};

#pragma once
#include "Memory.hpp"

static class Handler final {
private:
public:
	Handler();
	~Handler();
	static void KeyEvent(Memory& memory);
	static void Update(Memory& memory);
};

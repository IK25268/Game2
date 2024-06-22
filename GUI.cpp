#include "GUI.hpp"
#include "SolidWall.hpp"
#include "Device.hpp"
#include "Character.hpp"

GUI::GUI()
{
}

GUI::~GUI()
{
}

void GUI::Render(Memory& memory)
{
	memory.window.clear();
	for (auto charact : memory.characters)
	{
		memory.window.draw(charact.second->texture);
	}
	for (auto device : memory.devices)
	{
		memory.window.draw(device.second->texture);
	}
	for (auto wall : memory.walls)
	{
		memory.window.draw(wall.second->texture);
	}
	memory.window.display();
}

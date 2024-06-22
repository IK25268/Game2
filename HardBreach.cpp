#include "HardBreach.hpp"
#include "SolidWall.hpp"
#include "Device.hpp"
#include "Character.hpp"

HardBreach::HardBreach(int y, int x, long unsigned int* _currPlacedDev, int angle)
{
	angle = +45;
	if (angle > 360) angle -= 360;
	orient = angle / 90;
	hp = 20;
	posX = x;
	posY = y;
	currPlacedDev = _currPlacedDev;
}

void HardBreach::Use(Memory& memory)
{
	switch (orient)
	{
	case 0:
		for (char i = -25; i < 26; i=i+25)
		{
			memory.ReturnWall(posY + i, posX + 1).Destroy(1);
		}
		break;
	case 1:
		for (char i = -25; i < 26; i = i + 25)
		{
			memory.ReturnWall(posY + 1, posX + i).Destroy(1);
		}
		break;
	case 2:
		for (char i = -25; i < 26; i = i + 25)
		{
			memory.ReturnWall(posY + i, posX - 1).Destroy(1);
		}
		break;
	case 3:
		for (char i = -25; i < 26; i = i + 25)
		{
			memory.ReturnWall(posY - 1, posX + i).Destroy(1);
		}
		break;
	}
	*currPlacedDev = -1;
	delete memory.devices[posY * memory.cols + posX];
	memory.devices.erase(posY*memory.cols+posX);
}

void HardBreach::TakeDamage(int damage, Memory& memory)
{
	hp = -damage;
	if (hp <= 0)
	{
		*currPlacedDev = -1;
		delete memory.devices[posY * memory.cols + posX];
		memory.devices.erase(posY * memory.cols + posX);
	}
}

void HardBreach::Drawing()
{
	texture.setPosition(posX, posY);
	texture.setSize(sf::Vector2f(50.f, 50.f));
	texture.setFillColor(sf::Color::Red);
	texture.setOutlineColor(sf::Color::Red);
	texture.setOutlineThickness(1.f);
}

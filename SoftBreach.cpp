#include "SoftBreach.hpp"
#include "SolidWall.hpp"
#include "Device.hpp"
#include "Character.hpp"

SoftBreach::SoftBreach(int y, int x, long unsigned int* _currPlacedDev, int angle)
{
	angle = +45;
	if (angle > 360) angle -= 360;
	orient = angle / 90;
	hp = 20;
	posX = x;
	posY = y;
	currPlacedDev = _currPlacedDev;
}

void SoftBreach::Use(Memory& memory)
{
	switch (orient)
	{
	case 0:
		for (char i = -1; i < 2; i++)
		{
			memory.ReturnWall(posY + i, posX + 1).Destroy(0);
		}
		break;
	case 1:
		for (char i = -1; i < 2; i++)
		{
			memory.ReturnWall(posY + 1, posX + i).Destroy(0);
		}
		break;
	case 2:
		for (char i = -1; i < 2; i++)
		{
			memory.ReturnWall(posY + i, posX - 1).Destroy(0);
		}
		break;
	case 3:
		for (char i = -1; i < 2; i++)
		{
			memory.ReturnWall(posY - 1, posX + i).Destroy(0);
		}
		break;
	}
	*currPlacedDev = -1;
	memory.devices.erase(posY * memory.cols + posX);
}

void SoftBreach::TakeDamage(int damage, Memory& memory)
{
	hp = -damage;
	if (hp <= 0)
	{
		*currPlacedDev = -1;
		memory.devices.erase(posY * memory.cols + posX);
	}
}

void SoftBreach::Drawing()
{
	texture.setPosition(posX, posY);
	texture.setSize(sf::Vector2f(50.f, 50.f));
	texture.setFillColor(sf::Color::Yellow);
	texture.setOutlineColor(sf::Color::Yellow);
	texture.setOutlineThickness(1.f);
}

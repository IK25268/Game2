#include "SolidWall.hpp"

SolidWall::SolidWall(int x, int y)
{
	posX = x;
	posY = y;
	part = 0;
	reinforced = 0;
	hp = 100;
	existence = 1;
}

void SolidWall::Reinforce(Memory& memory)
{
}

void SolidWall::TakeDamage(unsigned int damage)
{
}

void SolidWall::Destroy(bool typeBreach)
{
}

void SolidWall::Drawing()
{
	texture.setPosition(posX, posY);
	texture.setSize(sf::Vector2f(50.f, 50.f));
	texture.setFillColor(sf::Color(200, 200, 200));
	texture.setOutlineColor(sf::Color::White);
	texture.setOutlineThickness(1.f);
}

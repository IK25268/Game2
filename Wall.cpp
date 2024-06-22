#include "Wall.hpp"

void Wall::Reinforce(Memory& memory)
{
	if (!reinforced)
	{
		int y1 = posY;
		int x1 = posX;
		if (part == 5) x1--;
		if (part == 6) y1--;
		char part1 = memory.walls[y1*memory.cols + x1]->part;
		memory.walls[y1 * memory.cols + x1]->existence = 1;
		memory.walls[y1 * memory.cols + x1]->reinforced = 1;
		y1 = y1 + iterY[part1];
		x1 = x1 + iterX[part1];
		if ((memory.walls[y1 * memory.cols + x1]->part==5)||(memory.walls[y1 * memory.cols + x1]->part == 6))
		{
			memory.walls[y1 * memory.cols + x1]->existence = 1;
			memory.walls[y1 * memory.cols + x1]->reinforced = 1;
			y1 = y1 + iterY[part1];
			x1 = x1 + iterX[part1];
		}
		memory.walls[y1 * memory.cols + x1]->existence = 1;
		memory.walls[y1 * memory.cols + x1]->reinforced = 1;
	}
}

void Wall::TakeDamage(unsigned int damage)
{
	if (!reinforced)
	{
		if (hp >= damage) hp = hp - damage;
		else
		{
			hp = 0;
			existence = 0;
		}
	}
}

void Wall::Destroy(bool typeBreach)
{
	if (!reinforced)
	{
		hp = 0;
		existence = 0;
	}
	else
	{
		if (typeBreach)
		{
			existence = 0;
		}
	}
}

void Wall::Drawing()
{
	texture.setPosition(posX, posY);
	texture.setSize(sf::Vector2f(50.f, 50.f));
	if (reinforced == 1)
	{
		texture.setFillColor(sf::Color(66, 19, 29));
	}
	else
	{
		if (existence == 0) texture.setFillColor(sf::Color(0, 0, 0));
		else texture.setFillColor(sf::Color(hp, hp, 30));
	}
	texture.setOutlineColor(sf::Color::White);
	texture.setOutlineThickness(1.f);
}

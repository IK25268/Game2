#include "Handler.hpp"
#include "SolidWall.hpp"
#include "Device.hpp"
#include "Character.hpp"
#include "AI.hpp"

Handler::Handler()
{
}

Handler::~Handler()
{
}

void Handler::KeyEvent(Memory& memory)
{
	while (memory.window.pollEvent(memory.ev))
	{
		switch (memory.ev.type)
		{
		case sf::Event::Closed:
			memory.window.close();
			break;
		case sf::Event::KeyPressed:
			if (memory.ev.key.code == sf::Keyboard::Escape)
				memory.window.close();
			if (memory.ev.key.code == sf::Keyboard::Num3)
				memory.ReturnPlayer0().PutDevice0(memory);
			if (memory.ev.key.code == sf::Keyboard::R)
				memory.ReturnPlayer0().Reload();
			if (memory.ev.key.code == sf::Keyboard::Num4)
				memory.ReturnPlayer0().PutDevice1(memory);
			if (memory.ev.key.code == sf::Keyboard::Num5)
				memory.ReturnPlayer0().UseDevice(memory);
			if (memory.ev.key.code == sf::Keyboard::Num2)
				memory.ReturnPlayer0().Reinforce(memory);
			if (memory.ev.key.code == sf::Keyboard::Num1)
				memory.ReturnPlayer0().ChangeWeapon();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				memory.ReturnPlayer0().Shoot();
				memory.ReturnPlayer0().keyMouse = 1;
			}
			else memory.ReturnPlayer0().keyMouse = 0;
			if ((memory.ev.key.code == sf::Keyboard::W)||(memory.ev.key.code == sf::Keyboard::A)||(memory.ev.key.code == sf::Keyboard::S)||(memory.ev.key.code == sf::Keyboard::D))
				memory.ReturnPlayer0().Move(memory.ev);
			break;
		}
	}
}

void Handler::Update(Memory& memory)
{
	KeyEvent(memory);
	memory.ReturnPlayer0().Turn(memory);
	for (auto charact : memory.characters)
	{
		charact.second->Drawing();
	}
	for (auto device : memory.devices)
	{
		device.second->Drawing();
	}
	for (auto wall : memory.walls)
	{
		wall.second->Drawing();
	}
	for (auto brain : memory.bots)
	{
		brain.second->calcChance(memory);
	}
}

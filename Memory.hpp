#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <unordered_map>
#include <map>
#include <math.h>
#include <list>
#include <array>
#include <iostream>
#include "utilities.hpp"
#include <ctime>
//#include "SolidWall.hpp"
//#include "Device.hpp"
//#include "Character.hpp"
class SolidWall;
class Device;
class Character;
class AI;

class Memory final {
private:
public:
	Memory(int width, int height);
	~Memory();
	std::unordered_map<long unsigned int, SolidWall*> walls;
	std::unordered_map<long unsigned int, Device*> devices;
	std::unordered_map<int, Character*> characters;
	std::unordered_map<int, AI*> bots;
	sf::RenderWindow window;
	sf::Event ev;
	int cols;
	int rows;
	SolidWall& ReturnWall(int posY, int posX);
	Device& ReturnDevice(int posY, int posX);
	Character& ReturnCharacter(int name);
	SolidWall& ReturnWall(int pos);
	Device& ReturnDevice(int pos);
	Character& ReturnPlayer0(); //костыль
	void CreateWall(SolidWall* wall);
	void CreateDevice(Device* device);
	void CreateCharacter(Character* character);
};



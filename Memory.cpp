#include "Memory.hpp"
#include "SolidWall.hpp"
#include "Device.hpp"
#include "Character.hpp"
#include "Player.hpp"

Memory::Memory(int width, int height) : window(sf::VideoMode(width, height), "Test", sf::Style::Resize | sf::Style::Close), ev()
{
    srand(time(0));
    window.setFramerateLimit(60);
    this->cols = width;
    rows = height;
    Player* player = new Player;
    CreateCharacter(player);
}

Memory::~Memory()
{
}

SolidWall& Memory::ReturnWall(int posY, int posX)
{
    //if (walls.find(posY * cols + posX) == walls.end())
    //{
    //    return nullptr;
    //}
    return *walls[posY * cols + posX];
}

Device& Memory::ReturnDevice(int posY, int posX)
{
    return *devices[posY * cols + posX];
}

SolidWall& Memory::ReturnWall(int pos)
{
    return *walls[pos];
}
Device& Memory::ReturnDevice(int pos)
{
    return *devices[pos];
}
Character& Memory::ReturnCharacter(int name)
{
    return *characters[name];
}
Character& Memory::ReturnPlayer0()
{
    return *characters[0];
}
void Memory::CreateWall(SolidWall* wall)
{
    walls[wall->posY * cols + wall->posX] = wall;
}
void Memory::CreateDevice(Device* device)
{
    devices[device->posY * cols + device->posX] = device;
}
void Memory::CreateCharacter(Character* character)
{
    characters[characters.size()] = character;
}
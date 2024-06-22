#include "Player.hpp"
#include "SolidWall.hpp"
#include "Device.hpp"
#include "Character.hpp"

Player::Player()
{
	speed = 5.0;
	keyMouse = 0;
	hp = 100;
	posX = 10.0;
	posY = 10.0;
	angle = 0;
	ShotGun* shotGun = new ShotGun;
	Assault* assault = new Assault;
	weapons.push_back(shotGun);
	weapons.push_back(assault);
	currPlacedDev = -1; //pos установленного устройства
	countDev0 = 2;
	countDev1 = 2;
	countReinforce = 4;
}

void Player::Drawing()
{
	texture.setPosition(posX, posY);
	texture.setSize(sf::Vector2f(50.f, 50.f));
	texture.setFillColor(sf::Color::Cyan);
	texture.setOutlineColor(sf::Color::Green);
	texture.setOutlineThickness(1.f);
	texture.setRotation(angle);
}

void Player::Reinforce(Memory& memory)
{
	angle = +45;
	if (angle > 360) angle -= 360;
	char orient = angle / 90;
	int i = 0;
	int j = 0;
	switch (orient)
	{
	case 0:
		if (memory.walls.find(SqPos(posY) * memory.cols + NextSqPos(posX)) != memory.walls.end())
		{
			memory.walls[SqPos(posY) * memory.cols + NextSqPos(posX)]->Reinforce(memory);
			countReinforce--;
		}
		break;
	case 1:
		if (memory.walls.find(NextSqPos(posY) * memory.cols + SqPos(posX)) != memory.walls.end())
		{
			memory.walls[NextSqPos(posY) * memory.cols + SqPos(posX)]->Reinforce(memory);
			countReinforce--;
		}
		break;
	case 2:
		if (memory.walls.find(SqPos(posY) * memory.cols + PrevSqPos(posX)) != memory.walls.end())
		{
			memory.walls[SqPos(posY) * memory.cols + PrevSqPos(posX)]->Reinforce(memory);
			countReinforce--;
		}
		break;
	case 3:
		if (memory.walls.find(PrevSqPos(posY) * memory.cols + SqPos(posX)) != memory.walls.end())
		{
			memory.walls[PrevSqPos(posY) * memory.cols + SqPos(posX)]->Reinforce(memory);
			countReinforce--;
		}
		break;
	}
}

void Player::Shoot()
{

}

void Player::Reload()
{

}

void Player::ChangeWeapon()
{
	currWeapon = !currWeapon;
}

void Player::PutDevice0(Memory& memory)
{
	if ((memory.devices.find(SqPos(posY) * memory.cols + SqPos(posX))== memory.devices.end())&&(currPlacedDev == -1))
	{
		SoftBreach* dev = new SoftBreach(SqPos(posY), SqPos(posX), &currPlacedDev, angle);
		memory.CreateDevice(dev);
		currPlacedDev = SqPos(posY) * memory.cols + SqPos(posX);
		countDev0--;
	}
}

void Player::PutDevice1(Memory& memory)
{
	if ((memory.devices.find(SqPos(posY) * memory.cols + SqPos(posX)) == memory.devices.end()) && (currPlacedDev == -1))
	{
		HardBreach* dev = new HardBreach(SqPos(posY), SqPos(posX), &currPlacedDev, angle);
		memory.CreateDevice(dev);
		currPlacedDev = SqPos(posY) * memory.cols + SqPos(posX);
		countDev1--;
	}
}

void Player::UseDevice(Memory& memory)
{
	if (currPlacedDev != -1)
	{
		memory.ReturnDevice(currPlacedDev).Use(memory);
		currPlacedDev = -1;
	}
}

void Player::Move(sf::Event ev)
{
	char fb = 1;
	char lr = 1;
	if (ev.key.code == sf::Keyboard::W) fb--;
	if (ev.key.code == sf::Keyboard::S) fb++;
	if (ev.key.code == sf::Keyboard::A) lr--;
	if (ev.key.code == sf::Keyboard::D) lr++;
	float angle1 = angle + dangle[fb][lr];
	if (angle1 > 360.0) angle1 = angle1 - 360.0;
	posX = posX + speed * cos(angle1 * (acos(-1.0) / 180));
	posY = posY + speed * sin(angle1 * (acos(-1.0) / 180));
	std::cout << "DEBUG";
}

void Player::Turn(Memory& memory)
{
	angle = (atan2(sf::Mouse::getPosition(memory.window).y - posY, sf::Mouse::getPosition(memory.window).x - posX)) * 180 / acos(-1.0);
}

void Player::TakeDamage(int damage, Memory& memory)
{
	hp = -damage;
	if (hp <= 0)
	{
		Death(memory);
	}
}

void Player::Death(Memory& memory)
{
	hp = 100;
	posX = 10.0;
	posY = 10.0;
}

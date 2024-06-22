#include "Shotgun.hpp"

ShotGun::ShotGun()
{
	damage = 100;
	capacity = 5;
	angleFire = 10;
	reductDist = 1;
	timeReload = 0;
}

void ShotGun::Shoot(bool keyFlag)
{
	if ((capacity > 0)&&(!keyFlag)&&(timeReload == 0))
	{

		keyFlag = 1;
		capacity--;
	}
}

void ShotGun::Reload()
{
	if (timeReload == 0)
	{
		timeReload++;
	}
}

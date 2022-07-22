#pragma once

#include "Entity.h"
#include "Missile.h"
#include <vector>

class SpaceShip: public Entity
{
private:
	std::vector<Missile*> missiles;
	double scrollX;
	double timeReload;
	bool aim;
	int imortal;
	int ammunition;

	int MISSILE_SHOOT_SFX;
	int MISSILE_EXPLODE_SFX;

public:
	SpaceShip(const char *filename, double width, double height);
	~SpaceShip();

	void move();
	void appear();

	
	bool getImortal();
	int getAmmunition();
	void setImortal(int time_duration);
	void resetPlayer();
	void shoot();
	void reload();

	std::vector<Missile*> getMissiles();

	void missileExplode(int index);

	void clearMissiles();
};


#pragma once
#include "Entity.h"

class Missile: public Entity 
{
private:
	double scrollX;
	double launched;
	double speed_x;
	double speed_y;

public:

	Missile(double x, double y, double speed_x, double speed_y);
	~Missile();

	void move();
	void appear();

};


#pragma once
#include "Entity.h"

class Meteor: public Entity
{
private:
	double speed_x;
	double speed_y;

public:
	Meteor(const char *filename, double width, double height, double x, double y, double speed_x, double speed_y);
	~Meteor();

	void move();
	void changeDirection(double sx, double sy);
	double getSpeedY();

};


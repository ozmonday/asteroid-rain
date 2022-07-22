#pragma once
#include "Entity.h"

class HealtLevel: public Entity
{
private:
	double level;

public:
	HealtLevel(const char* filename, double x, double y, double width, double height);
	~HealtLevel();
	void appear();
	bool isGameOver();
	void decreaseLevel();
	void resetHealt();
};


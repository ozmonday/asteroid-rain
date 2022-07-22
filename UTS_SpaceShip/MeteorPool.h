#pragma once
#include <vector>
#include "Meteor.h"
#include "Entity.h"


struct bump
{
	int one;
	int two;
};

class MeteorPool
{
private:
	double start;
	int capacity;
	int cordinat[10] = {21, 63, 105, 147, 189, 231, 273, 315, 357, 399};
	std::vector<Meteor*> pool;

public:
	MeteorPool(int init_Size, int capacity);

	~MeteorPool();

	void appearState();

	void changeState();

	int isMeteorBump(Entity *entity);

	void clearMeteors();

	void deleteMeteor(int index);
};


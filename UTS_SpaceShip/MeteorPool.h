#pragma once
#include <vector>
#include "meteor.h"
class MeteorPool
{
private:
	int capacity;
	std::vector<meteor*> pool;

	void deleteState();

public:
	MeteorPool(int init_Size, int capacity);

	~MeteorPool();

	void appearState();

	void changeState();

	bool isMeteorBump(double x, double y, double w, double h);

	void clearMeteors();


};


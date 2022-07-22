#include "MeteorPool.h"
#include "Meteor.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include "sl.h"


MeteorPool::MeteorPool(int init_size, int capacity) : capacity(capacity), start(slGetTime()) {
	for (int i = 0; i < init_size; i++) {
		double speed_y = rand() % 10;
		if (speed_y < 1) {
			speed_y = 2;
		}

		int index = rand() % 10;
		pool.push_back(new Meteor("assets/image/meteor_1.png", 42, 42, cordinat[index], 762, 0, speed_y));
	}
}

MeteorPool::~MeteorPool() {

}

void MeteorPool::appearState() {
	for (size_t i = 0; i < pool.size(); i++) {
		pool[i]->appear();
	}
}

void MeteorPool::changeState() {
	if (pool.size() < capacity) {
		double speed_y = rand()%4;
		if (speed_y < 1) {
			speed_y = 1.5;
		}

		int index = rand() % 10;
		pool.push_back(new Meteor("assets/image/meteor_1.png", 42, 42, cordinat[index], 762, 0, speed_y));
	}

	for (size_t i = 0; i < pool.size(); i++) {
		if (pool[i]->getY() < -42) {
			delete pool[i];
			pool.erase(pool.begin() + i);
		}
		else
		{
			pool[i]->move();
		}
	}
	std::vector<bump> idx;
	for (size_t i = 0; i < pool.size(); i++) {
		for (size_t y = 0; y < pool.size(); y++) {
			if (i == y || pool[i]->getSpeedY() == pool[y]->getSpeedY()) {
				continue;
			}
			else
			{
				if (pool[i]->isBump(pool[y], 0.1)) {
					bool skip = false;
					bump c;
					c.one = i;
					c.two = y;
					for (size_t d = 0; d < idx.size(); d++) {
						if (idx[d].one == c.two && idx[d].two == c.one) {
							skip = true;
						}
					}
					if (!skip) {
						idx.push_back(c);
						//std::cout << i << " bertumbukan " << y << std::endl;
					}
				}
			}
		}
	}


	for (size_t ix = 0; ix < idx.size(); ix++) {
		int idxFaster;
		if (pool[idx[ix].one]->getSpeedY() > pool[idx[ix].two]->getSpeedY()) {
			idxFaster = idx[ix].one;
		}
		else
		{
			idxFaster = idx[ix].two;
		}

		double speed = pool[idxFaster]->getSpeedY() * 0.5;
		if (idx[ix].one == idxFaster) {
			double s = pool[idx[ix].one]->getSpeedY() - speed;
			pool[idx[ix].one]->changeDirection(0, s);
		}
		else
		{
			double s = pool[idx[ix].one]->getSpeedY() + speed;
			pool[idx[ix].one]->changeDirection(0, s);
		}

		if (idx[ix].two == idxFaster) {
			double s = pool[idx[ix].two]->getSpeedY() - speed;
			pool[idx[ix].two]->changeDirection(0, s);
		}
		else
		{
			double s = pool[idx[ix].two]->getSpeedY() + speed;
			pool[idx[ix].two]->changeDirection(0, s);
		}
	}
}


int MeteorPool::isMeteorBump(Entity *entity) {

	for (size_t i = 0; i < pool.size(); i++) {

		if (pool[i]->getY() <= 22) {
			continue;
		}

		if (pool[i]->isBump(entity, 0.15)) {
			return i;
		}		
			
	}

	return -1;
}

void MeteorPool::clearMeteors() {
	for (size_t i = 0; i < pool.size(); i++) {
		delete pool[i];
	}
	pool.clear();
}


void MeteorPool::deleteMeteor(int index) {
	delete pool[index];
	pool.erase(pool.begin() + index);
}
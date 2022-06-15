#include "MeteorPool.h"
#include "meteor.h"
#include <algorithm>


MeteorPool::MeteorPool(int init_size, int capacity) : capacity(capacity) {
	for (int i = 0; i < init_size; i++) {
		double speed_y = rand() % 4;
		if (speed_y < 1) {
			speed_y = 1.5;
		}

		double position_x = rand() % 399;
		if (position_x <= 21) {
			position_x = 21;
		}
		pool.push_back(new meteor("assets/image/meteor_1.png", 42, 42, position_x, 762, 0, speed_y));
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
		double position_x = rand() % 399;
		if (position_x <= 21) {
			position_x = 21;
		}
		pool.push_back(new meteor("assets/image/meteor_1.png", 42, 42, position_x, 762, 0, speed_y));
	}
	for (size_t i = 0; i < pool.size(); i++) {
		pool[i]->move();
	}

	deleteState();

}

void MeteorPool::deleteState() {
	for (size_t i = 0; i < pool.size(); i++) {
	
		if (pool[i]->getPositionY() < -42) {
			delete pool[i];
			pool.erase(pool.begin() + i);
		}
	}
}

bool MeteorPool::isMeteorBump(double x, double y, double w, double h) {

	double max_x = x + (w / 2.0);
	double max_y = y + (h / 2.0);
	double min_x = x - (w / 2.0);
	double min_y = y - (h / 2.0);
	double box1[4] = { min_x, min_y, max_x, max_y };
	double box1_area = std::abs(w) * std::abs(h);

	for (size_t i = 0; i < pool.size(); i++) {

		if (pool[i]->getPositionY() <= 22) {
			continue;
		}

		double max_xas = pool[i]->getPositionX() + (pool[i]->getWidth() / 2.0);
		double max_yas = pool[i]->getPositionY() + (pool[i]->getHeight() / 2.0);
		double min_xas = pool[i]->getPositionX() - (pool[i]->getWidth() / 2.0);
		double min_yas = pool[i]->getPositionY() - (pool[i]->getHeight() / 2.0);

		double box2[4] = { min_xas, min_yas, max_xas, max_yas };
		double box2_area = std::abs(pool[i]->getWidth()) * std::abs(pool[i]->getHeight());

		double x_inter1 = std::max(box1[0], box2[0]);
		double y_inter1 = std::max(box1[1], box2[1]);
		double x_inter2 = std::min(box1[2], box2[2]);
		double y_inter2 = std::min(box1[3], box2[3]);


		double width_inter = std::max(0.0, x_inter2 - x_inter1);
		double height_inter = std::max(0.0, y_inter2 - y_inter1);

		double area_inter = width_inter * height_inter;
		double area_union = (box1_area + box2_area) - area_inter;

		double iou = area_inter / area_union;

		if (iou >= 0.15) {
			return true;
		}		
			
	}

	return false;
}

void MeteorPool::clearMeteors() {
	for (size_t i = 0; i < pool.size(); i++) {
		delete pool[i];
	}
	pool.clear();
}
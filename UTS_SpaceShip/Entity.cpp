#include "Entity.h"
#include "sl.h"
#include <algorithm>
#include <iostream>


Entity::Entity(const char* filename, double x, double y, double width, double height) : id(slLoadTexture(filename)), X(x), Y(y), width(width), height(height) {

}

Entity::~Entity() {

}

void Entity::changePosition(double x, double y) {
	X = x;
	Y = y;
}

bool Entity::isBump(Entity *entity, double threshold) {
	double maxX, maxY, minX, minY;
	
	maxX = entity->X + (entity->width / 2.0);
	maxY = entity->Y + (entity->height / 2.0);
	minX = entity->X - (entity->width / 2.0);
	minY = entity->Y - (entity->height / 2.0);
	
	double box1[4] = { minX, minY, maxX, maxY };
	double boxArea1 = std::abs(entity->width) * std::abs(entity->height);

	maxX = X + (width / 2.0);
	maxY = Y + (height / 2.0);
	minX = X - (width / 2.0);
	minY = Y - (height / 2.0);

	double box2[4] = { minX, minY, maxX, maxY };
	double boxArea2 = std::abs(width) * std::abs(height);

	double interX1, interX2, interY1, interY2;

	interX1 = std::max(box1[0], box2[0]);
	interY1 = std::max(box1[1], box2[1]);
	interX2 = std::min(box1[2], box2[2]);
	interY2 = std::min(box1[3], box2[3]);;

	double widthInter, heightInter;

	widthInter = std::max(0.0, interX2 - interX1);
	heightInter = std::max(0.0, interY2 - interY1);

	double areaInter, areaUnion, IoU;

	areaInter = widthInter * heightInter;
	areaUnion = (boxArea1 + boxArea2) - areaInter;
	IoU = areaInter / areaUnion;

	if (IoU >= threshold) {
		return true;
	}

	return false;
}

void Entity::appear() {
	slSprite(id, X, Y, width, height);
}

double Entity::getHeight() {
	return height;
}

double Entity::getWidth() {
	return width;
}

double Entity::getX() {
	return X;
}

double Entity::getY() {
	return Y;
}
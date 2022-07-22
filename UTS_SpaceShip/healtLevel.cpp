#include "HealtLevel.h"
#include "Entity.h"
#include<sl.h>

HealtLevel::HealtLevel(const char* filename, double x, double y, double width, double height) : Entity(filename, x, y, width, height),  level(0.0) {

}

HealtLevel::~HealtLevel() {}

void HealtLevel::appear() {
	slSetSpriteTiling(0.2, 1);
	slSetSpriteScroll(level, 0);
	slSprite(id, X, Y, 90, height - 20);
	slSetSpriteScroll(0, 0);
	slSetSpriteTiling(1, 1);
}

void HealtLevel::decreaseLevel() {
	if (level < 0.8) {
		level += 0.2;
	}
	else
	{
		level = 0.0;
	}
}

bool HealtLevel::isGameOver() {
	if (level == 0.8) {
		return true;
	}
	return false;
}

void HealtLevel::resetHealt() {
	level = 0.0;
}
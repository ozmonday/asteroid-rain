#include "healtLevel.h"
#include<sl.h>

healtLevel::healtLevel(const char* filename, double x, double y, double width, double height) : id(slLoadTexture(filename)), position_x(x), position_y(y), w(width), h(height), level(0.0) {

}

healtLevel::~healtLevel() {}

void healtLevel::appear() {
	slSetSpriteTiling(0.2, 1);
	slSetSpriteScroll(level, 0);
	slSprite(id, position_x, position_y, 90, h-20);
	slSetSpriteScroll(0, 0);
	slSetSpriteTiling(1, 1);
}

void healtLevel::decreaseLevel() {
	if (level < 0.8) {
		level += 0.2;
	}
	else
	{
		level = 0.0;
	}
}

bool healtLevel::isGameOver() {
	if (level == 0.8) {
		return true;
	}
	return false;
}

void healtLevel::resetHealt() {
	level = 0.0;
}
#include "spaceship.h"
#include "sl.h"

spaceship::spaceship(const char* filename, const char* fn_imortal, double width, double height) : w(width), h(height), id(slLoadTexture(filename)), id_imortal(slLoadTexture(fn_imortal)), point_x(210), point_y(50), scroll_y(0.0), scroll_y_imortal(0.0), imortal(0) {
	
}

spaceship::~spaceship() {

}

void spaceship::appear() {
	if (imortal > 0) {
		slSetSpriteTiling(1, 0.1);
		slSetSpriteScroll(0, scroll_y_imortal);
		slSprite(id_imortal, point_x, point_y, w, 59);
		slSetSpriteScroll(0, 0);
		slSetSpriteTiling(1, 1);
		if (scroll_y_imortal == 1) {
			scroll_y_imortal = 0.0;
		}
		else
		{
			scroll_y_imortal += 0.1;
		}
		imortal--;
	}
	else
	{
		slSetSpriteTiling(1, 0.5);
		slSetSpriteScroll(0, scroll_y);
		slSprite(id, point_x, point_y, w, h - 59);
		slSetSpriteScroll(0, 0);
		slSetSpriteTiling(1, 1);
		if (scroll_y == 1) {
			scroll_y = 0.0;
		}
		else
		{
			scroll_y += 0.5;
		}
	}

}

bool spaceship::isBump(double x, double y) {
	if (point_x == x && point_y == y) {
		return true;
	}
	return false;
}

void spaceship::move() {

	if (slGetKey(SL_KEY_UP) == 1) {
		if (point_y < 690.5) {
			point_y += 1.5;
		}
	}

	if (slGetKey(SL_KEY_DOWN) == 1) {
		if (point_y > 29.5) {
			point_y -= 1.5;
		}
	}

	if (slGetKey(SL_KEY_LEFT) == 1) {
		if (point_x > 29.5) {
			point_x -= 1.5;
		}
	}

	if (slGetKey(SL_KEY_RIGHT) == 1) {
		if (point_x < 390.5) {
			point_x += 1.5;
		}
	}

}

double spaceship::getPointX() {
	return point_x;
}

double spaceship::getPointY() {
	return point_y;
}

double spaceship::getWidth() {
	return w;
}

double spaceship::getHeight() {
	return h/2.0;
}

bool spaceship::getImortal() {
	if (imortal > 0) {
		return true;
	}
	return false;
}

void spaceship::setImortal(int time_duration) {
	imortal = time_duration;
}

void spaceship::resetPlayer() {
	point_x = 210;
	point_y = 50;
	imortal = 0;
}
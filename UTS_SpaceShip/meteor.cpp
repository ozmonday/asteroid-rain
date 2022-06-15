#include "meteor.h"
#include "sl.h"


meteor::meteor(const char* filename, double width, double height, double x, double y, double speed_x, double speed_y) : id(slLoadTexture(filename)), w(width), h(height), point_x(x), point_y(y), speed_x(speed_x), speed_y(speed_y) {

}

meteor::~meteor() {
}

void meteor::appear() {
	slSprite(id, point_x, point_y, w, h);
}

void meteor::move() {
	point_x -= speed_x;
	point_y -= speed_y;
}

void meteor::changeDirection(double sx, double sy) {
	speed_x = sx;
	speed_y = sy;
}

double meteor::getPositionY() {
	return point_y;
}

double meteor::getPositionX() {
	return point_x;
}

double meteor::getWidth() {
	return w;
}

double meteor::getHeight() {
	return h;
}
#include "Meteor.h"
#include "sl.h"


Meteor::Meteor(const char* filename, double width, double height, double x, double y, double speed_x, double speed_y) : Entity(filename, x, y, width, height), speed_x(speed_x), speed_y(speed_y) {

}

Meteor::~Meteor() {
}


void Meteor::move() {
	changePosition(X - speed_x, Y - speed_y);
}

void Meteor::changeDirection(double s_x, double s_y) {
	speed_x = s_x;
	speed_y = s_y;
}


double Meteor::getSpeedY() {
	return speed_y;
}


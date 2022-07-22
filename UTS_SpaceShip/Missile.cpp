#include "Missile.h"
#include "sl.h"

Missile::Missile(double x, double y, double speed_x, double speed_y ) : Entity("assets/image/missile.png", x, y, 15, 32), speed_x(speed_x), speed_y(speed_y), launched(slGetTime()), scrollX(0.0) {
	
}

Missile::~Missile() {
}

void Missile::move() {
	double a = slGetTime() - launched;
	changePosition(X + (speed_x * a), Y + (speed_y * a));
}

void Missile::appear() {
	slSetSpriteTiling(0.5, 1);
	slSetSpriteScroll(scrollX, 0);
	slSprite(id, X, Y, width, height);
	slSetSpriteScroll(0, 0);
	slSetSpriteTiling(1, 1);
	if (scrollX == 1) {
		scrollX = 0.0;
	}
	else {
		scrollX += 0.5;
	}
}

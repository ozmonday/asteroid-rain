#include "SpaceShip.h"
#include "Missile.h"
#include "sl.h"
#include <iostream>
#include <vector>

SpaceShip::SpaceShip(const char* filename, double width, double height) : Entity(filename, 210, 50, width, height), scrollX(0.0), imortal(0), aim(false), ammunition(6), timeReload(slGetTime()+15) {
	MISSILE_SHOOT_SFX = slLoadWAV("assets/effect/missile_shoot.wav");
	MISSILE_EXPLODE_SFX = slLoadWAV("assets/effect/missile_explode.wav");
}

SpaceShip::~SpaceShip() {

}

void SpaceShip::appear() {
	double time = slGetTime();

	if (missiles.size() > 0) {
		for (size_t i = 0; i < missiles.size(); i++) {
			missiles[i]->appear();
		}
	}

	slSetSpriteTiling(0.25, 0.5);
	if (time < imortal) {
		slSetSpriteScroll(scrollX, 0);
	}
	else {
		slSetSpriteScroll(scrollX, 0.5);
	}

	slSprite(id, X, Y, width, height);
	slSetSpriteScroll(0, 0);
	slSetSpriteTiling(1, 1);
	if (scrollX == 1) {
		scrollX = 0.0;
	}
	else {
		scrollX += 0.25;
	}


}


void SpaceShip::move() {

	if (slGetKey(SL_KEY_UP) == 1) {
		if (Y < 690.5) {
			Y += 1.5;
		}
	}

	if (slGetKey(SL_KEY_DOWN) == 1) {
		if (Y > 29.5) {
			Y -= 1.5;
		}
	}

	if (slGetKey(SL_KEY_LEFT) == 1) {
		if (X > 29.5) {
			X -= 1.5;
		}
	}

	if (slGetKey(SL_KEY_RIGHT) == 1) {
		if (X < 390.5) {
			X += 1.5;
		}
	}

	if (missiles.size() > 0) {
		for (size_t i = 0; i < missiles.size(); i++) {
			if (missiles[i]->getY() > 752) {
				delete missiles[i];
				missiles.erase(missiles.begin() + i);
			}
			else
			{
				missiles[i]->move();
			}
		}
	}
}



bool SpaceShip::getImortal() {
	if (imortal > slGetTime()) {
		return true;
	}
	return false;
}

void SpaceShip::setImortal(int time_duration) {
	imortal = slGetTime()  + time_duration;
}

void SpaceShip::resetPlayer() {
	X = 210;
	Y = 50;
	imortal = slGetTime() + 3;
	ammunition = 6;
}

void SpaceShip::shoot() {
	if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT) == 1) {
		aim = true;
	}

	if (aim == true && slGetMouseButton(SL_MOUSE_BUTTON_LEFT) == 0) {
		if (ammunition > 0) {
			slSoundPlay(MISSILE_SHOOT_SFX);
			missiles.push_back(new Missile(X, Y, 0, 1));
			ammunition -= 1;
		}
		aim = false;
	}
}

void SpaceShip::reload() {
	if (slGetTime() >= timeReload) {
		if (ammunition < 6) {
			ammunition += 1;
		}
		timeReload = slGetTime() + 15;
	}
}


void SpaceShip::missileExplode(int index) {
	slSoundPlay(MISSILE_EXPLODE_SFX);
	delete missiles[index];
	missiles.erase(missiles.begin() + index);
}

std::vector<Missile*> SpaceShip::getMissiles() {
	return missiles;
}


void SpaceShip::clearMissiles() {
	for (size_t i = 0; i < missiles.size(); i++) {
		delete missiles[i];
	}

	missiles.clear();
}

int SpaceShip::getAmmunition() {
	return ammunition;
}
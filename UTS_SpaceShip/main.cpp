#include <sl.h>
#include "Meteor.h"
#include "MeteorPool.h"
#include "SpaceShip.h"
#include "HealtLevel.h"
#include "Score.h"
#include "MissileStock.h"
#include <vector>

#define WINDOW_W 420
#define WINDOW_H 720



int main() {

	slWindow(WINDOW_W, WINDOW_H, "space ship", 0);

	MeteorPool pooling = MeteorPool(5, 35);
	SpaceShip player = SpaceShip("assets/image/spaceship.png", 59, 59);
	HealtLevel healt = HealtLevel("assets/image/helth_level.png", 350, 690, 800, 40);
	MissileStock stock = MissileStock("assets/image/missile_stock.png", 350, 660, 700, 40);
	Score score = Score(20, 685);

	int explode = slLoadWAV("assets/effect/ship_explode.wav");
	int thameMusic = slLoadWAV("assets/effect/on_my_way.wav");
	int background = slLoadTexture("assets/image/background.png");
	double scroll_background = 0.0;
	int sound = slSoundLoop(thameMusic);
	while (!slShouldClose()) {

		slSetSpriteScroll(0, scroll_background);
		slSprite(background, WINDOW_W / 2, WINDOW_H / 2, WINDOW_W, WINDOW_H);
		slSetSpriteScroll(0, 0);



		if (healt.isGameOver()) {
			slSoundPause(sound);
			score.appearLastScore();
			int restart = slGetKey(SL_KEY_ENTER);
			if (restart == 1) {
				pooling.clearMeteors();
				player.clearMissiles();
				healt.resetHealt();
				score.resetScore();
				player.resetPlayer();
			}
		}
		else {
			auto missiles = player.getMissiles();
			std::vector<int> missile_idx;

			slSoundResumeAll();
			pooling.appearState();
			player.appear();
			score.appear();
			healt.appear();
			stock.appear();

			player.move();
			player.shoot();
			stock.updateStock(player.getAmmunition());
			player.reload();
			pooling.changeState();
			score.changeScore(0.02);

			for (size_t i = 0; i < missiles.size(); i++) {
				int bump = pooling.isMeteorBump(missiles[i]);
				if (bump != -1) {
					pooling.deleteMeteor(bump);
					missile_idx.push_back(i);
				}
			}

			for (size_t i = 0; i < missile_idx.size(); i++) {
				player.missileExplode(missile_idx[i]);
			}

			if (!player.getImortal()) {
				int bump = pooling.isMeteorBump(&player);
				if (bump != -1) {
					healt.decreaseLevel();
					player.setImortal(3);
					int play = slSoundPlay(explode);
				}
			}
			if (scroll_background >= 1) {
				scroll_background = 0.0;
			}
			else
			{
				scroll_background += 0.002;
			}

		}

		slRender();
	}

	slClose();
	return 0;
}
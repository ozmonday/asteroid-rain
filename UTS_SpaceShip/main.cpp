#include <sl.h>
#include "meteor.h"
#include "MeteorPool.h"
#include "spaceship.h"
#include "healtLevel.h"
#include "Score.h"

#define WINDOW_W 420
#define WINDOW_H 720



int main() {

	slWindow(WINDOW_W, WINDOW_H, "space ship", 0);

	MeteorPool pooling = MeteorPool(4, 20);
	spaceship player = spaceship("assets/image/spaceship.png", "assets/image/spaceship_im.png", 59, 118);
	healtLevel healt = healtLevel("assets/image/helth_level.png", 350, 690, 800, 40);
	Score score = Score(20, 685);

	int thameSong = slLoadWAV("assets/effect/ship_explode.wav");
	int background = slLoadTexture("assets/image/background.png");
	double scroll_background = 0.0;

	while (!slShouldClose()) {

		slSetSpriteScroll(0, scroll_background);
		slSprite(background, WINDOW_W / 2, WINDOW_H / 2, WINDOW_W, WINDOW_H);
		slSetSpriteScroll(0, 0);



		if (healt.isGameOver()) {
			score.appearLastScore();
			int restart = slGetKey(SL_KEY_ENTER);
			if (restart == 1) {
				pooling.clearMeteors();
				healt.resetHealt();
				score.resetScore();
				player.resetPlayer();
			}
		}
		else {
			pooling.appearState();
			player.appear();
			score.appear();
			player.move();
			pooling.changeState();
			score.changeScore(0.02);

		}

		healt.appear();

		if (!player.getImortal()) {
			bool bump = pooling.isMeteorBump(player.getPointX(), player.getPointY(), player.getWidth(), player.getHeight());
			if (bump) {
				healt.decreaseLevel();
				player.setImortal(200);
				int play = slSoundPlay(thameSong);
			}
		}
		if (scroll_background >= 1) {
			scroll_background = 0.0;
		}
		else
		{
			scroll_background += 0.002;
		}
		slRender();
	}

	slClose();
	return 0;
}
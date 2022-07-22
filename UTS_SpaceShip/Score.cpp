#include "Score.h"
#include <sl.h>
#include <string>
#include <iostream>

Score::Score(double x, double y) : X(x), Y(y), score(0.0), fontId(slLoadFont("assets/font/pixelboy.ttf")) {

}

Score::~Score() {

}

void Score::appear() {
	int tmp = score;
	std::string scr =  "SCORE: "  + std::to_string(tmp);

	slSetFont(fontId, 22);
	slSetTextAlign(SL_ALIGN_LEFT);
	slText(X, Y, scr.c_str());

}

void Score::appearLastScore() {
	int tmp = score;
	std::string scr = std::to_string(tmp);
	slSetFont(fontId, 28);
	slSetTextAlign(SL_ALIGN_CENTER);
	slSetFontSize(42);
	slText(210, 320, "GAME OVER!");
	slSetFontSize(14);
	slText(210, 295, "YOUR SCORE:");
	slSetFontSize(28);
	slText(210, 270, scr.c_str());

	int time = slGetTime();
	if (time % 2 == 1) {
		slSetFontSize(16);
		slText(210, 250, "PRESS ENTER TO RESTART");
	}

}

void Score::changeScore(double append) {
	score += append;
};

int Score::getScore() {
	return score;
}

void Score::resetScore() {
	score = 0.0;
}






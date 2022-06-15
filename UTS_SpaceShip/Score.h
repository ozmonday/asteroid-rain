#pragma once
class Score
{
private:
	int fontId;
	double score;
	double point_x;
	double point_y;

public:
	Score(double x, double y);
	~Score();

	void appear();
	void changeScore(double append);
	int getScore();
	void resetScore();
	void appearLastScore();

};


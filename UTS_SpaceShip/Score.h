#pragma once
class Score
{
private:
	int fontId;
	double score;
	double X;
	double Y;

public:
	Score(double x, double y);
	~Score();

	void appear();
	void changeScore(double append);
	int getScore();
	void resetScore();
	void appearLastScore();

};


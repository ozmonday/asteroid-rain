#pragma once

class healtLevel
{
private:
	int id;
	double position_x;
	double position_y;
	double w;
	double h;
	double level;

public:
	healtLevel(const char* filename, double x, double y, double width, double height);
	~healtLevel();
	void appear();
	bool isGameOver();
	void decreaseLevel();
	void resetHealt();
};


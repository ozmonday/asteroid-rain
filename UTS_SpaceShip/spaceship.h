#pragma once
class spaceship
{
private:
	int id;
	int id_imortal;
	double point_x;
	double point_y;
	double scroll_y;
	double scroll_y_imortal;
	double w;
	double h;
	int imortal;

public:
	spaceship(const char *filename, const char *fn_imortal, double width, double height);
	~spaceship();

	void move();
	void appear();
	bool isBump(double x, double y);
	double getPointY();
	double getPointX();
	double getHeight();
	double getWidth();
	bool getImortal();
	void setImortal(int time_duration);
	void resetPlayer();
};


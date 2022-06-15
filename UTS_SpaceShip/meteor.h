#pragma once


class meteor
{
private:
	int id;
	double point_x;
	double point_y;
	double speed_x;
	double speed_y;
	double w;
	double h;
	
public:
	meteor(const char *filename, double width, double height, double x, double y, double speed_x, double speed_y);
	~meteor();
	void appear();
	void move();
	void changeDirection(double sx, double sy);
	double getPositionY();
	double getPositionX();
	double getHeight();
	double getWidth();
	
};


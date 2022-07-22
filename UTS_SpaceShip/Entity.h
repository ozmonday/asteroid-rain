#pragma once
class Entity
{
protected:
	int id;
	double X;
	double Y;
	double width;
	double height;

public:
	Entity(const char* filename, double XPosition, double YPosition, double width, double height);
	~Entity();
	void appear();
	void changePosition(double x, double y);
	bool isBump(Entity *entity, double threshold);
	double getWidth();
	double getHeight();
	double getX();
	double getY();
};


#pragma once
#include "Entity.h"
class MissileStock: public Entity 
{
private:
	double stock;
public:
	MissileStock(const char* filename, double x, double y, double width, double height);
	~MissileStock();

	void appear();
	void updateStock(int stock);
};


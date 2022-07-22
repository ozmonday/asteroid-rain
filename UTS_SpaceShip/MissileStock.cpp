#include "MissileStock.h"
#include "Entity.h"
#include "sl.h"

MissileStock::MissileStock(const char* filename, double x, double y, double width, double height) : Entity(filename, x, y, width, height), stock(0.0) {

}

MissileStock::~MissileStock() {}


void MissileStock::appear() {
	slSetSpriteTiling(1.0/7, 1);
	slSetSpriteScroll(stock, 0);
	slSprite(id, X, Y, 70, height - 20);
	slSetSpriteScroll(0, 0);
	slSetSpriteTiling(1, 1);
}



void MissileStock::updateStock(int stc) {
	switch (stc)
	{
	case 0:
		stock = (1.0 * 6) / 7;
		break;
	case 1:
		stock = (1.0 * 5) / 7;
		break;
	case 2:
		stock = (1.0 * 4) / 7;
		break;
	case 3:
		stock = (1.0 * 3) / 7;
		break;
	case 4:
		stock = (1.0 * 2) / 7;
		break;
	case 5:
		stock = (1.0 * 1) / 7;
		break;
	case 6:
		stock = 0.0;
		break;
	default:
		break;
	}

}
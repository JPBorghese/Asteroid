
#include "Player.h"

void init(struct Player* a, 
	int x, int y, 
	float xspd, float yspd, 
	float r, 
	void (*rendFunc)(Thing*)){
	a->x = x;
	a->y = y;
	a->xspd = xspd;
	a->yspd = yspd;
	a->radius = r;
	a->render = rendFunc;
}


#include "include.h"

Bullet* initBullet(
	float x,
	float y,
	float xspd,
	float yspd,
	float radius) {

	Bullet* a = malloc(sizeof(Bullet));

	a->x = x;
	a->y = y;
	a->xspd = xspd;
	a->yspd = yspd;
	a->radius = radius;
	a->c = WHITE;

	a->render = renderBullet;
	a->update = updateBullet;

	return a;
}

void updateBullet(Bullet* b) {

	// Xcollision
	if(b->x + b->xspd > *(getWindowWidth())) {
		b->x = 0;
	}
	else if (b->x + b->xspd < 0) {
		b->x = *(getWindowWidth());
	}

	// Ycollision
	if(b->y + b->yspd > *(getWindowHeight())) {
		b->y = 0;
	}
	else if (b->y + b->yspd < 0) {
		b->y = *(getWindowHeight());
	}
	
	b->x += b->xspd;
	b->y += b->yspd;

}

void renderBullet(Bullet* b) {

	DrawCircle(
		b->x, 
		b->y, 
		b->radius, 
		b->c);
}

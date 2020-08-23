
#include "include.h"

Enemy* initEnemy(
	float x, 
	float y, 
	float xspd, 
	float yspd, 
	float radius){

	Enemy* a = malloc(sizeof(Enemy));

	a->x = x;
	a->y = y;
	a->xspd = xspd;
	a->yspd = yspd;
	a->radius = radius;
	a->render = renderEnemy;
	a->update = updateEnemy;

	a->c = randomColor();

	return a;
}

void updateEnemy(Enemy* e) {

	// Xcollision
	if(e->x + e->xspd > *(getWindowWidth())) {
		e->x = 0;
	}
	else if (e->x + e->xspd < 0) {
		e->x = *(getWindowWidth());
	}

	// Ycollision
	if(e->y + e->yspd > *(getWindowHeight())) {
		e->y = 0;
	}
	else if (e->y + e->yspd < 0) {
		e->y = *(getWindowHeight());
	}
	
	e->x += e->xspd;
	e->y += e->yspd;
}

void renderEnemy(Enemy* e) {
DrawCircle(
		e->x, 
		e->y, 
		e->radius, 
		e->c);

}


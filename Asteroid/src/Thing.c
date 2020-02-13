
#include "include.h"

void init(Thing* a, 
	float x, float y, 
	float xspd, float yspd, 
	void (*rendFunc)(Thing*),
	void (*updateFunc)(Thing*)){

	a->x = x;
	a->y = y;
	a->xspd = xspd;
	a->yspd = yspd;
	a->render = rendFunc;
	a->update = updateFunc;
}

void destroy(Thing* t) {
	free(t);
}



#pragma once

#include "Thing.h"

struct Enemy {
	float x;
	float y;

	float xspd;
	float yspd;

	void (*render)(struct Enemy*);
	void (*update)(struct Enemy*);

	float radius;

	Color c;
};

typedef struct Enemy Enemy;

Enemy* initEnemy(
	float x,
	float y,
	float xspd,
	float yspd,
	float radius);

void renderEnemy(Enemy*);
void updateEnemy(Enemy*);

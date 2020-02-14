#pragma once

#include "Thing.h"

struct Bullet {
	float x;
	float y;

	float xspd;
	float yspd;

	void (*render)(struct Bullet*);
	void (*update)(struct Bullet*);

	float radius;
	float damage;

	Color c;
};

typedef struct Bullet Bullet;

Bullet* initBullet(
	float x,
	float y,
	float xspd,
	float yspd,
	float radius);


void renderBullet(Bullet*);
void updateBullet(Bullet*);


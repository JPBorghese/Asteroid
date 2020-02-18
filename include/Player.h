
#pragma once

#include "Thing.h"

struct Player {
	float x;
	float y;
	float xspd;
	float yspd;
	void (*render)(struct Player*);
	void (*update)(struct Player*);

	float length;
	float width;
	float radius;
	float angle;		// degrees
	float angleAccel;
	float accel;
	float maxSpeed;
	float bulletSpeed;

	Color c;
};

typedef struct Player Player;

Player* initPlayer(
	float x,
	float y,
	float radius,
	float width,
	float height);


void renderPlayer(Player*);
void updatePlayer(Player*);


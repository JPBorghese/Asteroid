
#pragma once

#include <stddef.h>

enum type {
	THING, 
	PLAYER, 
	ENEMY
};

struct Thing {
	float x;
	float y;

	float xspd;
	float yspd;

	void (*render)(struct Thing*);
	void (*update)(struct Thing*);
};

typedef struct Thing Thing;

void init(Thing*,
	float x,
	float y,
	float spdx,
	float spdy,
	void (*)(Thing*),
	void (*)(Thing*));

void destroy(Thing*);


#ifndef PLAYER_H
#define PLAYER_H

#include "Thing.h"

struct Player {
	int x;
	int y;

	float xpos;
	float ypos;

	float xspd;
	float yspd;

	void (*render)(struct Thing*);
	void (*update)(struct Thing*);

	float radius;
	float angle;	// degrees
};

typedef struct Player Player;

void init(Player*, int, int, float, float, float, void (*)(Thing*));

#endif
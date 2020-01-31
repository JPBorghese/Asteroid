
#ifndef THING_H
#define THING_H

struct Thing {
	int x;
	int y;

	float xpos;
	float ypos;

	float xspd;
	float yspd;

	void (*render)(struct Thing*);
	//void (*update)(struct Thing*);
};

typedef struct Thing Thing;

void renderPlayer(struct Thing*);
//void updatePlayer(Thing*);

#endif
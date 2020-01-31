
#include <raylib.h>
#include "Thing.h"
#include "Player.h"

#define screenWidth 800;
#define screenHeight 450;

void renderPlayer(Thing* t) {
	DrawCircle(t->x, t->y, ((Player*) t)->radius, BLACK);
}


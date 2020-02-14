
#include "include.h"

// 1920 x 1080
static int windowWidth = (MONITOR_WIDTH * 3) / 4;
static int windowHeight = (MONITOR_HEIGHT * 3) / 4;

int main()
{
	srand(time(NULL));
	SetConfigFlags(FLAG_VSYNC_HINT);
	InitWindow(windowWidth, windowHeight, "asdf");
	SetWindowPosition((MONITOR_WIDTH - windowWidth) / 2, (MONITOR_HEIGHT - windowHeight) / 2);
	SetTargetFPS(60);

	Player* p = initPlayer(
		windowWidth / 2, 		// x
		windowHeight / 2, 		// y
		10,						// radius
		25,						// length
		15);					// width

	ThingArray objects;
	initThingArray(&objects);
	addThing(&objects, (Thing*)p);

	Bullet* b = initBullet(
		0,
		0,
		1,
		1,
		10);
	
	addThing(&objects, (Thing*)b);

	while (!WindowShouldClose())
	{
		if (IsKeyDown(KEY_ZERO)) {
			Enemy* e = initEnemy(
				windowWidth / 2,	// x
				windowHeight / 2,	// y
				randomVal(-8, 8),	// xspd
				randomVal(-8, 8),	// yspd
				5);					// radius

			addThing(&objects, (Thing*)e);
		}
		if (IsKeyPressed(KEY_BACKSPACE)) {
			removeThing(&objects, objects.array[0]);
		}

		BeginDrawing();
			ClearBackground(BLACK);
			for (int i = 0; i < objects.filledSpots; i++) {
				Thing* temp = (objects.array[i]);
				temp->update(temp);
				temp->render(temp);
			}
		EndDrawing();
	}
	
	deleteThingArray(&objects);
	CloseWindow();
}

Color randomColor() {
	return (Color) { rand() % 255, rand() % 255, rand() % 255, rand() % 255 };
}

float randomVal(float low, float high) {
	float r = ((float)rand()) / ((float)RAND_MAX);
	return ((high - low) * r) + low;
}

int* getWindowWidth() {
	return &windowWidth;
}

int* getWindowHeight() {
	return &windowHeight;
}


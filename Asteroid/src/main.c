
#define NULL 0
#define screenWidth 800;
#define screenHeight 450;

#include <stdio.h>
#include <raylib.h>
#include "Player.h"
#include "Thing.h"
#include "LinkedList.h"

int main() 
{
	SetConfigFlags(FLAG_VSYNC_HINT);
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);
	
	struct Player p;
	//init(*player, xpos, ypos, xspd, yspd, radius, rendFunc, updateFunc)
	init(&p, screenWidth / 2, screenHeight / 5, 4, 4, 5, renderPlayer);
	
	LinkedList* objects = createLinkedList(&p);

    while (!WindowShouldClose())
    {	
    	if (p.x + p.xspd > screenWidth || p.x < 0) 
			p.xspd *= -1;
		if (p.y + p.yspd > screenHeight || p.y < 0)
			p.yspd *= -1;
	
		p.x += p.xspd;
		p.y += p.yspd;

		BeginDrawing();
			ClearBackground(RAYWHITE);
			FOR_EACH(objects, {
				Thing* t = ((Thing*)data);
				//t->update(t); // update objects
				t->render(t); // render all objects in linked list
				});
		EndDrawing();
    }
	
    CloseWindow();

    deleteLinkedList(objects);
}





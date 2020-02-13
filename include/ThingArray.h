
#pragma once

#include "Thing.h"

struct ThingArray {
	int length;
	int filledSpots;

	Thing** array; // make an array of pointers to Thing pointers
};

typedef struct ThingArray ThingArray;

void initThingArray(ThingArray* array);
void removeThing(ThingArray* array, Thing* data);
void addThing(ThingArray* array, Thing* data);
void deleteThingArray(ThingArray* array);
void enlargeArray(ThingArray* array);




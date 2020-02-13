
#include "include.h"

void initThingArray(ThingArray* a) {
	a->length = 8;
	a->filledSpots = 0;
	a->array = (Thing**)malloc(sizeof(Thing*) * a->length);

	for (int x = 0; x < a->length; x++) {
		a->array[x] = NULL;
	}
}

void removeThing(ThingArray* a, Thing* data) {
	bool replaced = false;
	int i;

	for (i = 0; i < a->filledSpots; i++) {
		if (a->array[i] == data) {
			free(a->array[i]);
			replaced = true;
			break;
		}
	}

	if (replaced) {
		a->array[i] = a->array[a->filledSpots - 1];
		a->array[a->filledSpots - 1] = NULL;
		a->filledSpots--;
	}
	else {
		printf("removeThing failed to find \"data\" in ThingArray \n");
	}
}

void addThing(ThingArray* a, Thing* data) {
	if(a->filledSpots == a->length) {	// no open spots available
		enlargeArray(a);
	}

	int i = 0;
	while (a->array[i] != NULL) {
		i++;
		if (i >= a->length) {
			printf("addThing function index out of range of ThingArray \n");
			return;
		}
	}

	a->array[i] = data;

	a->filledSpots++;
}

void deleteThingArray(ThingArray* a) {
	for(int x = 0; x < a->filledSpots; x++) {
		free(a->array[x]);
	}
}

void enlargeArray(ThingArray* a) {
	int newLength = a->length * 2;

	Thing** newArray = (Thing**)malloc(sizeof(Thing*) * newLength);

	for (int x = 0; x < newLength; x++) {			// initilize all new pointers to NULL
		newArray[x] = NULL;
	}

	for (int i = 0; i < a->length; i++) {			// copy old array to new array
		newArray[i] = a->array[i];
	}

	free(a->array);

	a->length = newLength;
	a->array = (Thing**)newArray;
}
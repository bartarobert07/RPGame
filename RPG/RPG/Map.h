#ifndef MAP_H
#define MAP_H

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include "Hero.h"


typedef struct Map {
	char** coord;
	int sideLength;
}Map;

//Map létrehozása és beolvasása
Map* CreateAndReadMap(FILE* file);

//Hero elhelyezése a térképen
void PlaceHero(Map* map, Hero* hero);

//Térkép megjelenítése 
void PrintMap(Map* map, Hero* hero);

#endif

#ifndef HERO_H
#define HERO_H

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdbool.h>

typedef struct Hero {
	char* name;
	bool gender;
	char** body;
	int HP;
}Hero;

//Hero típus létrehozása
Hero* CreateHero();

//Hero megjelenítése
void PrintBody(Hero* hero, int x, int y);




#endif

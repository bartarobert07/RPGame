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
	char* body;
	int HP;
	int prevPosX;
	int prevPosY;
	int posX;
	int posY;
}Hero;

//Hero típus létrehozása
Hero* CreateHero();

//Jobbra mozgás
void MoveRight(Hero* hero);

//Balra mozgás
void MoveLeft(Hero* hero);

//Le mozgás
void MoveDown(Hero* hero);

//Fel mozgás
void MoveUp(Hero* hero);

#endif

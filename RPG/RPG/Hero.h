#ifndef HERO_H
#define HERO_H

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdbool.h>

typedef struct Hero {
	char* name;
	char* body;
	int bodyColor;
	int HP;
	int prevPosX;
	int prevPosY;
	int posX;
	int posY;
}Hero;

//Hero t�pus l�trehoz�sa
Hero* CreateHero();

//Jobbra mozg�s
void MoveRight(Hero* hero);

//Balra mozg�s
void MoveLeft(Hero* hero);

//Le mozg�s
void MoveDown(Hero* hero);

//Fel mozg�s
void MoveUp(Hero* hero);

//HP levon�s
void HPdrop(Hero* hero, int point);

//Hero kin�zet v�laszt�s
void HeroBodySelect(Hero* hero);

//Hero kiirat�sa
void PrintBody(Hero* hero);

#endif

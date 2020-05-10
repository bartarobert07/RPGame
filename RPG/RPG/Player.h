#ifndef PLAYER_H
#define PLAYER_H

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdbool.h>

typedef struct Player {
	char* name;
	bool gender;
	char** body;
	int HP;
}Player;

//Player t�pus l�trehoz�sa
Player* Create();

//Player megjelen�t�se
void PrintBody(Player* player);


#endif

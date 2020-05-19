#ifndef GAME_H
#define GAME_H

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include "Hero.h"
#include "Map.h"



//J�t�k kezd�k�perny�
void StartGame();

//J�t�k v�ge
void GameOver();

//Szint megnyer�se
void Win(Hero* hero);


#endif // !GAME_H


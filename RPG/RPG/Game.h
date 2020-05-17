#ifndef GAME_H
#define GAME_H

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include "Hero.h"
#include "Map.h"



//Játék kezdõképernyõ
void StartGame(Hero* hero, Map* map);

//Játék vége
void GameOver();


#endif // !GAME_H


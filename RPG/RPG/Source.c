#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include "Hero.h"
#include "Map.h"
#include <locale.h>
#if defined(WIN32) || defined(_WIN32)
#include <windows.h>
#endif

int main() {
	setlocale(LC_ALL, "");
	#if defined(WIN32) || defined(_WIN32)
	SetConsoleCP(1250); SetConsoleOutputCP(1250);
	#endif

	FILE* fin = fopen("Map.txt", "rt");
	if (!fin) {
		printf("Sikertelen fájlmegnyitás!");
		exit(1);
	}

	Hero* hero = CreateHero();
	Map* map = CreateAndReadMap(fin);
	PlaceHero(map, hero);
	PrintMap(map);
	while (1) {
		char option = getch();
		
		if (option == 'w') {
			if (hero->posX - 1 == 0 ) {
				system("CLS");
				printf("Nem szabad a falnak menni %s!",hero->name);
				Sleep(2000);
			}
			else {
				MoveUp(hero);
			}
		}

		if (option == 'a') {
			if (hero->posY - 1 == 0) {
				system("CLS");
				printf("Nem szabad a falnak menni %s!", hero->name);
				Sleep(2000);
			}
			else {
				MoveLeft(hero);
			}
		}

		if (option == 's') {
			if (hero->posX + 1 == map->sideLength - 1) {
				system("CLS");
				printf("Nem szabad a falnak menni %s!", hero->name);
				Sleep(2000);
			}
			else {
				MoveDown(hero);
			}
		}

		if (option == 'd') {
			if (hero->posY + 1 == map->sideLength - 1) {
				system("CLS");
				printf("Nem szabad a falnak menni %s!", hero->name);
				Sleep(2000);
			}
			else {
				MoveRight(hero);
			}
		}
		
		Sleep(100);
		system("CLS");
		PlaceHero(map, hero);
		PrintMap(map);
	}
}
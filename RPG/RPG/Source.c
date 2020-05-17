#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <time.h>
#include "Hero.h"
#include "Map.h"
#include "Game.h"
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
	HeroBodySelect(hero);
	system("CLS");
	PlaceHero(map, hero);
	printf("Játékos neve:%s\n", hero->name);
	printf("Játékos HP:%i\n", hero->HP);
	printf("Mozgás:WASD\n");
	PrintMap(map,hero);
	while (1) {

		char option = getch();
		
			if (option == 'w' || option == 'W') {
				if (hero->posX - 1 == 0 ) {
					if (hero->HP > 10) {
						system("CLS");
						printf("Nem szabad a falnak menni %s!\nEz 10 életpontodba kerül!\nLegközelebb legyél óvatosabb!", hero->name);
						Sleep(5000);
					}
						HPdrop(hero, 10);
				}
				else {
					MoveUp(hero);
				}
			}

			if (option == 'a' || option == 'A') {
				if (hero->posY - 1 == 0) {
					if (hero->HP > 10) {
						system("CLS");
						printf("Nem szabad a falnak menni %s!\nEz 10 életpontodba kerül!\nLegközelebb legyél óvatosabb!", hero->name);
						Sleep(5000);
					}
						HPdrop(hero, 10);
				}
				else {
					MoveLeft(hero);
				}
			}

			if (option == 's' || option == 'S') {
				if (hero->posX + 1 == map->sideLength - 1) {
					if (hero->HP > 10) {
						system("CLS");
						printf("Nem szabad a falnak menni %s!\nEz 10 életpontodba kerül!\nLegközelebb legyél óvatosabb!", hero->name);
						Sleep(5000);
					}
						HPdrop(hero, 10);
				}
				else {
					MoveDown(hero);
				}
			}

			if (option == 'd' || option == 'D') {
				if (hero->posY + 1 == map->sideLength - 1) {
					if (hero->HP > 10) {
						system("CLS");
						printf("Nem szabad a falnak menni %s!\nEz 10 életpontodba kerül!\nLegközelebb legyél óvatosabb!", hero->name);
						Sleep(5000);
					}
						HPdrop(hero, 10);
				}
				else {
					MoveRight(hero);
				}
			}

			if (hero->HP == 0) {
				GameOver();
			}


			system("CLS");
			PlaceHero(map, hero);
			printf("Játékos neve:%s\n", hero->name);
			printf("Játékos HP:%i\n", hero->HP);
			printf("Mozgás:WASD\n");
			PrintMap(map, hero);
		
	}

	return 0;
}
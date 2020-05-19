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

	FILE* fin1 = fopen("Map1.txt", "rt");
	if (!fin) {
		printf("Sikertelen fájlmegnyitás!");
		exit(1);
	}

	FILE* fin2 = fopen("Map2.txt", "rt");
	if (!fin) {
		printf("Sikertelen fájlmegnyitás!");
		exit(1);
	}

	int winCounter = 0;

	StartGame();
	Hero* hero = CreateHero();
	Map* map = CreateAndReadMap(fin);

	HeroBodySelect(hero);

restart:
	hero->posX = 1;
	hero->posY = 1;
	system("CLS");
	printf("\t\t\t\t\t      Jegyezd meg a pályát %s!\n\t\t\t\t\t         Van 10 másodperced!\n", hero->name);
	PrintMap(map, hero);
	Sleep(10000);
	system("CLS");

	PlaceHero(map, hero);
	printf("\t\t\t\t\t\t   Játékos neve:%s\n", hero->name);
	printf("\t\t\t\t\t\t   Játékos HP:%i\n", hero->HP);
	printf("\t\t\t\t\t\t    Mozgás:WASD\n");

	PrintBlankMap(map,hero);

	while (1) {

		char option = getch();
		
			if (option == 'w' || option == 'W') {
				if (map->coord[hero->posX - 1][hero->posY] == 'x' || map->coord[hero->posX - 1][hero->posY] == '+') {
					MoveUp(hero);
				}
				else if (map->coord[hero->posX - 1][hero->posY] != '0' ) {
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
				if (map->coord[hero->posX][hero->posY - 1] == 'x' || map->coord[hero->posX][hero->posY - 1] == '+') {
					MoveLeft(hero);
				}
				else if (map->coord[hero->posX][hero->posY - 1] != '0') {
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
				if (map->coord[hero->posX + 1][hero->posY] == 'x' || map->coord[hero->posX + 1][hero->posY] == '+') {
					MoveDown(hero);
				}
				else if (map->coord[hero->posX + 1][hero->posY] !='0') {
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
				if (map->coord[hero->posX][hero->posY + 1] == 'x' || map->coord[hero->posX][hero->posY + 1] == '+') {
					MoveRight(hero);
				}
				else if ( map->coord[hero->posX ][hero->posY + 1] !='0') {
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
			
			if (map->coord[hero->posX][hero->posY] == 'x') {
				winCounter++;
				if (winCounter == 1) {
					Win(hero);
					map = CreateAndReadMap(fin1);
					
					goto restart;
				}
				if (winCounter == 2) {
					Win(hero);
					map = CreateAndReadMap(fin2);
					
					goto restart;
				}
				if (winCounter == 3) {
					printf("Gratulálok %s!\n", hero->name);
					printf("Sikeresen befejezted a MemoLab játékot!\n");
					exit(1);
				
				}
			}

			if (map->coord[hero->posX][hero->posY] == '+') {
				system("CLS");
				printf("Szereztél 10 életpontot magadnak!");
				HPadd(hero,10);
				Sleep(3000);
			}

			system("CLS");
			PlaceHero(map, hero);
			printf("\t\t\t\t\t\t   Játékos neve:%s\n", hero->name);
			printf("\t\t\t\t\t\t   Játékos HP:%i\n", hero->HP);
			printf("\t\t\t\t\t\t    Mozgás:WASD\n");
			PrintBlankMap(map, hero);
		
	}

	return 0;
}
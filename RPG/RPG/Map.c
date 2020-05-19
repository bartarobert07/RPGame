#include "Map.h"
#include "Hero.h"
#include<Windows.h>

Map* CreateAndReadMap(FILE* file){

	Map* map = (Map*)(calloc(1, sizeof(Map)));
	if (!map) {
		printf("'\t\tError!\n");
		printf("Sikertelen Map típus lefoglalás!");
		exit(1);
	}

	fscanf(file, "%i", &map->XsideLength);
	fscanf(file, "%i\n", &map->YsideLength);

	map->coord = (char**)(calloc(map->XsideLength, sizeof(char*)));
	for (int i = 0; i < map->XsideLength; ++i) {
		map->coord[i] = (char*)(calloc(map->YsideLength, sizeof(char)));
	}

	if (!map->coord) {
		printf("'\t\tError!\n");
		printf("Sikertelen térkép helylefoglalás!");
		exit(1);
	}

	for (int i = 0; i < map->XsideLength; ++i) {
		for (int j = 0; j < map->YsideLength; ++j) {
			fscanf(file, "%c\n", &map->coord[i][j]);
		}
	}

	return map;
}

void PlaceHero(Map* map, Hero* hero)
{
	map->coord[hero->prevPosX][hero->prevPosY] = '0';
	map->coord[hero->posX][hero->posY] = hero->body;

}


void PrintMap(Map* map, Hero* hero) {
	for (int i = 0; i < map->XsideLength; ++i) {
		switch (map->YsideLength) {
		case 20:
			printf("\t\t\t\t\t\t");
			break;
		
		case 30:
			printf("\t\t\t\t\t   ");
			break;
		
		case 40:
			printf("\t\t\t\t\t");
			break;
		}
		
		for (int j = 0; j < map->YsideLength; ++j) {
			if (map->coord[i][j] == '0') {
				printf(" ");
			}

			else if (map->coord[i][j] == '1' && (i == 0 || i == map->XsideLength - 1)){
				printf("\033[0;31m");
				printf("-");
				printf("\033[0m");
			}

			else if (map->coord[i][j] == '1' && (i > 0 || i < map->XsideLength - 1)) {
				printf("\033[0;31m");
				printf("|");
				printf("\033[0m");
			}
			

			else if (map->coord[i][j] == '3') {
				printf("\033[0;31m");
				printf("-");
				printf("\033[0m");
			}

			else if (map->coord[i][j] == '4') {
				printf("\033[0;31m");
				printf("|");
				printf("\033[0m");
			}

			else{
				switch (hero->bodyColor) {
				case 0:
					printf("\033[0m");
					break;
				case 1:
					printf("\033[0;31m");
					break;
				case 2:
					printf("\033[1;31m");
					break;
				case 3:
					printf("\033[0;32m");
					break;
				case 4:
					printf("\033[1;32m");
					break;
				case 5:
					printf("\033[0;33m");
					break;
				case 6:
					printf("\033[1;33m");
					break;
				case 7:
					printf("\033[0;34m");
					break;
				case 8:
					printf("\033[1;34m");
					break;
				case 9:
					printf("\033[0;35m");
					break;
				case 10:
					printf("\033[1;35m");
					break;
				case 11:
					printf("\033[0;36m");
					break;
				case 12:
					printf("\033[1;36m");
					break;
				}

				printf("%c",map->coord[i][j]);
				printf("\033[0m");
			}

		}
		printf("\n");
	}
	
}

void PrintBlankMap(Map* map, Hero* hero)
{
	for (int i = 0; i < map->XsideLength; ++i) {
		switch (map->YsideLength) {
		case 20:
			printf("\t\t\t\t\t\t");
			break;

		case 30:
			printf("\t\t\t\t\t   ");
			break;

		case 40:
			printf("\t\t\t\t\t");
			break;
		}

		for (int j = 0; j < map->YsideLength; ++j) {
			if (map->coord[i][j] == '0' || map->coord[i][j] == '3' || map->coord[i][j] == '4') {
				printf(" ");
			}

			else if (map->coord[i][j] == '1' && (i == 0 || i == map->XsideLength - 1)) {
				printf("\033[0;31m");
				printf("-");
				printf("\033[0m");
			}

			else if (map->coord[i][j] == '1' && (i > 0 || i < map->XsideLength - 1)) {
				printf("\033[0;31m");
				printf("|");
				printf("\033[0m");
			}


			else {
				switch (hero->bodyColor) {
				case 0:
					printf("\033[0m");
					break;
				case 1:
					printf("\033[0;31m");
					break;
				case 2:
					printf("\033[1;31m");
					break;
				case 3:
					printf("\033[0;32m");
					break;
				case 4:
					printf("\033[1;32m");
					break;
				case 5:
					printf("\033[0;33m");
					break;
				case 6:
					printf("\033[1;33m");
					break;
				case 7:
					printf("\033[0;34m");
					break;
				case 8:
					printf("\033[1;34m");
					break;
				case 9:
					printf("\033[0;35m");
					break;
				case 10:
					printf("\033[1;35m");
					break;
				case 11:
					printf("\033[0;36m");
					break;
				case 12:
					printf("\033[1;36m");
					break;
				}

				printf("%c", map->coord[i][j]);
				printf("\033[0m");
			}

		}
		printf("\n");
	}
}


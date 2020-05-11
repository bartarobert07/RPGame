#include "Map.h"
#include "Hero.h"

Map* CreateAndReadMap(FILE* file){

	Map* map = (Map*)(calloc(1, sizeof(Map)));
	if (!map) {
		printf("'\t\tError!\n");
		printf("Sikertelen Map típus lefoglalás!");
		exit(1);
	}

	map->sideLength = 25;

	map->coord = (char**)(calloc(map->sideLength, sizeof(char*)));
	for (int i = 0; i < map->sideLength; ++i) {
		map->coord[i] = (char*)(calloc(map->sideLength, sizeof(char)));
	}

	if (!map->coord) {
		printf("'\t\tError!\n");
		printf("Sikertelen térkép helylefoglalás!");
		exit(1);
	}

	for (int i = 0; i < map->sideLength; ++i) {
		for (int j = 0; j < map->sideLength; ++j) {
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


void PrintMap(Map* map) {
	for (int i = 0; i < map->sideLength; ++i) {
		for (int j = 0; j < map->sideLength; ++j) {
			if (map->coord[i][j] == '0') {
				printf("  ");
			}

			else if (map->coord[i][j] == '1' && (i == 0 || i == map->sideLength - 1) && (j > 0 && j < map->sideLength - 1)) {
				printf("__");
			}

			else if (map->coord[i][j] == '1' && (j == map->sideLength - 1) && i > 0 && i < map->sideLength) {
				printf("|");
			}

			else if (map->coord[i][j] == '1' && (j == 0) && i > 0 && i < map->sideLength) {
				printf("|");
			}

			else if (map->coord[i][j] == '1' && ((j == 0 && i == 0) || j == map->sideLength - 1 && i == 0) ) {
				printf(" ");
			}

			else{
				printf("%c ",map->coord[i][j]);
			}

		}
		printf("\n");
	}
	
}


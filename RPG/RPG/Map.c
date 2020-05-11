#include "Map.h"
#include "Hero.h"

Map* CreateAndReadMap(FILE* file){

	Map* map = (Map*)(calloc(1, sizeof(Map)));
	if (!map) {
		printf("'\t\tError!\n");
		printf("Sikertelen Map típus lefoglalás!");
		exit(1);
	}

	map->sideLength = 10;

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
			fscanf(file, "%c\n", map->coord[i][j]);
		}
	}

	return map;
}

void PlaceHero(Map* map, Hero* hero)
{
	int x, y;
	printf("Add meg a koordinátákat!\n\tx=");
	scanf("%i", &x);
	if (x > map->sideLength - 1 || x < 0) {
		printf("Nem létezõ x koordinátát próbált megadni!");
		exit(1);
	}
	printf("\ty=");
	scanf("%i", &y);
	if (y > map->sideLength - 1 || y < 0) {
		printf("Nem létezõ y koordinátát próbált megadni!");
		exit(1);
	}
	map->coord[x][y] = hero->body[0];
}


void PrintMap(Map* map) {
	for (int i = 0; i < map->sideLength; ++i) {
		for (int j = 0; j < map->sideLength; ++j) {
			if (map->coord[i][j] == 1) {
				printf("_");
			}

			if (map->coord[i][j] == 0) {
				printf(" ");
			}

			if (map->coord[i][j] == 2) {
				printf("|");
			}
		}
		printf("\n");
	}
	
}

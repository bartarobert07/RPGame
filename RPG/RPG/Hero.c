#include "Hero.h"
#include "Map.h"
#include <string.h>

Hero* CreateHero()
{
	Hero* hero = (Hero*)(calloc(1, sizeof(Hero)));
	if (!hero) {
		printf("'\t\tError!\n");
		printf("Sikertelen Hero típus lefoglalás!");
		exit(1);
	}

	hero->name = (char*)(calloc(30, sizeof(char)));
	if (!hero->name) {
		printf("'\t\tError!\n");
		printf("Sikertelen névlefoglalás!");
		exit(1);
	}

	hero->body = (char**)(calloc(3, sizeof(char*)));
	hero->body[0] = (char*)(calloc(5, sizeof(char)));
	/*hero->body[1] = (char*)(calloc(5, sizeof(char)));
	hero->body[2] = (char*)(calloc(5, sizeof(char)));*/

	if (!hero->body) {
		printf("'\t\tError!\n");
		printf("Sikertelen kinézet lefoglalás!");
		exit(1);
	}

	hero->HP = 100;

	strcpy(hero->body[0],"o");
	/*strcpy(hero->body[1]," /|\\");
	strcpy(hero->body[2]," / \\  ");*/

	printf("Neved:");
	scanf("%s", hero->name);

	if (strlen(hero->name) > 25 || strlen(hero->name) < 1) {
		printf("Helytelen név! Maximum 25 karakter!\n");
		exit(1);
	}

	return hero;
}

void PrintBody(Hero* hero)
{
	printf("%s\n", hero->body[0]);
	printf("%s\n", hero->body[1]);
	printf("%s\n", hero->body[2]);
}

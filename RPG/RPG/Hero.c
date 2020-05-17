#include "Hero.h"
#include "Map.h"
#include <string.h>
#include<Windows.h>

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

	
	hero->body = (char*)(calloc(1, sizeof(char)));
	
	if (!hero->body) {
		printf("'\t\tError!\n");
		printf("Sikertelen kinézet lefoglalás!");
		exit(1);
	}

	hero->HP = 20;

	hero->posX = 1;
	hero->posY = 1;

	hero->bodyColor = 0;

	hero->prevPosX = 1;
	hero->prevPosY = 1;

	printf("Neved:");
	scanf("%s", hero->name);
	

	if (strlen(hero->name) > 25 || strlen(hero->name) < 1) {
		printf("Helytelen név! Maximum 25 karakter!\n");
		exit(1);
	}

cimke:
	system("CLS");
	printf("Válassz egy karaktert a billentyûzetrõl,amelyik a hõsöd lesz:");
	hero->body = getch();
	printf("%c",hero->body);
	if (hero->body == '0') {
		system("CLS");
		printf("Nem lehet a kinézeted a 0 karakter!");
		Sleep(3000);
		goto cimke;
	}
	printf("\n");

	return hero;
}


void MoveRight(Hero* hero)
{
	hero->prevPosY = hero->posY;
	hero->prevPosX = hero->posX;
	++hero->posY;
}

void MoveLeft(Hero* hero)
{
	hero->prevPosY = hero->posY;
	hero->prevPosX = hero->posX;
	--hero->posY;
}

void MoveDown(Hero* hero)
{
	hero->prevPosY = hero->posY;
	hero->prevPosX = hero->posX;
	++hero->posX;
}

void MoveUp(Hero* hero)
{
	hero->prevPosY = hero->posY;
	hero->prevPosX = hero->posX;
	--hero->posX;
}

void HPdrop(Hero* hero, int point) {
	hero->HP = hero->HP - point;
}

void HeroBodySelect(Hero* hero) {
	int counter = 0;
	bool exit = 0;
	system("CLS");
	while (exit != 1) {
		

		if (counter == 0) {
			printf("Most pedig %s, válassz egy színt is a hõsödnek:", hero->name);
			printf("%c", hero->body);
			printf("\nKövetkezõ szín: D");
			printf("\nElözõ szín: A");
			printf("\nVálaszt: E");
			counter++;
		}
		int n = getch();
		switch (n) {
		case 'd':
			if (hero->bodyColor == 12) {
				hero->bodyColor = 0;
			}
			else {
				hero->bodyColor++;
			}
			break;
		case 'a':
			if (hero->bodyColor == 0) {
				hero->bodyColor = 12;
			}
			else {
				hero->bodyColor--;
			}
			break;

		case 'e':
			exit = 1;
			system("CLS");
			printf("\033[0m");
			printf("A hõsöd:");

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
			
			printf("%c",hero->body);
			printf("\033[0m");
			Sleep(2000);
		}

		if (exit != 1) {
			system("CLS");

			printf("Most pedig %s, válassz egy színt is a hõsödnek:", hero->name);

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



			printf("%c", hero->body);
			printf("\033[0m");
			printf("\nKövetkezõ szín: D");
			printf("\nElözõ szín: A");
			printf("\nVálaszt: E");
		}
	}
}




#include "Player.h"
#include <string.h>

Player* Create()
{
	Player* player = (Player*)(calloc(1, sizeof(Player)));
	if (!player) {
		printf("'\t\tError!\n");
		printf("Sikertelen Player típus lefolgalás!");
		exit(1);
	}

	player->name = (char*)(calloc(30, sizeof(char)));
	if (!player->name) {
		printf("'\t\tError!\n");
		printf("Sikertelen névlefoglalás!");
		exit(1);
	}

	player->body = (char**)(calloc(3, sizeof(char*)));
	player->body[0] = (char*)(calloc(5, sizeof(char)));
	player->body[1] = (char*)(calloc(5, sizeof(char)));
	player->body[2] = (char*)(calloc(5, sizeof(char)));

	if (!player->body) {
		printf("'\t\tError!\n");
		printf("Sikertelen kinézet lefoglalás!");
		exit(1);
	}

	player->HP = 100;

	strcpy(player->body[0],"  o  ");
	strcpy(player->body[1]," /|\\");
	strcpy(player->body[2]," / \\  ");

	printf("Neved:");
	scanf("%s",player->name);

	if (strlen(player->name) > 25 || strlen(player->name) < 1) {
		printf("Helytelen név! Maximum 25 karakter!\n");
		exit(1);
	}

	return player;
}

void PrintBody(Player* player)
{
	printf("%s\n", player->body[0]);
	printf("%s\n", player->body[1]);
	printf("%s\n", player->body[2]);
}

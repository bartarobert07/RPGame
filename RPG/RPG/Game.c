#include "Game.h"
#include<Windows.h>


void StartGame()
{
	system("CLS");
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t __  __                              _                _\n");
	printf("\t\t\t\t|  \\/  |                            | |              | |\n");
	printf("\t\t\t\t| \\  / |   ___   _ __ ___     ___   | |        __ _  | |__\n");
	printf("\t\t\t\t| |\\/| |  / _ \\ | '_ ` _ \\   / _ \\  | |       / _` | | '_ \\\n");
	printf("\t\t\t\t| |  | | |  __/ | | | | | | | (_) | | |____  | (_| | | |_) |\n");
	printf("\t\t\t\t|_|  |_|  \\___| |_| |_| |_|  \\___/  |______|  \\__,_| |_.__ /\n");
	printf("\n\n\n\n\t\t\t\t\t\tK�sz�tette:Bartha R�bert");
	Sleep(10000);
}

void GameOver()
{
	system("CLS");
	printf("Meghalt�l...\n");
	printf("Pr�b�ld �jra!\n");
	Beep(523, 700);
	Beep(493, 700);
	Beep(466, 700);
	Beep(440, 1800);

	exit(1);
}

void Win(Hero* hero) {
	system("CLS");
	printf("Gratul�lok %s!\nSikeresen teljes�tetted ezt a szintet!\n",hero->name);
	printf("K�szen �llsz a k�vetkez� szintre?\n");
	printf("Igen: I \t Nem:N\n");
	char g = getch();
	switch (g) {
	case 'i' :
		system("CLS");
		printf("A k�vetkez� szintre ker�lsz");
		for (int i = 0; i < 4; ++i) {
			Sleep(1000);
			printf(".");
		}
		
		break;
	case 'n' :
		system("CLS");
		printf("Kil�p�s");
		for (int i = 0; i < 4; ++i) {
			Sleep(1000);
			printf(".");
		}
		printf("\n");
		exit(1);
		break;
	}
}


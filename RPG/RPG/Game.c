#include "Game.h"
#include<Windows.h>


void StartGame(Hero* hero, Map* map)
{
	

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


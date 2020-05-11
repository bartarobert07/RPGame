#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include "Hero.h"
#include "Map.h"
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
	/*int option;
	scanf("%i", &option);
	while (option != 0) {
		scanf("%i", &option);
		PlaceHero(map, hero);
	}*/
	PrintMap(map);
	

}
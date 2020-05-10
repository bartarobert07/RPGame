#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include "Player.h"
#include <locale.h>
#if defined(WIN32) || defined(_WIN32)
#include <windows.h>
#endif

int main() {
	setlocale(LC_ALL, "");
	#if defined(WIN32) || defined(_WIN32)
	SetConsoleCP(1250); SetConsoleOutputCP(1250);
	#endif

	Player* player = Create();
	PrintBody(player);

	

}
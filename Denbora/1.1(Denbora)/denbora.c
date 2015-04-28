#include<stdio.h>
#include <Windows.h>
#include <time.h>

int main(){

	//Aldagai lokalak

	time_t has_denbora, buk_denbora;
	double iraupena;
	char erantzuna;
	int minutu, segundu;


	//Algoritmia
	has_denbora = time(NULL);

	printf("Sakatu teklaren bat:\n");
	scanf("%c", &erantzuna);
	fflush(stdin);
	buk_denbora = time(NULL);

	iraupena = difftime(buk_denbora, has_denbora);

	//printf("\nIraupena: %2.0f segundo", iraupena);

	segundu = (int)iraupena;
	minutu = segundu / 60;
	segundu = segundu % 60;

	printf("Iraupena:%i minutu eta %i segundu \n", minutu, segundu);
	fflush(stdin);


	//Bukaera

	printf("\nSakatu return tekla amaitzeko...");
	fflush(stdin);
	getchar();
	return 0;
}
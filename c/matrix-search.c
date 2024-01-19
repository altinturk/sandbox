#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define TABLOSATIR 3
#define TABLOSUTUN 2

void yeniTabloGoster();

int tablo[TABLOSATIR][TABLOSUTUN];
int aranan[1][1];

int main(void)
{
	int i,j;
	yeniTabloGoster();

	printf("lutfen aranacak 1x1 matrisi girin");
	scanf("%d",aranan);

	for(i=0 ; i<TABLOSATIR ; i++)  //(tablo satir-aranan satir)
	{
		for(j=0; j<TABLOSUTUN ; j++)
		{
			if(tablo[j][i] == aranan[0][0])
			{
				printf("aranan matrisi bulduk!\n");
				printf("matrisin yeri: (%d,%d)",i+1,j+1);
				getch();
				return 0;
			}
			else
				printf(".");
		}
	}

	return 0;
}

	

void yeniTabloGoster()
{
	int i,j;
	//tablo duzenleme
	for(i=0; i<TABLOSATIR ; i++)
	{
		for(j=0; j<TABLOSUTUN; j++) //sutunlarin ilk elemanlarini dolduruyor -> satir dolduruyor
		{
			tablo[j][i] = rand()%10;
		}
	}

	//tablo gosterttirme
	printf("\n");

	for(i=0; i<TABLOSATIR ; i++)
	{
		for(j=0; j<TABLOSUTUN; j++)
		{
			printf("%3d",tablo[j][i]);
		}
		printf("\n");
	}

}
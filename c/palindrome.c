#include <stdio.h>
#include <math.h>
#include <conio.h>

int main(){
	long int orjinal, sayi, terssayi=0, sonbasamak=0;

	printf("\n\t Enter A number:");
	scanf("%ld",&sayi);

	while(1==1)	{
		orjinal = sayi;
		while(sayi>0)
		{
			sonbasamak = sayi%10;
			terssayi = terssayi*10 +sonbasamak;
			sayi= sayi/10;
		}

		if(orjinal == terssayi)
			printf("\n\tsayimiz palindrom.");
		else
			printf("\n\tsayimiz palindrom degil");

		break;
		getch();
	}
	return 0;
}

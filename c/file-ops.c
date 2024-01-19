#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <assert.h>
#include <string.h>

void Writer(void);
void Reader(void);
void Program(void);

FILE *dosyaPtr,*filePtr;
char bisey[20];


void main(void)
{
  Program();
}

void Program(void)
{
   int secim;
   do
   {
	  system("cls");
	  printf("\n1 yazar 2 okur 3 c1kar\n");
   	  scanf("%d",&secim);
	  switch (secim)
	  {
		 case 1:
			Writer();
			break;
		 case 2:
 			Reader();
			break;
	  }
   }while(secim!=3);
}

void Writer(void)
{
   dosyaPtr = fopen("mail.txt","a");
   printf("dosyaya yazmaya basla:\n");
   scanf("%s",bisey);
   fprintf(dosyaPtr,"%s\n",bisey);
   fclose(dosyaPtr);
}


void Reader(void)
{
   filePtr = fopen("mail.txt","r+"); 
   if(filePtr == NULL)
   {
	  printf("\n\a Klasorde okunacak dosya bulunamad%c",(char)141);
	  //dosya yok ki acilsin
	  getch();
   }
   else
   {
      fscanf(filePtr,"%s",bisey);
	  while(!feof(filePtr))
	  {
		 printf("\n%s",bisey);
		 fscanf(filePtr,"%s",bisey);
	  }
	  getch();
	  fclose(filePtr);
   }
}


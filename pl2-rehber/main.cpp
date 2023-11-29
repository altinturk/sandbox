 /*************************/
 /***** Alp ALTINTÜRK *****/
 /*****  1306060050   *****/
 /*************************/

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "rehber.h"
#include "rehber.cpp" //kaldirma! error verior(garip ama gercek!)
using namespace std;


Menu menu;
Kayit yeni;
Kayit kisi;

int main(void)
{
	FILE* fPtr;
	int sayac=0,sonID,menuSec;
	//easteregg();

	do{
		temizle;
		menu.anaMenu();
		menuSec = getch();

		switch (menuSec)
		{
		case '1': //kayit ekleme

			temizle;
			menu.kayitEkle();

			cout<<" Eklenecek kaydin adini giriniz:\n";
			cumleOku(kisi.ad); 
			cout<<" Soyadi girin:\n";
			cin>>kisi.soyad; 

			//id belirleme bölümü
			fPtr = fopen("isim.txt","r");
			sayac = kayitSay(fPtr);
			if(fPtr==NULL)
			{
				kisi.ID = 1;
				kisi.tail = 1;
				getch();
			}
			else
			{
				rewind(fPtr);
				fscanf(fPtr,"%s %s %d %d", yeni.ad,yeni.soyad,&yeni.ID,&yeni.tail);
				while(!feof(fPtr))
				{
					fscanf(fPtr,"%s %s %d %d \n", yeni.ad,yeni.soyad,&yeni.ID,&yeni.tail);					
				}
				sonID = (yeni.tail+1);
				kisi.tail = sonID;
				kisi.ID = sonID;
			}

			kaydiGoster(kisi);

			//dosyaya kayit yazma bölümü
			fPtr = fopen("isim.txt","a");
			add2File(fPtr,kisi);
			fclose(fPtr);
			sayac++;
			cout<<" Rehberde "<<(sayac)<<" adet kayit var.\n"; getch();/////////////////////////////////

			if(sayac>1)
				idGuncelle(sayac,sonID);

			detayGoster(kisi);

			break;


		case '2': //kayit silme

			int detayliMi;
			detayliMi = 0;

			temizle;
			menu.kayitSil();

			fPtr = fopen("isim.txt","r");
			if(fPtr == NULL)
			{
				cout<<" Henuz kayit eklemediniz!";
				getch();
				break;
			}

			cout<<" Tum kaydi mi, sadece detay mi sileceksiniz?\n"
				<<" Kayit : 1\n"
				<<" Detay : 2\n";

			detayliMi = getch();
			if(detayliMi == '1')
			{
				sayac = kayitSay(fPtr);
				fclose(fPtr);
				kayitSil(sayac);
				break;
			}
			else if(detayliMi == '2')
			{
				cout<<" Lutfen detayi silinecek idyi girin:\n ";
				cin>>detayliMi;
				cout<<" "<<detayliMi<<" nolu kaydin detayini silmek istediniz.\n";


					

				getch();
				break;
			}


		case '3': //kayit arama
		
			cout<<" Aradiginiz secenek su anda calismiyor.\n Lutfen daha sonra tekrar deneyiniz.\n";
			getch();
			break;

		case '4': //kayit goruntuleme
			int arananID;
			bool bulundu;
			bulundu = false;
			arananID = 0;

			temizle;
			menu.kayitGoruntule();

			fPtr = fopen("isim.txt","r");
			if(fPtr == NULL)
			{
				cout<<" Henuz kayit eklemediniz!";
				getch();
				break;
			}

			temizle;
			menu.kayitGoruntule();

			cout<<" Gormek istediginiz kaydin numarasini girin: \n";
			scanf("%d",&arananID);

			while(!feof(fPtr))
			{
				fscanf(fPtr,"%s %s %d %d \n", yeni.ad,yeni.soyad,&yeni.ID,&yeni.tail);
				if(yeni.ID == arananID)
				{
					bulundu = true;
					kaydiGoster(yeni);
					detayGoster(yeni);
				}
			}
			fclose(fPtr);

			if(!bulundu)
			{
				cout<<" Aranilan kayit rehberde bulunamadi.\n";
				getch();
			}
			break;


		case '5': //tum kayitlari goruntuleme
			temizle;
			menu.tumunuGoruntule();
			break;
		}
		
	}while(menuSec!='6');
	return 0;
}


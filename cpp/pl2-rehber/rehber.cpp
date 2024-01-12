/*************************/
/***** Alp ALTINTÜRK *****/
/*****  1306060050   *****/
/*************************/

#ifndef rehber_cpp
#define rehber_cpp
#include "rehber.h"
using namespace std;


class Detay
{
public:
   char tlfNo[20],il[20],ilce[20],adres[100];
   int ownerID;
};

class Kayit
{
public:
	char ad[20];
	char soyad[20];
	int ID;
	int tail; //sonuncu kaydin id.sini tutan int.
	Kayit* nextKayit; //sonraki kaydin Ptr tutacak
	Detay* ilkDetay; //eklenen detaylarin 1.sinin adresini tutcak
};


class Menu {
public:
   void anaMenu ();
   void tumunuGoruntule();
   void kayitEkle();
   void kayitSil();
   void kayitGoruntule();
};


void Menu::anaMenu(){
   cout<<"             Ana Menu       \n"
	   <<" ---------------------------------\n"
	   <<"   1. Kayit Ekle\n"
	   <<"   2. Kayit Sil\n"
	   <<"   3. Kayit Ara\n"
	   <<"   4. Kayit Goruntule\n"
	   <<"   5. Butun Kayitlari Goruntule\n"
	   <<"   6. Exit\n"
	   <<" ---------------------------------\n";
}

void Menu::kayitEkle(){
	cout<<"          Kayit Ekleme \n"
		<<" ---------------------------------\n";
}

void Menu::kayitSil(){
	cout<<"          Kayit Sil \n"
		<<" ---------------------------------\n";
}

void Menu::kayitGoruntule(){
	cout<<"          Kayit Goruntule \n"
		<<" ---------------------------------\n";
}

void add2File(FILE *ptr,Kayit rec)
{
	fprintf(ptr,"%s %s %d %d\n",rec.ad,rec.soyad,rec.ID,rec.tail);
}


void kaydiGoster(Kayit rec)
{
	cout<<"\n Secilen Kayit.....:"
		<<"\n Ad      : "<<rec.ad
		<<"\n Soyad   : "<<rec.soyad
		<<"\n ID      : "<<rec.ID
		<<"\n (Son ID : "<<rec.tail<<")"
		<<"\n";
}


int kayitSay(FILE *fPtr)
{
	int count=0;
	char ot[50];
	int at=0;

	if(fPtr==NULL)
		return 0;
	else
	{
		while(!feof(fPtr))
		{
			fscanf(fPtr,"%s %s %d %d \n",ot,ot,&at,&at);
			++count;
		}
		return (count);
	}
//	rewind(file); //calismiyo nedense
}

void cumleOku (char* cumle)
{
	char c;
	int i = 0;

	while((c = getchar())!='\n')
	{
		if(c==' ')
			c='_';
		cumle[i++] = c;
	}
	cumle[i] = '\0';
}

void idGuncelle(int sayac,int sonID)
{
	Kayit yeni;
	FILE* fPtr;
	int u=0;

	fPtr = fopen("isim.txt","r");
	Kayit* nPtr = new Kayit[sayac]();

	while(!feof(fPtr) && u<sayac)
	{
		fscanf(fPtr,"%s %s %d %d", yeni.ad, yeni.soyad, &yeni.ID, &yeni.tail);
		nPtr[u] = yeni;
		nPtr[u].tail = sonID;
		u++;
	}

	fclose(fPtr);

	fPtr = fopen("isim.txt","w");

	for(u=0;u<sayac;u++)
	{
		add2File(fPtr,nPtr[u]);
	}

	fclose(fPtr);

	delete(nPtr);
}

void detayEkle(Kayit kisi)
{
	FILE* fPtr;
	Detay info;

	info.ownerID = kisi.ID;

	cout<<" "<<kisi.ID<<" nolu kayit icin telefon numarasi girin:";
	cin>>info.tlfNo;
	cout<<"il yazin:";
	cin>>info.il;
	cout<<"ilce yazin:";
	cin>>info.ilce;
	cout<<"adresi girin:";
	cin>>info.adres;

	fPtr = fopen("detay.txt","a");
	fprintf(fPtr,"%d %s %s %s %s \n ", info.ownerID, info.tlfNo, info.il, info.ilce, info.adres);
	fclose(fPtr);
	cout<<"\n Bilgiler Kaydedildi..";
	getch();
}


void kayitSil(int sayac)
{
	FILE* fPtr;
	FILE* dPtr;
	Kayit yeni;
	int silID,counter=0,counterFinal=0;

	cout<<" Lutfen silinecek kaydin numarasini girin:";
	cin>>silID;
	fPtr = fopen("isim.txt","r");
	Kayit* kPtr = new Kayit[sayac]();

	while(!feof(fPtr) && counter<sayac)
	{
		fscanf(fPtr,"%s %s %d %d \n", yeni.ad, yeni.soyad, &yeni.ID, &yeni.tail);
		if(yeni.ID == silID) continue;
		kPtr[counter] = yeni;
		counter++;
		counterFinal++;
	}
	fclose(fPtr);
	
	fPtr = fopen("isim.txt","w");

	for(counter=0;counter<counterFinal;counter++)
	{
		add2File(fPtr,kPtr[counter]);
	}

	fclose(fPtr);
	delete(kPtr);

	do{
		dPtr = fopen("detay.txt","r");
		if(dPtr==NULL)
		{
			cout<<" Bu kayit icin detay eklenmemis.";
			break;
		}
		
		detaySil(yeni);
		fclose(dPtr);
	}while(false);



	cout<<" Kayit silindi.";
	getch();
	
}

void detayGoster(Kayit yeniObj)
{
	FILE* dPtr;
	Detay info;
	char secim;
	bool detailFound = false;

	dPtr = fopen("detay.txt","r");
	if(dPtr != NULL)
	{
	while(!feof(dPtr))
	{
		fscanf(dPtr,"%d %s %s %s %s \n ", &info.ownerID, info.tlfNo, info.il, info.ilce, info.adres);
		if(info.ownerID == yeniObj.ID)
		{
			cout<<" -----------------------------------\n"
				<<" Telefon : "<<info.tlfNo <<"\n"
				<<" Il      : "<<info.il <<"\n"
				<<" Ilce    : "<<info.ilce <<"\n"
				<<" Adres   : "<<info.adres <<"\n";
			//printf(" Telefon: %s\n il: %s\n ilce: %s\n Adres: %s \n ", info.tlfNo, info.il, info.ilce, info.adres);
			detailFound = true;
		}
	}
	getch();
	}
		cout<<" Bu kayit icin detay eklemek ister misiniz?(e/h)";
		cin>>secim;
		if(secim=='e' || secim == 'E')
		detayEkle(yeniObj);
	
}

int detaySay(FILE* fPtr)
{
	Detay dummy;
	int count = 0;

	if(fPtr==NULL)
	{
		cout<<" Detay eklenmemis.";
		return 0;
	}
	else
	{
		while(!feof(fPtr))
		{
			fscanf(fPtr,"%d %s %s %s %s \n ", &dummy.ownerID, dummy.tlfNo, dummy.il, dummy.ilce, dummy.adres);
			count++;
		}
	}
	return count;
	
}



void detaySil(Kayit rec)
{
	// !! This function works UNSTABLE !!
	//Only erases non-detailed records
	//if possible, try not to erase any detailed ones.

	FILE* dPtr;
	Detay dummy;
	int sayac = 0, index = 0;


	dPtr = fopen("detay.txt","r");
	sayac = detaySay(dPtr);

	Detay* detArr = new Detay[sayac]();
	while(!feof(dPtr) && index<sayac)
	{
		//first, pick which record you want to erase.
		//when it's found, make it jump over and get another line of data.
		//because of that, u will only have lines of useful data on memory.

		fscanf(dPtr,"%d %s %s %s %s \n", &dummy.ownerID, dummy.tlfNo, dummy.il, dummy.ilce, dummy.adres);
		if(dummy.ownerID==rec.ID)
		{
			continue;
		}
		else
		{
			detArr[index] = dummy;
			index++;
		}
	}
	fclose(dPtr);

	//dosya overwrite islemi baslangici

	dPtr = fopen("detay.txt","w");
	for(index=0;index<sayac;index++)
	{
		fprintf(dPtr,"%d %s %s %s %s\n", detArr[index].ownerID, detArr[index].tlfNo, detArr[index].il, detArr[index].ilce, detArr[index].adres);
	}
	fclose(dPtr);

}




////////////////////////////////////////////////////////////////////////
//BUTUN KAYITLARI GORUNTULEME///////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
void Menu::tumunuGoruntule(){
	Kayit yeni;
	FILE* Ptr;
	Ptr = fopen("isim.txt","r");
	int sayac = kayitSay(Ptr);

	cout<<"       Rehber Goruntuleme       \n"
		<<" ---------------------------------\n";

	if(sayac!=0)
	{
		cout<<" Toplam "<<sayac<<" kayit goruntuleniyor:\n";
		rewind(Ptr);
		fscanf(Ptr,"%s %s %d %d",yeni.ad,yeni.soyad,&yeni.ID,&yeni.tail);
		while(!feof(Ptr))
		{
			printf(" %2d| %s %s\n",yeni.ID,yeni.ad,yeni.soyad);
			fscanf(Ptr,"%s %s %d %d",yeni.ad,yeni.soyad,&yeni.ID,&yeni.tail);
		}
		fclose(Ptr);
	}
	else
		cout<<" Defterde kisi kaydi yoktur.\n";

	cout<<" ---------------------------------\n";
	getch();

}

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

void easteregg(void)
{
	int i;
	for (i=0;i<12;i++)
	{
		Sleep(200);
		temizle;
		if(i%2==1)
			cout<<"\n"
				<<"\t:::'###::::'##:::::::'########::\n"
				<<"\t::'## ##::: ##::::::: ##.... ##:\n"
				<<"\t:'##:. ##:: ##::::::: ##:::: ##:\n"
				<<"\t'##:::. ##: ##::::::: ########::\n"
				<<"\t #########: ##::::::: ##.....:::\n"
				<<"\t ##.... ##: ##::::::: ##::::::::\n"
				<<"\t ##:::: ##: ########: ##::::::::\n"
				<<"\t..:::::..::........::..:::::::::\n";
		else
			cout<<"\n"
				<<"\t    ###     ##        ########  \n"
				<<"\t   ## ##    ##        ##     ## \n"
				<<"\t  ##   ##   ##        ##     ## \n"
				<<"\t ##     ##  ##        ########  \n"
				<<"\t #########  ##        ##        \n"
				<<"\t ##     ##  ##        ##        \n"
				<<"\t ##     ##  ########  ##        \n";
			
	}
	Sleep(3000);
	temizle;
	cout<<"\n\n\n\t Has mixed that piece of code. ";
	Sleep(4000);
	temizle;

}

#endif



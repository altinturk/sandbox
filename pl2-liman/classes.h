#ifndef CLASSES_H
#define CLASSES_H
#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;

static int GemiID = 1;

class Liman
{
public:

	int gemiTip;
	int peronID;
	int siraNo;
	int gemiNo;
	int gemiYuk;
	Liman(){
		gemiTip = 0;
		peronID = 0;
		siraNo = 0;
		gemiNo = 0;
		gemiYuk = 0;
	}

	void gemiYarat(){
		cout<<"Gemi tipini girin: Taka->1 Vapur->2 KuruYuk->3\n"<<endl;
		cin>> gemiTip;
		gemiNo = GemiID;
		GemiID++;

		if(gemiTip == 1)
			gemiYuk = 1;
		else if(gemiTip == 2)
			gemiYuk = 5;
		else
			gemiYuk = 7;
	}

	void menuGoster(){
			
	cout<<" LimanSim v0.1 \n"
		<<"_____________________\n"
		<<" 1. Yeni Gemi Yarat\n"
		<<" 2. Islem Gerceklestir\n"
		<<" 3. Bilgileri Goster\n"
		<<" 4. Islemi biten gemileri goster\n"
		<<" 5. Cikis\n"
		<<"_____________________\n"
		<<"Lutfen yapilacak islemi secin:"<<endl;
	}

};

class Gemi
{
public:
	bool isBitti;
	int gemiID;
	int ustundeki_yuk; // taka1 vapur5 kuruYük7
	int tip; // 1taka 2vapur 3kuruYük
	int peronNo;
	int siraNo;
	Gemi(){
		isBitti = false;
		siraNo = 0;
		peronNo = 0;
		tip = 0;
		ustundeki_yuk = 0;
		gemiID = 0;
	}
};

class Peron
{
public:
	Peron();
	int peronID;
	int gemiSayisi; //kaç tane gemi var göstercek
	int ilkGemiID; //iþlenen geminin sýrasýne vercek
	void bitenleriGoster();
	int bitenTaka;
	int bitenVapur;
	int bitenKuruYuk;
	void bilgiGoster();
private:
	int secim;
};

Peron::Peron(){
	peronID = 0;
	ilkGemiID = 0;
	gemiSayisi = 0;
	bitenTaka =0;
	bitenVapur = 0;
	bitenKuruYuk = 0;
}

void Peron::bilgiGoster(){
	cout<< peronID <<". Peronun Bilgileri:\n";
	cout<< "Siradaki toplam gemi #: "<< gemiSayisi;
	if(gemiSayisi!=0)
	{
	cout<< "\nSu anki gemi: "<< ilkGemiID <<" liman giris numarali";
	if(ilkGemiID == 1)
		cout<<" Taka\n";
	else if(ilkGemiID == 2)
		cout<<" Vapur\n";
	else if(ilkGemiID == 3)
		cout<<" Kutu Yuk Gemisi\n";
	}//gemi varsa bitis
	else
		cout<<"\nGemi bulunmamaktadir"<<endl;

	cout<< "Biten islemleri gostermek istiyorsaniz 1 e basin:\n"<<endl;
	cin>>secim;
	if(secim==1)
		bitenleriGoster();
}


void Peron::bitenleriGoster(){
	cout<<"------Peron "<< peronID <<" icin\n";
	cout<<"Biten Taka:"<< bitenTaka <<"\nBiten Vapur:" << bitenVapur <<"\nBiten Kuru Yuk Gemisi: "<< bitenKuruYuk <<endl;

}

#endif
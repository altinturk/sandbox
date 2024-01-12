#include "classes.h"

void main(void)
{
	Liman liman;
	
	Peron peron1;
	Peron peron2;
	Peron peron3;
	Gemi yeni;
	Gemi *liste = new Gemi[1000]();

	peron1.peronID = 1;
	peron2.peronID = 2;
	peron3.peronID = 3;
	int sayac=0;

	while (1){
		system("cls");
		liman.menuGoster();
		int secim;
		cin>>secim;
	
		switch (secim){

//gemiekle
		case 1:
			liman.gemiYarat();
			//Gemi yeni;
			yeni.gemiID = liman.gemiNo;
			yeni.tip = liman.gemiTip;
			yeni.ustundeki_yuk = liman.gemiYuk;

			//perona yönlendirme
			if(peron1.gemiSayisi == 0 || peron1.gemiSayisi<=peron2.gemiSayisi || peron1.gemiSayisi<=peron3.gemiSayisi )
				yeni.peronNo = 1;
			else if(peron2.gemiSayisi == 0 || peron2.gemiSayisi<=peron3.gemiSayisi )
				yeni.peronNo = 2;
			else 
				yeni.peronNo = 3;

			if (yeni.peronNo == 1)
			{
				peron1.gemiSayisi +=1;
				yeni.siraNo = peron1.gemiSayisi;
				if(peron1.ilkGemiID == 0)
					peron1.ilkGemiID = yeni.gemiID;
			}
			else if (yeni.peronNo == 2)
			{
				peron2.gemiSayisi +=1;
				yeni.siraNo = peron2.gemiSayisi;
				if(peron2.ilkGemiID == 0)
					peron2.ilkGemiID = yeni.gemiID;
			}
			else 
			{
				peron3.gemiSayisi +=1;
				yeni.siraNo = peron3.gemiSayisi;
				if(peron3.ilkGemiID == 0)
					peron3.ilkGemiID = yeni.gemiID;
			}
	

			cout<<"Yaratilan Gemi:\n";
			if(yeni.tip==1)
				cout<<"Tipi: Taka\n"<<"Uzerindeki Yuk: 1 birim\n";
			else if(yeni.tip == 2)
				cout<<"Tipi: Vapur\n"<<"Uzerindeki Yuk: 5 birim\n";
			else
				cout<<"Tipi: Kuru Yuk Gemisi\n"<<"Uzerindeki Yuk: 1 birim\n";

			
			cout<<"Geminin ID'si: "<<yeni.gemiID
				<<"\nGirdigi Peron: "<<yeni.peronNo
				<<"\nPeron Sira No: "<<yeni.siraNo <<endl;
			

			liste[sayac] = yeni;
			sayac++;
		
			getch();
			break;

//zaman gecir
		case 2:
			if(peron1.gemiSayisi == 0 && peron2.gemiSayisi == 0 && peron3.gemiSayisi == 0)
				cout<<"Limanda Gemi Yok. Uyuyarak vakit geciriyorsun bee :) "<<endl;
			else
			{
				cout<<"the time has passed\n";
				for(int i= 0; i<sayac; i++)
				{
					liste[i].ustundeki_yuk -=1;
					if(liste[i].ustundeki_yuk == 0)
					{
						liste[i].isBitti = true;
						liste[i].siraNo = 0;
						if(peron1.peronID == liste[i].peronNo)
							peron1.gemiSayisi--;
						else if(peron2.peronID == liste[i].peronNo)
							peron2.gemiSayisi--;
						else if(peron3.peronID == liste[i].peronNo)
							peron3.gemiSayisi--;
						else
							cout<<"acaip bi durum"<<endl;
					} //yuk bittiyse gemi cikartir

				} //for- tüm gemileri inceleme bitis

			} //if gemi var bitis

			getch();
			break;
	
//bilgiler
		case 3:
			cout<<"Bilgiler:\n"<<endl;
			peron1.bilgiGoster();
			peron2.bilgiGoster();
			peron3.bilgiGoster();
			getch();
			break;

//bitenler
		case 4:
			peron1.bitenleriGoster();
			peron2.bitenleriGoster();
			peron3.bitenleriGoster();
			getch();
			break;
			
//cikis
		case 5:
			exit(0);

		} //switch bitis

	} //while 1 bitis

} //main bitis

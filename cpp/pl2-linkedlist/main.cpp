#include "liman.h"

void main(void)
{
	menu Menu;
	Menu.Main();
	scanf("%d",&secim);

	switch(secim){
	case '1':
		cout<<"Yeni Gemi Yaratma secenei"<<endl;
		break;
	case '2':
		cout<<"zaman gecir";
		break;
	case '3':
		cout<<"Bilgi Listele";
		break;
	case '4':
		cout<<"Islemi Biten Gemileri goster";
		break;

}
/*************************/
/***** Alp ALTINTÜRK *****/
/*****  1306060050   *****/
/*************************/

#ifndef rehber_h
#define rehber_h

#define temizle system("cls");

class Kayit; //Kisi kaydi icin temel class. Kisi ad-soyad bilgileri bununla tutulur.
class Detay; //Kisi icin detay classi. telefon,adres bilgileri bununla tutulur.
class Menu; //Menu goruntulemek icin class. Islem yapmaz, sadece ekrana menu bastirir.

int kayitSay(FILE *file); //gonderilen Kayit dosyasi pointeriyla dosyada kac adet kayit oldugunu dondurur.
void kaydiGoster(Kayit record); //record nesnesini kullanarak o nesneye ait temel bilgileri gosterir.
void kayitSil(int sayac); //kayit sayisi bilgisini ister, icindeki menulerle istenen kaydi dosyadan siler.
void add2File(FILE *ptr,Kayit record); //record nesnesinin bilgilerini fPtr ile gosterilen dosyaya kaydeder.
void detayEkle(Kayit kisi); //kisi nesnesine adres/telefon bilgileri ekler.
void detayGoster(Kayit yeniKayit); //yeniKayit nesnesini kullanarak uygun adres/telefon bilgilerini -varsa- goruntuler.
									//kayit bilgileri yoksa ekler.
void idGuncelle(int sayac,int sonID); //yazilan dosyada butun kayitlardaki son eklenen kayit numarasini gunceller.
void cumleOku(char *cumle); //cumle dizisine istenilen sekilde -bosluk olmadan- yazmaya yarar.
void detaySil(Kayit rec); //kaydin detaylarini siler.
#endif
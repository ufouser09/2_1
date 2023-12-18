/*
kullanýcagýnýz veri tipleri kadar bosluða ihtiycanýz yoksa bit field kullanabilirsiniz
bit fieldlarla adres alamýyosun register specific adres alamýyosun bit field array olusturamýyosun
meela int 4 byte ama 4 byte ýhtýyacýnýz yok
sadece pozitif=unsigned kullanýrýz mesela

struct date{
	unsigned int day;//boyle yapabilirsin mesela
	unsigned int month;
	unsigned int year;//bunlarýn dizilerini olusturamýyorsun
};
içindeki tum memberlarýn hafýzada kaldýgý alan ayný demek
mesela turkse tc numarasý degilse pasaport numarasý alan bir olay
herkes tc numarasýna sahp olmayabilir herkes pasaport numarasýna sahip olmayabilir.

*/

typedef union std{
	unsigned int ID;
	unsigned char c1;
	unsigned char c2;
}STD;
int main(){
	STD s;
	s.c1='A';
	s.c2='b';
	printf("%c %c %d",s.c1,s.c2,s.ID);
	printf("%p %p %p",s.c1,s.c2,s.ID);
	s.ID=100;
	
	return 0;
}













































































































































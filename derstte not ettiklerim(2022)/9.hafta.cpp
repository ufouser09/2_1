/*
kullan�cag�n�z veri tipleri kadar boslu�a ihtiycan�z yoksa bit field kullanabilirsiniz
bit fieldlarla adres alam�yosun register specific adres alam�yosun bit field array olusturam�yosun
meela int 4 byte ama 4 byte �ht�yac�n�z yok
sadece pozitif=unsigned kullan�r�z mesela

struct date{
	unsigned int day;//boyle yapabilirsin mesela
	unsigned int month;
	unsigned int year;//bunlar�n dizilerini olusturam�yorsun
};
i�indeki tum memberlar�n haf�zada kald�g� alan ayn� demek
mesela turkse tc numaras� degilse pasaport numaras� alan bir olay
herkes tc numaras�na sahp olmayabilir herkes pasaport numaras�na sahip olmayabilir.

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













































































































































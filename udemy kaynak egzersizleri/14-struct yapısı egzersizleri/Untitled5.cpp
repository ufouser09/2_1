#include <stdio.h>
#include <stdlib.h>
//struct AdresDefteri diye bir struct olustururuz
struct AdresDefteri{
char Ad[100];
char Soyad[100];
char TelNo[10];
char Adres[200];
char PostaKodu[6];

};
//structlar tanýmlandýktan sonra 
int main()
{
    /*Adres defteri adýnda bir yapý tanýmlayýnýz.Tutulacak bilgiler ad,soyad,tel,adres,posta kodu þeklindedir.
    Buna göre N adet kiþinin bilgisini bir yapýda tutan C programýný yazýnýz.*/
    //N diye bir degisken tanýmlarýz
	int N;
	//i diye bir degisken tanýmlarýz
    int i;
    //satir diye bir degisken tanýmlarýz
    char satir;
    //kac adet kayit tutulacýný kullanýcýdan alýr ve onu da N degiskenine aktarýrýz
    printf("Kac adet kayit tutulacak\n");
    scanf("%d",&N);
    scanf("%c",&satir);
	//struct adres defterine iletisim[N] ismini veririz
    struct AdresDefteri iletisim[N];

    for(i=0;i<N;i++)
    {
		//kullanýcýdan iletisim[i].Ad ile adý alýrýz
        printf("Adi giriniz\n");
        gets(iletisim[i].Ad);
		//kullanýcdan iletisim[i].Soyad ile soyad alýrýz
        printf("Soyadi giriniz\n");
        gets(iletisim[i].Soyad);
		//kullanýcýdan iletisim[i].TelNo ile tel no alýrýz
        printf("Telno giriniz\n");
        gets(iletisim[i].TelNo);
		//kullanýcýdan iletisim[i].Adres ile adres alýrýz
        printf("Adres giriniz\n");
        gets(iletisim[i].Adres);
		//kullanýcýdan iletisim[i].PostaKodu ile posta kodunu alýrýz
        printf("Postakodu giriniz\n");
        gets(iletisim[i].PostaKodu);


    }

    printf("ADI\tSOYADI\tTELEFON\tADRES\t\POSTAKODU\n");
    printf("=============================================\n");
	//kullanýcýdan aldýklarýmýzý ekrana yazdýrýrýz
    for(i=0;i<N;i++)
    {
        printf("%s \t %s \t %s \t %s \t %s\n",iletisim[i].Ad,iletisim[i].Soyad,iletisim[i].TelNo,iletisim[i].PostaKodu,iletisim[i].Adres);
    }

    return 0;
}
/*
output:
Kac adet kayit tutulacak
2
Adi giriniz
e
Soyadi giriniz
f
Telno giriniz
g
Adres giriniz
3
Postakodu giriniz
4
Adi giriniz
r
Soyadi giriniz
e
Telno giriniz
e
Adres giriniz
a
Postakodu giriniz
s
ADI     SOYADI  TELEFON ADRES   POSTAKODU
=============================================
e        f       g       4       3
r        e       e       s       a
*/






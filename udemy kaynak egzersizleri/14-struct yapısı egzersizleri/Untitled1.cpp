#include <stdio.h>
#include <stdlib.h>

//bir struct yarismaciTip diye bir struct olustururuz
struct yarismaciTip{

char isim[10],soyad[10];
float puan[10],performans;

};

float puanHesap(struct yarismaciTip pat)
{
    int i;
    //sonuc degiskenimizi tanýmlarýz
    float sonuc=0;
    float max=0.0;
    float min=6.0;
    for(i=0;i<10;i++)
    {
    	//burda hakemlerin vermis oldugu max puaný buluruz
        if(pat.puan[i]>max)
        {
            max=pat.puan[i];
        }
        //burda hakemlerin vermis oldugu min puaný buluruz
        if(pat.puan[i]<min)
        {
            min=pat.puan[i];
        }
		//tüm puanlarý burda toplarýz
        sonuc +=pat.puan[i];
    }
    
	//sonuc degiskenimizden max ve min puaný cýkartýrýz onu da kalan 8 hakeme bolup ortalamayý buluruz
    sonuc=(sonuc-max-min)/8;
    return(sonuc);
}



int main()
{
    /*Bir buz pateni karsýlasmasýnda,bir yarýsmacýnýn performansý 6.00 üzeinden puanlanarak 10 hakem tarafýndan
    degerlendirilmektedir.yarýsmacýnýn performans puaný ise hakemlerin vermiþ oldugu en düþük ve en yüksek puan
    atýlýp,geri kalan puanlarýn aritmetik ortlamasý alýnarak bulunmaktadÄ±r.Yazacagýnýz programda yarýsmacýnýn
    adý,soyadý performans puaný hesaplayýp ekranda görüntüleyiniz.Performans hesaplamasýnda tek parametreli
    bir fonksiyonda yapýnýz.Bu fonksiyon yarýsmacýya ait yappýlý parametre olarak almalý ve performans puanlarýný
    hesaplayarak geri döndürülmelidir.*/
    
	//i diye bir degisken tanýmlarýz
	int i;
	//struct yarismacýTip structýna patenci ismini verirsin
    struct yarismaciTip patenci;
	
	//&patenci.isim diyerek patencinin ismini alýrsýn
    printf("Yarismacinin adi\n");
    scanf("%s",&patenci.isim);
	//&patenci.soyad diyerek patencinin soyadýný alýrsýn
    printf("Soyadi\n");
    scanf("%s",&patenci.soyad);

	//ekrana hakem puaný yazdýrýlýr
    printf("Hakem puani\n");
	
    for(i=0;i<10;i++)
    {
    	//patenci.puan[i] ile kullanýcýdan sýrasýyla 10 hakemin verdigi puanlarý alýnýr
        scanf("%f",&patenci.puan[i]);
    }
	//puan hesap fonksiyonuna gidilir orda puan hesaplanýr bu da patenci.performans degerini olustururuz.
    patenci.performans=puanHesap(patenci);
	
    printf("Performans puani = %f",patenci.performans);
    return 0;
}
/*
output:
Yarismacinin adi
efe
Soyadi
f
Hakem puani
3
4
5
6
7
3
2
1
2
3
Performans puani = 3.500000
*/

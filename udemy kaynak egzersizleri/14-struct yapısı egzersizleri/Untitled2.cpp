#include <stdio.h>
#include <stdlib.h>

struct yarismaciTip{

char isim[10],soyad[10];
float puan[10],performans;

};

float puanHesap(struct yarismaciTip pat)
{
    int i;
    float sonuc=0;
    float max=0.0;
    float min=6.0;
    for(i=0;i<10;i++)
    {
        if(pat.puan[i]>max)
        {
            max=pat.puan[i];
        }
        if(pat.puan[i]<min)
        {
            min=pat.puan[i];
        }

        sonuc +=pat.puan[i];
    }

    sonuc=(sonuc-max-min)/8;
    return(sonuc);
}




int main()
{
   /* StructYeniEgzersiz2 yi tekrar yazınız.Bu programda ilk önce yarışmaya katılan yarışmacı sayısını n,
    yarışmacıların adı,soyadı ve hakemlerin değerlendirme puanlarını tanımlayacağınız bir yapı
    dizisine giriniz.Daha sonra her yarışmacının performans puanını yukarıda yazılmış fonksiyonu
    kullanarak hesaplayınız.Son olarak yapı dizisini taratarak birinci gelen yarışmacıyı bulunuz.

    */
    struct yarismaciTip patenci[100];
    int n,birinci;
    int i,j;
    char satir;
    float max=0.0;
    printf("Lutfen yarismaci sayisini giriniz\n");
    scanf("%d",&n);
    scanf("%c",&satir);

    for(j=0;j<n;j++)
    {
        printf("Lutfen yarismacinin adini giriniz\n");
        gets(patenci[j].isim);

        printf("Lutfen yarismacinin soyadini giriniz\n");
        gets(patenci[j].soyad);

        printf("Hakem puani\n");

        for(i=0;i<10;i++)
        {
            scanf("%f",&patenci[j].puan[i]);
        }
         scanf("%c",&satir);
        patenci[j].performans=puanHesap(patenci[j]);

        printf("Puan = %f",patenci[j].performans);

        if(patenci[j].performans>max)
        {
            max=patenci[j].performans;
            birinci=j;
        }


    }
    printf("Yarismanin birincisi:\n");
    printf("Isim:%s Soyisim:%s Puan:%f\n",patenci[birinci].isim,patenci[birinci].soyad,max);





    return 0;
}
/*
output:
Lutfen yarismaci sayisini giriniz
2
Lutfen yarismacinin adini giriniz
e
Lutfen yarismacinin soyadini giriniz
f
Hakem puani
3
2
1
4
5
6
7
8
9
2
Puan = 4.625000Lutfen yarismacinin adini giriniz
f
Lutfen yarismacinin soyadini giriniz
r
Hakem puani
3
4
5
6
2
1
4
5
6
7
Puan = 4.375000Yarismanin birincisi:
Isim:e Soyisim:f Puan:4.625000
*/

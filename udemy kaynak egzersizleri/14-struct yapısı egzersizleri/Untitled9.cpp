#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ogrenci{
    char ad[10];
    char soyad[20];
    int no;
    int sinif;
    };


int main()
{
    /*Aşağıdaki verilen yapıyı kullanarak öğrenci numarası 2019 olduğunda aşağıda verilen
    bilgilerin tutulmasını ve ekrana gösterilmesini sağlayan C programını yazınız.

    Bilgi
    Ad=Can
    Soyad=Boz
    No:2019
    Sınıf=5

    Yapı:*/

      struct ogrenci ogr;
      printf("Lutfen ogrenci numarasini giriniz\n");
      scanf("%d",&ogr.no);

      if(ogr.no==2019)
      {
          ogr.no=2019;
          strcpy(ogr.ad,"Can");
          strcpy(ogr.soyad,"Boz");
          ogr.sinif=5;

          printf("\n No :%d ",ogr.no);
          printf("\n Adi: %s ",ogr.ad);
          printf("\n Soyad: %s ",ogr.soyad);
          printf("\n Sinifi: %d ",ogr.sinif);


      }


    return 0;
}
/*
output:
Lutfen ogrenci numarasini giriniz
2019

 No :2019
 Adi: Can
 Soyad: Boz
 Sinifi: 5
 */

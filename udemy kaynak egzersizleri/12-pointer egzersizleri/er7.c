#include <stdio.h>
#include <stdlib.h>

int main()
{
	//can ve canan diye 2 dizi olustururuz
    int can[100],canan[100];
    //*sayi1 ve *sayi2 diye 2 degisken tanýmlarýz
    int *sayi1,*sayi2;
    //n ve m diye 2 degisken tanýmlarýz
    int n,m;
    //i diye bir degisken tanýmlarýz
    int i;
	//eleman sayisini giriniz
    printf("Ilk dizimizin eleman sayisi (max 50) : \n");
    scanf("%d",&n);
    
    for(sayi1=can;sayi1<can+n;sayi1++)
    {
        printf("Eleman %d : ",sayi1-can);
        scanf("%d",sayi1);
    }
    printf("Ikinci dizimin eleman sayisi : \n");
    scanf("%d",&m);
    for(sayi2=canan;sayi2<canan+m;sayi2++)
    {
        printf("Eleman %d :",sayi2-canan);
        scanf("%d",sayi2);
    }

    printf("Ilk dizimiz : \n");

    for(i=0;i<n;i++)
    {

        printf("%4d",*(can+i));
    }

    printf("\nIkinci tablomuz : \n");
    for(i=0;i<m;i++)
    {
        printf("%4d",*(canan+i));
    }

    for(sayi1=can+n,sayi2=canan;sayi2<canan+m;sayi1++,sayi2++)
    {
        *sayi1=*sayi2;
    }
    printf("\n");

    printf("Birlestirmeden sonra : \n");
    for(i=0;i<n+m;i++)
    {
        printf("%4d",*(can+i));
    }


    return 0;
}
/*
output:
Ilk dizimizin eleman sayisi (max 50) :
5
Eleman 0 : 1
Eleman 1 : 5
Eleman 2 : 3
Eleman 3 : 8
Eleman 4 : 5
Ikinci dizimin eleman sayisi :
2
Eleman 0 :8
Eleman 1 :6
Ilk dizimiz :
   1   5   3   8   5
Ikinci tablomuz :
   8   6
Birlestirmeden sonra :
   1   5   3   8   5   8   6
   */

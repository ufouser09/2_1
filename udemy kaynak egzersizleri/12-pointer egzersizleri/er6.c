#include <stdio.h>
#include <stdlib.h>
#define MAX 15

int main()
{
	//dizi diye bir degisken olustururuz
    char dizi[MAX]={'k','l','b','d','q','i','s','t','e','f','o','r','c','h','x'};
    //*sayi1 degiskeni tanýmlarýz
    char *sayi1;
    //*sayi2 degiskeni tanýmlarýz
    char *sayi2;
    //dizi_kopya diye bir dizi tanýmlarýz
    char dizi_kopya[MAX];
    //i diye bir degisken tanýmlarýz
    int i;
	//dizi_kopyanin basýndaki elemaný sayi2 degiskenine atarýz
    sayi2=dizi_kopya;
	
    for(sayi1=dizi;sayi1<dizi+MAX;sayi1++)
    {
        *sayi2=*sayi1;
        sayi2++;

    }
    printf("Original tablo : ");

    for(i=0;i<MAX;i++)
    {
        printf("%c",*(dizi+i));
    }
    printf("\nKopya Tablo :");
    for(i=0;i<MAX;i++)
    {
        printf("%c",*(dizi_kopya+i));
    }

    return 0;
}
/*Original tablo : klbdqisteforchx
Kopya Tablo :klbdqisteforchx
*/

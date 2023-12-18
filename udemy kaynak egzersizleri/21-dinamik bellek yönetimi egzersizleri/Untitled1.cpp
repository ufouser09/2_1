#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Klavyeden girilen N adet tamsayÄ±nÄ±n bellekten yer ayrÄ±larak belleÄŸe yazÄ±lmasÄ±nÄ± ve bellekten okunarak
    ekrana listelenmesini saÄŸlayan C programÄ±nÄ± yazÄ±nÄ±z.*/
	//p pointerı tanımlanmıs
    int *p;
    //N degiskeni tanımlanır
    int N;
    //i degiskeni tanımlanır
    int i;
    //kullanıcıdan N degerini alırız
    printf("N degerini giriniz\n");
    scanf("%d",&N);
	//bellekte int boyutunda N tane yer ayrılır
    p=(int *)malloc(N*sizeof(int));
	//kullanıcıdan degerler alınır
    for(i=0;i<N;i++)
    {
        printf("%d. sayi",i+1);
        scanf("%d",&(*(p+i)));
    }
    //kullanıcıdan aldıgımız degerleri ekrana yazdırılır
    for(i=0;i<N;i++)
    {
        printf("%d\n",*(p+i));
    }

    return 0;
}
/*
output:
N degerini giriniz
3
1. sayi1
2. sayi4
3. sayi6
1
4
6
*/

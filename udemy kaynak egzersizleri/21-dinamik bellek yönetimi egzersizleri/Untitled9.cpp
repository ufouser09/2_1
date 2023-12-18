#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Klavyeden girilen N adet tam sayının bellekten yer ayrılarak belleğe yazılmasını ve bellekten okunarak toplatılmasını
    ve ortalmasının bulunmasını sağlayan C programını yazınız.*/
    int *bellek;
    int N;
    int i;
    float toplam=0;
    float ortalama;


    printf("Lutfen eleman sayisini giriniz\n");
    scanf("%d",&N);

    bellek=(int *)calloc(N,sizeof(int));
    for(i=0;i<N;i++)
    {
        printf("%d. sayi:",i+1);
        scanf("%d",bellek+i);
        toplam += *(bellek+i);

    }
    ortalama=toplam/N;
    printf("Ortalama:%f ",ortalama);

    return 0;
}
/*
output:
Lutfen eleman sayisini giriniz
3
1. sayi:6
2. sayi:7
3. sayi:4
Ortalama:5.666667
*/

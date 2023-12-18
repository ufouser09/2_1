#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Klavyeden girilen N adet tam sayının bellekten yer ayrılarak belleğe yazılmasını ve bellekten okunarak toplatılmasını
    sağlayan C programını yazınız.*/


    int *bellek;
    int N;
    int i;
    int toplam=0;


    printf("Lutfen eleman sayisini giriniz\n");
    scanf("%d",&N);

    bellek=(int *)calloc(N,sizeof(int));
    for(i=0;i<N;i++)
    {
        printf("%d. sayi:",i+1);
        scanf("%d",bellek+i);
        toplam += *(bellek+i);

    }

    printf("Toplam =%d",toplam);

    return 0;
}
/*
output:
Lutfen eleman sayisini giriniz
4
1. sayi:1
2. sayi:5
3. sayi:8
4. sayi:2
Toplam =16
*/

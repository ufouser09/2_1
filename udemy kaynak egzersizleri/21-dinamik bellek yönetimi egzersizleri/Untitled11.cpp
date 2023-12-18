#include <stdio.h>
#include <stdlib.h>

int main()
{
   /* Bilgisayar tarafından üretilen rastgele sayılar iki farklı bellek bölgesinde tutulmaktadır.Bellek boyutları
    birbirinden farklıdır.Buna göre bu iki diziyi dinamik bellek kullanarak tek bir dizide birleştiren ve ekrana
    gösteren C programını yazınız.*/
    int N,M;
    int *dizi1,*dizi2,*sonuc;
    int sayac=0;
    int i;


    printf("Birinci dizi icin kac tane sayi uretilecek\n");
    scanf("%d",&N);
    printf("Ikinci dizi icin kac tane sayi uretilecek\n");
    scanf("%d",&M);

    dizi1=calloc(N,sizeof(int));
    dizi2=calloc(M,sizeof(int));

    srand(time(0));
    printf("Birinci dizi elemanlari\n");
    for(i=0;i<N;i++)
    {
        *(dizi1+i)=rand()%50;
        printf("%d  ",*(dizi1+i));
    }
    printf("\n");

    printf("Ikinci dizi elemanlari\n");
    for(i=0;i<M;i++)
    {
        *(dizi2+i)=rand()%100;
        printf("%d  ",*(dizi2+i));
    }

    sonuc=calloc(N+M,sizeof(int));
    printf("\n Birlestirilmis Dizi\n");
    for(i=0;i<N;i++)
    {
        *(sonuc+sayac)=*(dizi1+i);
        sayac++;
    }
    for(i=0;i<M;i++)
    {
        *(sonuc+sayac)=*(dizi2+i);
        sayac++;
    }
    for(i=0;i<sayac;i++)
    {
        printf("%d  ",*(sonuc+i));
    }

    free(dizi1);
    free(dizi2);
    free(sonuc);

    return 0;
}
/*
output:
programda bir sorun var
*/

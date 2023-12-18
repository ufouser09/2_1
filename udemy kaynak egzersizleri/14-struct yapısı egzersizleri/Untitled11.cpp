#include <stdio.h>
#include <stdlib.h>
#define N 5


typedef struct
    {
        char ilac_adi[20];
        int adet;
        int fiyat;
    }data;
int main()
{
    /*Bir eczane stoklarında bulunan 100 farklı ilaca ait bilgileri saklamak istemektedir.
    Bunun için aşağıda verilen yapı kullanılmaktadır.Buna göre verilen yapıyı kullanarak
    100 adet ilaç bilgisini tutan ve ilaç adedi 20 ve altında olan ilaçların adlarını bulmaya
    yarayan C programını yazınız.*/

    data veriler[N];
    int i;
    char satir;

    for(i=0;i<N;i++)
    {
        fflush(stdin);
        printf("Lutfen ilac adini giriniz\n");
        gets(veriler[i].ilac_adi);

        printf("Lutfen ilac adedini giriniz\n");
        scanf("%d",&veriler[i].adet);

        printf("Lutfen ilac fiyatini giriniz\n");
        scanf("%d",&veriler[i].fiyat);


    }
    printf("ILAC ADI\n");
    printf("=============\n");

    for(i=0;i<N;i++)
    {
        if(veriler[i].adet<=20)
        {
            printf("%s\n",veriler[i].ilac_adi);
        }
    }



    return 0;
}

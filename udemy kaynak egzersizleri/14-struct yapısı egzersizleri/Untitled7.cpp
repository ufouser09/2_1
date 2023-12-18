#include <stdio.h>
#include <stdlib.h>



union hesapla{

    int cevre;
    int alan;
    };
 /*Yukarıda verilen union ı kullanarak bir dairenin alanını ve çevresini hesaplayan C programını yazınız.
    Pı sauısını 3 alınız.*/
int main()
{
    int yaricap;
    union hesapla bul;

    printf("Lutfen yaricapi giriniz\n");
    scanf("%d",&yaricap);

    bul.cevre=2*3*yaricap;
    printf("Cevresi=%d\n",bul.cevre);

    bul.alan=3*yaricap*yaricap;
    printf("Alan=%d",bul.alan);


    return 0;
}
/*
output:
Lutfen yaricapi giriniz
2
Cevresi=12
Alan=12
*/

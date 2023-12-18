#include <stdio.h>
#include <stdlib.h>

typedef struct karmasik_sayi
    {
        float reel;
        float sanal;
    }karmasik;

/*Karmaşık sayılarda toplama işlemi yapılırken reel ve sanal kısımlar ayrı ayrı toplanmaktadır.
    Buna göre kullanıcı tarafından girilen a+bi şeklindeki iki karmaşık sayının toplamını aşağıda
    verilen fonksiyon prototipi ve yapıyı kullanarak gerçekleştiren C programını yazınız.
    void topla(karmasik n1,karmasik n2);*/
    void topla(karmasik n1,karmasik n2)
    {
        karmasik temp;
        temp.reel=n1.reel+n2.reel;
        temp.sanal=n1.sanal+n2.sanal;
        printf("%.1f +%.1f i\n",n1.reel,n1.sanal);
        printf("%.1f +%.1f i\n",n2.reel,n2.sanal);
        printf("Toplam= %.1f +%.1f i",temp.reel,temp.sanal);

    }

int main()
{
    karmasik k1,k2;
    printf("Birinci sayinin reel ve sanal kismini giriniz\n");
    scanf("%f%f",&k1.reel,&k1.sanal);

    printf("Ikinci sayinin reel ve sanal kismini giriniz\n");
    scanf("%f%f",&k2.reel,&k2.sanal);

    topla(k1,k2);



    return 0;
}
/*
Birinci sayinin reel ve sanal kismini giriniz
2
3
Ikinci sayinin reel ve sanal kismini giriniz
3
4
2.0 +3.0 i
3.0 +4.0 i
Toplam= 5.0 +7.0 i
*/

#include <stdio.h>
#include <stdlib.h>
#define N 2
struct oyuncu
{
    char soyisim[10];
    char isim[10];
    int yas;
    int seviye;
};

struct equipe
{
    char isim[10];
    struct oyuncu oyuncu1;
    struct oyuncu oyuncu2;
};
void oyuncuyu_olustur(struct oyuncu *j)
{
    printf("Ismi giriniz:");
    scanf("%s",j->isim);
    printf("Soyismi giriniz:");
    scanf("%s",j->soyisim);
    printf("Yasi giriniz :");
    scanf("%d",&j->yas);
    printf("Seviyeyi giriniz");
    scanf("%d",&j->seviye);
}


void ekibi_olustur(struct equipe *e)
{
    printf("Ekibib adinin giriniz : \n");
    scanf("%s",e->isim);
    printf("Oyuncu 1 :\n");
    oyuncuyu_olustur(&e->oyuncu1);
    printf("Oyuncu 2 :\n");
    oyuncuyu_olustur(&e->oyuncu2);

}
void ekibi_bas(struct equipe e)
{
    printf("Ýsim: %s\n",e.isim);
    printf("Oyuncu 1 :\n");
    oyuncuyu_bas(e.oyuncu1);
    printf("Oyuncu 2 : \n");
    oyuncuyu_bas(e.oyuncu2);

}
void oyuncuyu_bas(struct oyuncu j)
{
    printf("isim : %s\n ",j.isim);
    printf("soyisim : %s\n ",j.soyisim);
    printf("yas : %d\n",j.yas);
    printf("seviye : %d\n",j.seviye);
}


int main()
{
    struct equipe tab[N];
    int i;
    for(i=0;i<N;i++)
    {
        printf("Ekip %d : \n",i);
        ekibi_olustur(&tab[i]);
    }
    for(i=0;i<N;i++)
    {
        printf("Ekip %d :\n",i);
        ekibi_bas(tab[i]);
    }
    return 0;
}
//kodda bir sorun var

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//cumlem diye bir dizi tanýmlarýz
    char cumlem[100];
    //*p1 ve *p2 degiskenlerini tanýmlarýz
    char *p1,*p2;
    //kontrol diye bir degisken tanýmlarýz
    int kontrol;


	//kullanýcýdan cumle girmesi istenir
    printf("Lutfen maksimum 100 karakterli bir cumle giriniz\n");
    //gets ile string yani cumle alabilirsin
    gets(cumlem);
	//p2=cumlem demek cumlenin basýndaki karakterden basla demek 
    for(p2=cumlem;*p2;p2++);

    p2--;

	//kontrol degiskenini tanýmlar ve 1 sayýsýný atarýz
    kontrol=1;
    //p1=cumlem cumlem dizisinin basýndan basla demek
    for(p1=cumlem;kontrol && p1<p2;p1++,p2--)
    {
        if(*p1 != *p2)
        {
            kontrol=0;
        }
    }

    if(kontrol)
    {
        printf("Girilen %s bir palendomdur",cumlem);
    }
    else
    {
        printf("Girilen %s bir palendrom degildir",cumlem);
    }
    return 0;
}
/*
output:
Lutfen maksimum 100 karakterli bir cumle giriniz
efe girgin
Girilen efe girgin bir palendrom degildir

Lutfen maksimum 100 karakterli bir cumle giriniz
efe
Girilen efe bir palendomdur

*/


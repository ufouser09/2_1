#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
/*
    -1.Bir öğrencinin okul numarası,adı,soyadı ve yaş bilgilerini tutan ogrenci_bilgi
    adlı bir yapı tanımlayınız
    -2.ogrenci_1 ve ogrenci_2 değişkenlerini ogrenci_bilgi yapı tipinde tanımlayınız
    -3.Aşağıdaki öğrenci bilgilerini ogrenci_1 değişkenine atayınız.
    Okul numarası:522
    Adı:Can
    Soyadı:Boz
    Yaşı:18
    -4 ogrenci_1 değişkenini,ogrenci_2 değişkenine kopyalayınız.
*/
	//Struct ��renci bilgi diye bir struct olusturduk
    struct ogrenci_bilgi{
    int no;
    char ad[10];
    char soyad[10];
    int yas;
    };
	//struct ��renci_bilgi diye adland�rd�g�m�z structa ��renci_1 ve ��renci_2 ismini veririz
    struct ogrenci_bilgi ogrenci_1,ogrenci_2;
    
    //ogrenci_1 ismindeki structa 522 degerini atar�z
    ogrenci_1.no=522;
    //ogrenci_1 ismindeki structa can degerini atar�z
    strcpy(ogrenci_1.ad,"Can");
    //ogrenci_1 ismindeki structa boz degerini atar�z
    strcpy(ogrenci_1.soyad,"Boz");
    //ogrenci_1 ismindeki structa 18 degerini atar�z
    ogrenci_1.yas=18;

	//��enci_1 struct�ndaki bilgileri b�ylece struct_2 ye at�yabiliriz
    ogrenci_2=ogrenci_1;
    //struct_2 deki bilgileri yazd�r�r�z ekrana
    printf("%d %s %s %d",ogrenci_1.no,ogrenci_1.ad,ogrenci_1.soyad,ogrenci_1.yas);
    return 0;
}
/*
522 Can Boz 18
*/

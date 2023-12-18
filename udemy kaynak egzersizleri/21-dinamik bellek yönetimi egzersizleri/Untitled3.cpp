#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*KullanÄ±cÄ± tarafÄ±ndan girilen iki adet tamsayÄ± iÃ§in farklÄ± bellek bÃ¶lgelerinde yer ayrÄ±lmaktadÄ±r.Buna
    gÃ¶re bu iki bellek bÃ¶lgesinde yer alan sayÄ±larÄ±n yerlerinin deÄŸiÅŸtirilmesini saÄŸlayan C programÄ±nÄ±
    yazÄ±nÄ±z.*/

	//*p1 pointerı *p2 pointerı ve gecici degiskeni tanımlarız
    int *p1,*p2,gecici;
    //p1 ve p2 pointerında int boyutunda bir yer ayrılır
    p1=(int *)malloc(sizeof(int));
    p2=(int *)malloc(sizeof(int));
	//kullanıcıdan birinci sayimizi alırız
    printf("Birinci sayi\n");
    scanf("%d",&(*p1));
	//kullanıcıdan ikinci sayimizi alırız
    printf("Ikinci sayi");
    scanf("%d",&(*p2));

	//p1 ve p2 degiskenlerini ekrana yazdırırız
    printf("Sayi1 =%d Sayi2 =%d\n ",*p1,*p2);

	//p1 ve p2 pointerlarının yerlerini degistiririz
    gecici=*p1;
    *p1=*p2;
    *p2=gecici;

	//p1 ve p2 pointerlarını ekrana yazdırırız
    printf("Sayi1 =%d Sayi2 =%d",*p1,*p2);
	//son olarak p1 ve p2 pointerları için bellekte ayırdıgımız yeri bosaltırız
    free(p1);
    free(p2);

    return 0;
}
/*
output:
Birinci sayi
3
Ikinci sayi4
Sayi1 =3 Sayi2 =4
 Sayi1 =4 Sayi2 =3
 */

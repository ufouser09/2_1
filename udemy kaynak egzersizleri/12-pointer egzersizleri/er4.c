#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//dizi adli bir dizi tanýmlarsýn	
    char dizi[100];
    //eleme adlý bir degisken tanýmlarsýn
    char eleme;
    //*can adlý bir degisken tanýmlarsýn
    char *can;
	//kullanýcýdan bir karakter dizisi istersin
    printf("Lutfen bir karakter dizisi girin\n");
    //String ifadeleri gets ile alýrsýn
    gets(dizi);
    //karakter dizisinden çýkarmak istediginiz karakteri kullanýcýdan alýrsýn
    printf("Karakter dizisinden cýkarmak istediginiz karakter nedir :");
    scanf("%c",&eleme);
	//dizinin basýndaki elemaný can'a atarsýn
    can=dizi;
    //dizinin sonuna kadar gider
    while(*can)
    {
    	//dizinin içinde gezerken çýkarmak istedigimiz elemanla karsýlasýrsak bu if'e gireriz
        if(*can==eleme)
        {
        	//dizinin bir sonraki elemanýný su anki degerimiz yerine yerlestiririz
            strcpy(can,can+1);
        }
        else
        {
        	//can indis degerimiz gibidir onu bir arttýrýrýz
            can++;
        }
    }


    printf("Eleme yapildiktan sonra karakter dizimizin son hali :%s ",dizi);
    return 0;
}
/*
output:
Lutfen bir karakter dizisi girin
efeee
Karakter dizisinden c²karmak istediginiz karakter nedir :e
Eleme yapildiktan sonra karakter dizimizin son hali :f
*/

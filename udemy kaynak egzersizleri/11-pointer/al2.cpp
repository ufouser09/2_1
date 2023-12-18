#include <stdio.h>
#include <stdlib.h>

int main()
{
	//pointer cinsinde 3 tane degisken tutarız
    int *ad1,*ad2,*ad;
    //n degiskeni 10,p degiskenine 20 degerini atarız
    int n=10,p=20;


	//n'in adresini ad1 adresine atarız
    ad1=&n;
    //p'nin adresini ad2 adresine atarız
    ad2=&p;
	//ad1 artık n in degerini gösterir o da 10 dur
    printf("Atamadan önce ad1 degeri %d\n",*ad1);
	//ad1 yazdıgımız için ad1 in adresini gösterir
    printf("%d\n",ad1);
	//ad2'nin degerini 2 arttırıp ad1'e atarsak 22 diye cıkar çunku ad2 20'ydi 2 arttırıp ad1'e atadık
    *ad1=*ad2+2;
	//ad1 degerimiz artık 22 diye cıkar
    printf("Atamami yaptiktan sonra ad1 degeri %d\n",*ad1);
    //ad1 dedigimiz için adresi cıkar
    printf("%d\n",ad1);

    return 0;
}
/*
output:
Atamadan ÷nce ad1 degeri 10
6487564
Atamami yaptiktan sonra ad1 degeri 22
6487564
*/

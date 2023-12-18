#include <stdio.h>
#include <stdlib.h>

int main()
{
	//bir tane isim dizisi tutarýz
    char isim[20]={'b','o','n','j','o','u','r','\0'};
    //*can degiskeni tanýmlarýz
    char *can;
	//isim dizisinin basýndaki degeri can'a pointer'ýna atarýz	
    can=isim;
	//*(can+1)ile de dizinin bir sonraki elemanýna yani 2.elemaný olan 'o' karakterine ulasýrýz 
    printf("%c",*(can+1));


    return 0;
}
/*
output:
o
*/

#include <stdio.h>
#include <stdlib.h>
//N sayisini basta tanýmlarýz
#define N 10

int main()
{
	//i min max degiskenlerini tanýmlarýz
    int i,min,max;
    //*canan degiskenini tanýmlarýz
    int *canan;
    //can dizisi tanýmlarýz
    int can[N];
    //N degiskenini ekrana yazdýrýrýz
    printf("%d kadar deger giriniz",N);
    //canan=can demek dizinin basýný isaret eder
    //burda ise diziyi kullanýcýdan alýrýz
    for(canan=can;canan<can+N;canan++)
    {
        scanf("%d",canan);
    }
//dizinin ilk degerini maks ve min olarak kabul ederiz
max=min=can[0];
	//canan=can+1 yapmamýzýn sebebi zaten ilkýný maks ve min olarak kabul ettik o degeri digerleriyle karsýlastýrýcaz
    for(canan=can+1;canan<can+N;canan++)
    {
    	//sýradaki indisteki eleman max dan buyuk mu kucuk mu ona bakar 
        if(*canan>max)
        {
        	//eger maxdan buyukse buraya girer ve o degeri yeni max degiskenine atar artýk max sayimizi o sayi kabul ederiz
            max=*canan;
            
        }
        //siradaki degisken min den kucuk mu onu kontrol eder
        if(*canan<min)
        {
        	//eger min den kucukse buraya girer ve o sayiyi min degiskenine atar yeni min sayimizi o sayi kabul ederiz
            min=*canan;
        }
    }
    //max ve min'i burda ekrana yazdýrýrýz
    printf("Dizimizin maksimum degeri: %d\n",max);
    printf("Dizimizin minumum degeri : %d\n",min);

    return 0;
}
/*
output:
10 kadar deger giriniz3
2
1
4
5
6
7
8
9
8
Dizimizin maksimum degeri: 9
Dizimizin minumum degeri : 1
*/

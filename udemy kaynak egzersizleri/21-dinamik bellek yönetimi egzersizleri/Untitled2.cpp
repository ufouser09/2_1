#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Bilgisayar tarafýndan rastgele üretilen N adet tamsayýyý belleðe yazan ve bellekten okuyarak
    karelerini ekrana listeleyen C programýný yazýnýz.*/
	//p pointerý ve i ve N degiskenleri tanýmlanýr
    int *p,i,N;
	//kac adet sayi üretilecegini kullanýcýdan alýrýz
    printf("Kac adet sayi uretilecek\n");
    scanf("%d",&N);
    //int boyutunda N tane bellekte yer ayrýlýr
    p=(int *)malloc(N*sizeof(int));
    //random
    srand(time(0));
    
    printf("Uretilen sayilar\n");
    for(i=0;i<N;i++)
    {
    	//random sayilar atarýz 
        *(p+i)=rand()%100;
        printf("%d  ",*(p+i));
    }
    printf("\n");
    printf("Kareleri:");
    printf("\n");
    //sonra bu atanan degerlerin karelerini yazdýrýrýz
    for(i=0;i<N;i++)
    {
        printf("%d  ",(*(p+i))*(*(p+i)));
    }
    return 0;
}
//programda bir sorun var

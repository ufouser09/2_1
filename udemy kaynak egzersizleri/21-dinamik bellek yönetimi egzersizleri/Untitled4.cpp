#include <stdio.h>
#include <stdlib.h>

int main()
{
   /*Bilgisayar tarafýndan rastgele üretilen N adet tamsayýnýn belleðe,ardýndan bellekten okunan deðerlerin
   sayi.txt text dosyasýna yazýlmasýný ve dosyadan okunan degerlerin ekrana listelenmesini saðlayan C programýný
   yazýnýz.*/


   FILE *dosya;
   //p pointerýný ve N,i,c degiskenlerini tanýmlarýz 
   int *p,N,i,c;
	//kullanýcýdan kac adet sayi girilecegini alýnýz
   printf("Kac adet tamsayi girilecek\n");
   scanf("%d",&N);
   
   p=(int *)malloc(N*sizeof(int));
   dosya=fopen("sayi.txt","w");
   srand(time(0));
   printf("Uretilen sayilar\n");

   for(i=0;i<N;i++)
   {
       *(p+i)=rand()%100;
       fprintf(dosya,"%d ",*(p+i));
       printf("%d ",*(p+i));
   }
   fclose(dosya);
   printf("Okunan sayÄ±lar\n");

   dosya=fopen("sayi.txt","r");
   do
   {
       c=getc(dosya);
       if(c !=EOF)
       {
           putchar(c);
       }

   }while(c != EOF);
   fclose(dosya);
   free(p);

    return 0;
}
//programda bir sorun var

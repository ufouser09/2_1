#include <stdio.h>
#include <stdlib.h>

int main()
{
	//ptr pointer 
  int *ptr;
	//n degeri tanýmlanýr
  int n;
  //n'e 5 degeri atýlýr
  n=5;
  //i degsikeni tanýmlanýr
  int i;
  //n degerini ekranda gösterir
  printf("Girdigimiz sayi degeri %d\n",n);
	//bu ifade n tane int boyutunda dizi yapar
  ptr=(int*)malloc(n*sizeof(int));
	//ama bellek içinde yeterli alan olmýyabilir o zaman null döner sistemin null dönüp dönmediðini kontrol etmen lazým
  if(ptr==NULL)
  {
      printf("Hafiza bolunmedi\n");
  }

  else
  {
  	
  		//burda diziye sayilar aktarýlýr 
      for(i=0;i<n;i++)
      {
          ptr[i]=i+1;
      }
		//diziye tanýmlanan sayilar yazdýrýlýr
      printf("Elemanlarim\n");
      for(i=0;i<n;i++)
      {
          printf("%d, ",ptr[i]);
      }
		//en son kullandýgýn alaný bosaltman lazým
      free(ptr);

  }
    return 0;
}
/*
Girdigimiz sayi degeri 5
Elemanlarim
1, 2, 3, 4, 5,
*/

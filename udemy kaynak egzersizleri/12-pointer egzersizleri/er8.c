#include <stdio.h>
#include <stdlib.h>

int main()
{
   char dizi[5][50];
   char *ilk;
   char *ikinci;
   int i;
   char gecici;

   printf("Lutfen 5 adet kelime giriniz:  \n");

   for(i=0;i<5;i++)
   {
       printf("%d. kelime ",i);
       scanf("%s",dizi[i]);
   }

   for(i=0;i<5;i++)
   {
      ilk=ikinci=dizi+i;

          while(*ikinci)
          {
              ikinci++;
          }
          ikinci--;
          while(ilk<ikinci)
          {
              gecici=*ilk;
              *ilk=*ikinci;
              *ikinci=gecici;
              ilk++;
              ikinci--;
          }

   }

   for(i=0;i<5;i++)
   {
       printf("%s \n",*(dizi+i));
   }








    return 0;
}
/*
output:
Lutfen 5 adet kelime giriniz:
0. kelime efe
1. kelime girgin
2. kelime ee
3. kelime rr
4. kelime tt
efe
nigrig
ee
rr
tt
*/

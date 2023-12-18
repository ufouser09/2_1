#include <stdio.h>
#include <stdlib.h>

int main()
{
   /*Klavyeden satır ve sütün sayısı girilen bir matrise bellekten yer ayrılarak değer yazan
   ve bu matrisi ekrana gösteren C programını yazınız.*/

   int satir,sutun;
   int i,j;
   int **matris;

   printf("Lutfen satir sayisini giriniz\n");
   scanf("%d",&satir);

   printf("Lutfen sutun sayisini giriniz\n");
   scanf("%d",&sutun);


   matris=(int **)calloc(satir,sizeof(int *));

   for(i=0;i<satir;i++)
   {
       matris[i]=(int *)calloc(sutun,sizeof(int));
       for(j=0;j<sutun;j++)
       {
           printf("Matris[%d][%d]=",i,j);
           scanf("%d",&(matris[i][j]));
       }
   }

   for(i=0;i<satir;i++)
   {
       for(j=0;j<sutun;j++)
       {
           printf("%3d",matris[i][j]);
       }
       printf("\n");
   }

   for(i=0;i<satir;i++)
   {
       free((void *)matris[i]);

   }

   free((void *)matris );






    return 0;
}
/*
output:
Lutfen satir sayisini giriniz
2
Lutfen sutun sayisini giriniz
2
Matris[0][0]=1
Matris[0][1]=2
Matris[1][0]=3
Matris[1][1]=4
  1  2
  3  4
*/

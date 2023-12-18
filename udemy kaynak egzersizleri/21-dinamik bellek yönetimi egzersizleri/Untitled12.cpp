#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Kullanıcı tarafından girilen N*N boyutlarındaki bir matrisin köşegen değerlerinin toplamını dinamik bellek
    kullanarak gerçekleştiren C programını yazınız.*/
    int boyut;
    int **matris;
    int i,j;
    int toplam=0;

    printf("Lutfen matrisin boyut ve sutun sayisini giriniz\n");
    scanf("%d",&boyut);
    matris=(int **)malloc(boyut*sizeof(int *));

    for(i=0;i<boyut;i++)
    {
        matris[i]=(int *)calloc(boyut,sizeof(int));
        for(j=0;j<boyut;j++)
        {
            printf("Matris[%d][%d]=",i,j);
            scanf("%d",&(matris[i][j]));

        }
    }

    for(i=0;i<boyut;i++)
    {
        for(j=0;j<boyut;j++)
        {
            if(i==j)
            {
                toplam=toplam+matris[i][j];
            }
        }
    }

    printf("Toplam = %d",toplam);
    return 0;
}
/*
output:
Lutfen matrisin boyut ve sutun sayisini giriniz
2
Matris[0][0]=2
Matris[0][1]=3
Matris[1][0]=1
Matris[1][1]=4
Toplam = 6
*/

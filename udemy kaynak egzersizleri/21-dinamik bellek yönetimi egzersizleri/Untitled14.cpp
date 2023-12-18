#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /*Kullanıcı tarafından girilen bir kelimenin karakterlerinin aşağıdaki şekilde ekrana gösterilmesini
    sağlayan C programını dinamik bellek kullanarak yazınız


    Kelime giriniz:kelime
    k
    k e
    k e l
    k e l i
    k e l i m
    k e l i m e*/
    int i=0,j=0;
    char *kelime;
    kelime=(char *)malloc(50*sizeof(char));

    printf("Lutfen kelime giriniz\n");
    gets(kelime);

    while(i<strlen(kelime))
    {
        j=0;
        while(j<=i)
        {
            printf("%c ",*(kelime+j));
            j++;
        }
        printf("\n");
        i++;
    }
    free(kelime);
    return 0;
}
/*
output:
Lutfen kelime giriniz
kelime
k
k e
k e l
k e l i
k e l i m
k e l i m e
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /*Klavyeden girilen bir cümlenin tersten okunuşunu dinamik bellek kulanarak elde etmeye
    yarayan C programını yazınız*/
    char *metin;
    int i;
    metin=(char *)malloc(50*sizeof(char));

    printf("Lutfen bir cumle giriniz\n");
    gets(metin);
    for(i=strlen(metin)-1;i>=0;i--)
    {
        printf("%c",*(metin+i));
    }

    free(metin);


    return 0;
}
/*
output:
Lutfen bir cumle giriniz
efe girgin
nigrig efe
*/

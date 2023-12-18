#include <stdio.h>
#include <stdlib.h>

int main()
{
   /*Kullanıcı tarafından girilen bir cümlenin dinamik belleğe yazılarak ve bellekten okunarak ekrana
    gösterilmesini sağlayan C programını yazınız.*/

    char *metin;
    metin=(char *)calloc(100,sizeof(metin));

    printf("Lutfen bir cumle giriniz\n");
    gets(metin);

    printf("Girdiginiz cumle: %s",metin);



    return 0;
}
/*
output:
Lutfen bir cumle giriniz
efe
Girdiginiz cumle: efe
*/

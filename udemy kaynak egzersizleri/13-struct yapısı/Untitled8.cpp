#include <stdio.h>
#include <stdlib.h>

 typedef enum
 {
   ocak=1,
   subat,
   mart,
   nisan,
   mayis,
   haziran,
   temmuz,
   agustos,
   eylul,
   ekim,
   kasim,
   aralik

 }aylar;

void ayi_goster(aylar canan)
{
    switch(canan)
    {
    case ocak:
        printf("Ocak");
        break;
        case subat:
        printf("subat");
        break;
        case mart:
        printf("mart");
        break;
        case nisan:
        printf("nisan");
        break;
        case mayis:
        printf("mayıs");
        break;
        case haziran:
        printf("haziran");
        break;
        case temmuz:
        printf("temmuz");
        break;
        case agustos:
        printf("agustos");
        break;
        case eylul:
        printf("eylul");
        break;
        case ekim:
        printf("ekim");
        break;
        case kasim:
        printf("kasim");
        break;
        case aralik:
        printf("aralik");
        break;
        default:
        printf("Boyle bir ay yok");
        break;

    }
}

int main()
{
    char a="Can";
    aylar can=a;
    ayi_goster(can);
    return 0;
}
//programda bir sorun var


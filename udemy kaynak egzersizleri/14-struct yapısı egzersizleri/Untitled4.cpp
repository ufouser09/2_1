#include <stdio.h>
#include <stdlib.h>

struct degerTip{
int tip;
union{
char kar;
float sayi;
}bir;

};



int main()
{
  /*  Birinci elemanı tamsayı ve ikinci elemanı bir birleşim olan yapı dizisini(en fazla 20 elemanlı)
    tanımlayınız.Birleşim tipindeki eleman,karakter ve reel sayı olan 2 elemnadan oluşsun.Programınızda
    bir tamsayı değerine göre bir karakter veya bir reel sayıyı girdi olarak alınız.Bu tamsayı değeri
    1 ise bir karakter 0 ise bir reel sayı girilmelidir.Bu tamsayıları ve bu tamsayılara bağlı olarak
    karaker veya reel sayıları bu yapı dizisinde saklayınız.Veri girme işlemi ise tamsayı
    değerinin 0 ve 1 den farklı bir sayı girilmesiyle sonlanmalıdır.Ayrıca yapı dizisi tarayarak
    reel sayıların ortalamasını bulunuz.*/
    struct degerTip degerler[20];
    char satir;
    int i=-1;
    float ortalama=0.0;
    int j;
    int n=0;
    do
    {
        i++;
        printf("Lutfen bir tamsayi giriniz\n");
        scanf("%d",&degerler[i].tip);
        scanf("%c",&satir);
        if(degerler[i].tip==1)
        {
            printf("Karakter giriniz\n");
            scanf("%c",&degerler[i].bir.kar);
              scanf("%c",&satir);
        }
        else if(degerler[i].tip==0)
        {
            printf("Reel sayi giriniz\n");
            scanf("%f",&degerler[i].bir.sayi);
        }

    }while(degerler[i].tip==0 || degerler[i].tip==1);


    for(j=0;j<=i;j++)
    {
        if(degerler[j].tip==0)
        {
            ortalama +=degerler[j].bir.sayi;
            n++;
        }
    }

    ortalama=ortalama/n;
    printf("Reel sayilarin ortalamasi : %f",ortalama);



    return 0;
}
/*
output:
Lutfen bir tamsayi giriniz
3
Reel sayilarin ortalamasi : -1.#IND00
*/

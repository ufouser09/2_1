#include <stdio.h>
#include <stdlib.h>

union paylasim_kontrol{
int x;
int y;

}kontrol;


int main()
{/*
    Klavyeden girilen sayıları tutan iki adet değişken için aynı bellek bölgesini paylaşan paylas adında bir
    union tanımlayınız ve değişkenlerin kullandıkları bellek bölgesinin adreslerini ekrana gösteriniz.*/

    int *X,*Y;
    kontrol.x=100;

    X=&kontrol.x;
    printf("Tamsayi(x)=%d bellek adresi %X\n",kontrol.x,X);

    kontrol.y=200;
    Y=&kontrol.y;
    printf("Tamsayi(y)=%d bellek adresi %X\n",kontrol.y,Y);


    return 0;
}
/*
output:
Tamsayi(x)=100 bellek adresi 407030
Tamsayi(y)=200 bellek adresi 407030

*/

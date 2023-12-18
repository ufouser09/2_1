#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Bilgisayar tarafÄ±ndan Ã¼retilen N adet rastgele tamsayÄ±nÄ±n bellekten yer ayrÄ±larak
    belleÄŸe yazÄ±lmasÄ±nÄ± ve bu tamsayÄ±lar iÃ§erisinden en kÃ¼Ã§Ã¼ÄŸÃ¼nÃ¼n bulunmasÄ±nÄ± saÄŸlayan
    C programÄ±nÄ± yazÄ±nÄ±z.*/
    //p pointerını tanımlarız
    int *p;
    //N degiskenini tanımlarız
	int N;
    //i degiskenini tanımlarız
    int i;
    //enk degiskenini tanımlarız
    int enk;
    //kullanıcıdan kac adet sayi girilecegini alırız
    printf("Kac adet sayi uretilecek\n");
    scanf("%d",&N);
    //p ponterı için N tane int boyutunda bellekte yer ayırırız
    p=(int *)malloc(N*sizeof(int));
	//random
    srand(time(0));
    //random sayilar dizimize aktarılır
    for(i=0;i<N;i++)
    {
        *(p+i)=rand()%50;
        printf("%d  ",*(p+i));
    }
    
    printf("\n");
    //p pointerı enk degşskenine aktarılır
	enk=*p;
    for(i=1;i<N;i++)
    {
        if(*(p+i)<enk)
        {
            enk=*(p+i);
        }
    }

    printf("En kucuk tamsayi =%d\n",enk);
    free(p);




    return 0;
}
/*
output:
programda bir sorun var
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//t diye bir dizi tutariz	
    int t[100];
    //i degiskenini tanýmlarýz
    int i;
    //*pt degiskenini tanýmlarýz
    int *pt;

	
    for(pt=t;pt<t+100;pt++)
    {
        *pt=0;
    }
    for(pt=t;pt<t+100;pt++)
    {
        printf("%d\n",*pt);
    }


    /*for(i=0;i<100;i++)
    {
        t[i]=0;
    }
    for(i=0;i<100;i++)
    {
       printf("%d\n",t[i]);
    }*/



    return 0;
}
/*
output:
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*int can=10;
    int *p;

    p=&can;


    printf("%d\n",*p);
     printf("%d\n",p);
      printf("%d\n",can);
       printf("%d\n",&can);*/

	//sayi pointerı tutarız bir tane
    int *sayi;
    
	//n degiskeni tanımlarız
    int n;
   
    //n degerine 20 degeri atılır
    n=20;
	
	//n'in adresini sayi degiskeninın adresine atarız
    sayi=&n;
	
	//sayi degiskeni n'in adresini gösterdiği için 20 olarak çıkar
    printf("%d\n",*sayi);
    
	//sayi dedigimiz için adresi gösterir
    printf("%d\n",sayi);
     
	//n degiskenin degeri 20 dir
    printf("%d\n",n);
      
	  //&n dedigimiz için n degiskeninin adresini gösterir
       printf("%d\n",&n);
		
		//sayi degiskenimizin gösterdigi degeri 30 yaparız
       *sayi=30;
		//n'in adresini sayi degiskenine atadıgımız için n de artık 30 degerini gösterir
       printf("%d\n",n);
       //&n dedigimiz için adresi gösterir
        printf("%d",&n);



}
/*output:
20
6487572
20
6487572
30
6487572
*/

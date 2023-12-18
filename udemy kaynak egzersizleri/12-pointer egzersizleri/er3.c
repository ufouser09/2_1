#include <stdio.h>
#include <stdlib.h>

int main()
{
	//can diye bir dizi olusturursun
   char can[100];
   //*pointer adli degisken tanımlarsın
   char *pointer;

   printf("Lutfen bir karakter dizisi girin\n");
   gets(can);

   for(pointer=can;*pointer;pointer++)
   {

   }
   printf("Dizimiz %s %d kadar karakterden olusmaktadir.",can,pointer-can);
}
/*
output:
Lutfen bir karakter dizisi girin
efeee
Dizimiz efeee 5 kadar karakterden olusmaktadir.
*/

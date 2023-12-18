#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//burda struct öðrenci diye bir strucut tanýmlýyoruz
struct ogrenci{

char ad[10];
char soyad[10];
int yas;
};
//structlardan sonra int main() yaparýz
int main()
{
	//struct içinde tanýmladýgýmýz 3 degiskene böyle atama yapabiliriz.burda ayrýca struct ogrenci dedigimiz structa can ismini veririz
   struct ogrenci can={"Can","Boz",27};
   
   //structlarda bir degere erisebilmek için structýn ismi sonra nokta sonra ise struct içindeki degiskenin ismini koyarýz mesela burda structýn ismi can.ad diyip atadýgýmýz ad degiskenine erisebiliriz 
   /*strcpy(can.ad,"Can");
   strcpy(can.soyad,"Boz");
   can.yas=27;*/
	//burda atadýgýmýz degerleri ekrana yazdýrýrýz
   printf("%s \t %s \t %d",can.ad,can.soyad,can.yas);

    return 0;
}
/*
Can      Boz     27
*/

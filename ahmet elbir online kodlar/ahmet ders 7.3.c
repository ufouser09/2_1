  /* su ana kadar yaptýgýmýz calýsmalarda hep tek veri tipleriyle ilgilendik int character float gibi fakat gunluk hayatta daha cok nesnelerle ugrasýyoruz nesneler tek bir boyuttan yani tek bir özellikten olusmuyor burlarda structarlar devreye giriyor
mesela bir karmasýk sayi örnegi verelim mesela a+bi ilk kýsým reel kýsým diger kýsým imajýner kýsým 
sonracýma insanlarýn adý var yasý var memleketi var boyle bir suru durum var
sýmdý 100 tane ogrenci uzerinde ýslem yapýcak olsak 100 ogrencinin adý için 100 elemanlý bir dizi 100 ögrencinin yasý için 100 elemanlý bir dizi falan bunlarý yapabiliriz
fakat bu primitive obsession dedigimiz temel veri tiplerine baglý olmak takýntýlý olmak dedigimiz bir kod kusuru meydana getiriyor 
neden bir fonksiyona kiþilerin adlarýný yaslarýný vs hepsini gönderiyorsunuz
fakat bunu yapmak yerine biz structlar sayesinde kýsýler acýp tum iþimizi ordan halledebiliriz

structu gloabal bir degisken olarak ve fonksiyon olarak tanýmlýyabiliriz ama bizden global olarak tanýmlanmasý istenicek

tanýmlamayý gloabal yapýcaz fakat tanýmlamadan degisken üretmeyi gloabal yapmýcaz
*/

#include <stdio.h>
struct Complex{
	int r;
	int i;
};
typedef struct complex{
	int r;
	int i;
}COMPLEX;

typedef struct Complex CMP;
#define CMP2 struct complex
int main(){
	struct Complex c1;
	COMPLEX c3,*c2;
	//*c2 herhangi bir structýn adres bilgisini tutuyor.int içinde integer tutar integer pointer içinde integer adresi tutar.
	
	c2=&c3;
	//yukarda yaptýgýmýz iþlem cok onemli deger atamadan once pointerýn bir yeri isaret etmesi gerekir)
	c2->r=999;
	(*c2).i=88;
	
	CMP c4[3];
	c1.r=4;  
	c1.i=6;
	c4[3].r=0;
	c4[3].i=8;
	CMP2 c5;
	c5.r=44;
	c5.i=6;
	
	printf("%d - %di\n",c1.r,c1.i);
	printf("%d -%di\n",c4[3].r,c4[3].i);
	printf("%d-%di\n",c5.r,c5.i);

	printf("%d - %di\n",c2->r,(*c2).i);
}
/*
EMPLOYEE yunus;
yunus.ID=1234;
dogrudan bir þeye direct eriþimi kullanýyorsak nokta operatörünü kullanýyoruz.


eger pointer kullanarak eriþmek istiyorsak 2 türlü yontem var
EMPLOYEE *e_ptr;
(bu pointer tanýmlanmýs ama nereyi isaret ettigi gosterilmemis bu örnek yanlýs)
(bunun için öncesinde EMPLOYEE E;
sonra e_ptr=&E;yapmamýz gerekirdi.
yani ilk once pointerýn bir yeri göstermesi gerekirdi.)
e_ptr->ID=1234;
(bu birinci yontem)

(*e_ptr).ID=1234;
(bu da ikinci yontem)

eger iç içe struct olusturmak istiyorsak soyle yaparýz

typedef struct{
	short day,month;
	int year;
}DATE;
typedef struct {
	char name[20],surname[20];
	int ID;
	float salary;
	DATE enlisted;
}EMPLOYEE;

late you can write:
yunus.enlisted.year=2008;

structlari fonksiyon parametresi olarak göndermek

call pass by value(buradaki degisiklikler kaydedilmiyor)
EMPLOYEE emp;
printReport(emp);

call pass by referance(burdaki degisiklikler kaydediliyor)
EMPLOYEE emp;
increaseSalary(&emp);

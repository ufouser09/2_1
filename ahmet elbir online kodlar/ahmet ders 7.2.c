/*
butun fonksiyonlar parametre alýyor ve fonkisyonlarý cagýrýrken arguman gonderiyoruz
acaba maýn fonksiyonu parametre alablir mi veya maýn fonksiyonunu cagýrýrken arguman gönderebilir miyiz evet gönderebiliyoruz

su ana kadar ki çalýþmalarýmýzda hep tek bir veri tipleriyle çalýþtýk ýnt karakter float gibi
fakat günlük hayatta daha cok nesnelerle ugrasýyoruz ve nesneler tek boyutlu bir durumda degiller tek bir özellikten olusmuyorlar
burda structlar devreye giriyor
mesela bizim bir personumuz var bunun yasý var ýsmý var memleketi var
þimdi biz 100 öðrenci için bunlarý yapýyor olsak 100 öðrencinin adý için 100 elemanli bir dizi
yasý için 100 elemanlý baska bir dizi mesela
fakat bu primitive obsession dedigimiz temel veri tiplerine baðlý olmaktan kaynaklý bir kod kusuru meydana getirir
mesela biir fonksiyonun içinde f(ad,yas,memleke...)boyle yapýcagýmýza f(kisiler) boyle bir structla iþimizi haleldebiliyoruz bu bir programlama kolaylýgýdýr

struct Employee(structýmýzýn ismi){
	char name[20],surname[20];
	int ID;
	float salary;
};
bu global bir degisken olabilir
fonksiyon içerisinde tanýmlayabiliriz
bizden istenen global bir degisken olarak structýn tanýmýný yapmak
fonksiyonlar içinde strcuttan degisken üretmek

strcut Employee(bu ikisi birbirinden ayrýlmýyo gördügünüz gibi) employess(buna bir isim verdik ve bunun 1000 elemanlý olamsýný istedik)[1000];

baska ne yapabiliriz mesela strcut Employee *E;mesela boyle bir pointer tanýmlayabiliriz.
baska ne yapabilriz struct Employee E;boyle bir degisken tanýmlayabilirzi bu tek elemanlý bir struct

bunu her defa tanýmlandýgýnda struct demek yerine Employee ifadesini yani verilen etiketi kullanmak daha dogru
burda da type definition dan yararlanýyoruz

typedef kullanýmý söyle bir þey
#typedef int tamsayi;(artýk biz int yazmamýz gereken yerlere tamsayi yazabilirsin demek)

typedef struct{
	char name[20],surname[20];
	int ID;
	float salary;
}EMPLOYEE;


EMPLOYEE employees[1000];
typedef sayesinde biz EMPLOYEE ifadesini dogrudan kullanabiliyoruz;

ya da soyle bir þey olusturabiliyoruz;
EMPLOYEE *E;mesela burda bir pointer tanýmladýk

ya da soyle 
EMPLOYEE E;burda E degiskeni olusturduk

struct Employee{
 ---------
 ---------
 ----------
};
typdef struct Employee EMPLOYEE;
(typedef ifadesini boyle de kullanabiliyoruz)



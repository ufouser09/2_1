#include <stdio.h>
#include <stdlib.h>
#define MAX 20

//bu tarz iþlemlerde dosya okurken eger yapýmýz dosyamýz yapýlandýrýlmýs bir þey ise 
//bunu struct üzerinden okumak kod yazarken cok avantaj saglar özellikle her degisken için 


typedef struct ogr{
	char ad[MAX];
	int no;
	int puan;
}OGR;


int main(){
	//þimdi burda bir dosya açýcaz 
	char dosya[20];
	
	//FILE uzerinden pointer olusturalým 
	FILE *fp;
	
	int no;
	
	//ve okudugumuz bu dosyayý da bir OGR turunde bir degiskende tutucaz.(odevde de biz boyle yapýcaz.)
	OGR ogr;
	
	//hiçbir projede hiçbir þeyde kod içerisinden dýsarýdan girilecek bir veri girilmez.
	//bunu kullanýcýdan alýcaksýnýz ona uygun tasarlamanýz lazým.
	printf("DOSYA adi giriniz\n");
	scanf("%s",dosya);
	
	//oncelikle dosyanýn içindeki þeyleri ekrana yazdýracak bir fonksiyon yazalým.
	printf_file(dosya);
	//dosyayý acýp içerisinde bir kayýt arýyalým.
	
	//ben burda dosyayý tekrar acýyým okumayý da burda yapalým 
	//yani aranan bir ogrencilere ait bilgileri veya aranan ogrenci bilgisini kullanýcýdan alalým.
	
	//bir file pointer acalým 
	//burdaki dosya ismiyle bunu binary olarak okuycaz 
	fp=fopen(dosya,"rb");     
	
	//eger file pointer'ýmýz null dan farklý ise 
	if(fp!=NULL){
		//burda kullanýcýdan bir ogrenci numarasý alalým 
		printf("Ogrenci No");
		scanf("%d",&no);
	}
	//burda aranan ogrencinin bilgileri var mý yok mu diye
	//þimdi dosyayý actýk bir kayýt okuycam sýmdý 
	//bu kayýt eger benim aradýgým bir kayýtsa dogrudan buluruz.
	//veya dosyanýn sonuna kadar arama yapmam gerekecek.burda bir fread yapalým ilk once cunku ilk defade bulabilme imkanýmýz var.
	//dosyanýn formatý bu arada binary format.bunu acarken once bi tane okumam gerekiyor.
	//muhtemelen burda numaralar da sýralýydý okuyunca daha rahat anlasýlýr.
	//burdan bir kayýt okuycam once.
	//Nasýl okuycaz ----------->nasýl yazýldýysa oyle.
	
	//gidicez ogrenci structýnýn içerisine ,sizeof(OGR)kadar bir kayýt oku,bunu bir defa oku,file pointer'ýn gosterdigi yerden oku.
	fread(&ogr,sizeof(OGR),1,fp);
	
	//þimdi bunu okuduktan sonra bu benim ogrenci içerisinde ogrenci no degiskenimin altýnda bir þey var artýk bir degisken var 
	//bir de bunu while dongusu ile butun kayýtlarý gezicem aradýgým kaydý bulmak için bunu da soyle ogrenci numarasýna gore 
	//sýralý bir format var burda ogrenci no'nun nosu kucukse no'dan diyelim bir de diger sart olarak dosyanýn sonuna gelene kadar 
	//feof(fp)diyince napýyoduk dosyanýn sonuna gelip gelmedigimizi kontrol ediyoduk.yani boyle yaptýgýmýzda dosyanýn sonuna kadar arýcaz.
	while((ogr.no<no)&&(!feof(fp))){
		
		//þimdi yine ayný sekilde burda bir kayýt ara diyoruz bu þart saðlanana kadar yani while'a hiç girmeyebilir 
		//eger girersede sartlar saðlanana kadar bir þey gelicek.
		fread(&ogr,sizeof(OGR),1,fp);
	}
	
	//þimdi buraya geldigimizde aradýgýmýz kayýt bulundu mu bulunmadý mý
	//bu bahsettigimiz kayýt numara degil de puan olsaydý ve birden fazla gelme durumu vardý aranýlan durumda birden fazla ogrenci olabilirdi o zaman napmak gerekirdi. dosyadan okuyoruz ama okudugumuz kayýt her defasýnda birden fazla kayýt var.o zaman nasýl bir cozum uretirdiniz.bu veri tabaný ve oop nin konusudur.her bir sorgulama yapýldýgýnda ister veri tabanýnda ister dosyada nerde yapýlýrsa yapýlsýn eger kullanýcagýnýz kayýtlar yani cekeceginiz veriler size bi yerde gosterilsin istiyorsanýz,o zaman tek bir degisken degil dinamik olarak bir degisken yani OGR ogr dedigimiz seyi bir struct'ýr dizisinden saklamamýz gerekiyor.bu struct'ýr neyse artýk hangi turse ve her bir okudugumuz seyý napmamýz lazým o structýr dizisine eklememiz lazým.tabi dosya oldugu için dosyada napcak deep copy methodu ile burdaki structýra bellek içerisinde bir yere bunlar kopyalancak cunku onlarýn dogrudan adresi yok.biz sadece bir ogrenci buldugumuzda onun bilgisini yazmasý o zaman burda birden fazla satýr olucaksa OGR ogr 'yi nasýl tanýmlýcam.malloc ile tanýmlýcam.once bir tanelik yer ayýrýrsýnýz kayýt buldukca onu geniþletirsiniz veya þöyle bir strateji olabilir.ozellikle oop lerde array listler vardýr array list'in mantýgý þudur.dýnamýk bir dizi her turde tanýmlanabiliyor.ornegýn once 1000 tane acýlýyor.siz içerisinde 500 kayýt kullandýysanýz.500 luk kýsmý bellege geri iade ediyor.1000 i doldurdunuz.1.5 katý kadar kendi otomatik boyut arttýrýyor.arkada olan olaylar yine malloc realloc falan var.boyle bir dinamýk sey olmak zounda.dosyadan okudugumuz bu veriyi öðrencinin i'sine kopyaladýk tamam sýmdý burdan aldýgýmýzý baska bir fonksiyona göndercez orda iþlicez baska bir dosyaya gondercez o zaman ne lazým.dinamik bellek yonetimini olusturmak daha onemli oluyor.yaný normal bir dizi bizi cok sýkýntýya sokar  
	if(ogr.no==no ){
		printf("bulunan bilgiler");
		
		//ister text formatý olsun ister binary formatta olsun.
		//dosya üzerinde arama yaparken bi þekilde sýralý iþleme takýlmak zorundayýz.ayný dizide arar gibi.
		printf("\n%s %d %d\n",ogr.ad,ogr.no,ogr.puan);
	
	}
	
	else{	
		printf("kayýt bulunamadý.");
	}
	return 0;
}

//Dosya yazdýrma fonksiyonu
//buraya ne gelicek bir dosya adý gelicek 

void print_file(char ad[20]){
	int N,i;
	OGR e;
	FILE *fp=fopen(ad,"wb");//ad ile aç,binary bir dosya oldugu için bunu binary modda acýcam 
	//kac tane ogrenci olduguna bakmak istiyorum.bunu okuyunca   
	printf("ogrenci sayisi giriniz\n");
	scanf("%d",&N);
	
	printf("Bilgiler\n Ad -No - Puan\n");
	//formatlý bir okuma burda yapýcam yani formatlý bir þekilde dosyaya yazmak istiyorum 
	for(i=0;i<N;i++){
		
		//fscanf'i klavyeden almak için kullanýcam 
		//nerden alýyorum stdin ile aldýgým için bunu kullanýcýdan alýyorum klavyeden alýyorum yani 
		fscanf(stdin,"%s %d %d",e.ad,&e.no,&e.puan);
		
		//sonra struct'ý tek bir seferde tek bir blok halinde yazýyorum 
		//fwrite oncelikle burda bir pointer istiyor.su e'nin pointerýný adresini yaz,sizeof(OGR)kadar yaz ,1 defa yaz,nereye yaz file pointer'ýn gosterdigi yere yaz.
		fwrite(&e,sizeof(OGR),1,fp);
		
		//kac defa giriceksek N defa kayýt giriceksek N defa bu kayýt girdik 	
		
		
	}
	//file pointer'ý kapattýk.
	fclose(fp);
}

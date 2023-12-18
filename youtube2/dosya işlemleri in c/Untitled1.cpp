https://www.youtube.com/watch?v=fNXjahQ46jI&ab_channel=BilgisayarKavramlari


dosya nedir?
bir diskin üzerinde verilerimizi tuttugumuz zaman bu disk ssd de olabilir sonucta bir yerde tuttugunuzda
ram dýsýnda diske genelde ikincil hafýza(secondary memory) deniyor.

c de biz dosyanýn içine nasýl müdahale edebiliriz.bunu nasýl yazabiliriz.nasýl okuyabiliriz.
bunu öðrenicez. 

veri
disk 
dosya sistemi
iþletim sistemi


DOSYA ÝÞLEMLERÝ 4 ADIMDAN OLUSUYOR
1-dosya göstericisi FILE yapýsýndadýr(structure).Bir dosya tanýmlamamýz gerekiyor.
FILE *p;

2-dosya açýlýr.(fopen)

3-iþlem yapýlýr.

4-dosya kapanýr(fclose)


TEMEL DOSYA ÝÞLEMLERÝ(C için)

fopen-dosyayý açar(read/write)tipi belirtilir.(binary/text)

fclose-dosyayý kapatýr.

fread-dosyadan okur.

fwrite-dosyaya yazar.

fseek/fsetpos-dosya içerisinde göstericiyi hareket ettirir

ftell/fgetpos-dosya göstericisinin yerini soyler


DOSYA AÇMA ÞEKÝLLERÝ

r------->
okumak için açar(text)
dosya varsa dosyanýn basýný gösterir.
dosya yoksa hata doner.



w----------->
yazmak için açar(text)
dosya varsa içerigi silinir.
dosya yoksa olusturulur.



a--------->
eklemek için açar.
dosya varsa dosyanýn sonu gösterilir.
dosya yoksa olusturulur.

EOF--->her dosyanýn sonun gösteren pointerdýr.


dosyanýn 2 tip modu vardýr:text modu bi de binary modu
text modu açtýgýnýzda bir editorle içini okuyabiliceginiz bizim için anlamlý ascýý karakterlerinden olusan
binary mod ise içinde 1 0 þeklinde verileri tutuyor.dolayýsýyla bir karakter kodlamasý yapmak zorunda degil



DÝGER MODLAR

r+
dosyayý okuma ve yazma için açar ve dosyanýn basýný gosterir.

w+
dosyayý okuma ve yazmak için acar(mevcut dosyanýn uzerine yazar.)

a+
dosyayý okuma ve yazma için açar(dosyaya ekleme yapar)


mesela yazmak için açtýnýz fprintf 'i kullanabilirsiniz,ama fscanf'i kullanamazsýnýz.



DOSYAYI ACMA FONKSÝYONU

c dilinde(fopen)fonksiyonunun 2 amacý vardýr.

1-akýs(stream)ile fiziksel olarak dosyanýn baglanmasý
2-C tarafýndan iþlenebilecek bir program yapýsýnýn(struct)olusturabilmesi

Syntax:
	filepointer=fopen("filename","mode");//burda mode dedigimiz yukarýdaki r w a lar.
	
	yukarýdaki ifade bir filepointer donduruyor.bu filepointer aslýnda FILE yapýsýnda olan olur.
	yaný þöyle FILE *filepointer=fopen("filename","mode");
	
	

DOSYANIN KAPANMASI

lock(kilit)
buffer(gecici hafýza)
kullanýmý:
fclose(spdata);	

dosyayý kapamazsanýz sýkýntýlar çýkmaya baslýyor.dosyayý kapamadýgýnýz zaman cogu zaman calýsýr ama fclose demeden dosyaya yazýldýgýndan emýn olamazsýnýz.fclose 'u koymanýz lazým.


FPRÝNTF()

syntax:
	fprintf(fp,"string",variables);
	
	ornek:
		int i=12;
		float x=2.356;
		char ch='s';
		FILE *fp;
		fp=fopen("out.txt","w");
		fprintf(fp,"%d %f %c",i,x,ch);
		
		printf dedigimiz zaman ekrana basýyordu fprintf dedigimiz zaman ise file pointer veriyoruz oraya basýyor.
		
		
	
	
READÝNG AND WRÝTÝNG FÝLES

#include <stdio.h>
int main(){
	FILE *outfile,*infile;
	int b=5,f;
	float a=13.72,c=6.68,e,g;
	outfile=fopen("testdata","w");
	fprintf(outfile,"%f %d %f",a,b,c);
	fclose(outfile);
	infile=fopen("testdata","r");
	fscanf(infile,"%f %d %f",&e,&f,&g);
	printf("%f %d %f\n",a,b,c);
	printf("%f %d %f\n",e,f,g);
}	


end of file bizde dosyanýn sonuna ulasýldýgýnýz soyluyor.
her dosyanýn sonunda bir end of file pointer'ý var.
bu niye onemli cunku dosyayý okumaya basladýgýnýzda dosyanýn sonunu bilmezseniz sonuna kadar okumaya devam edebilirsiniz.
dolayýsýyla bir sembole ihtiyacýmýz var artýk daha fazla okunamýcagýný belirten bir sembole ihtiyacýmýz var o da EOF.

EOF ý da c de alan bir tane fonksiyon var feof diye gecen ve bununla okuyabiliyoruz.





ÖRNEK

#include <stdio.h>
#include <conio.h>

void main(){
	char ch;
	FILE *fp;
	fp=fopen("out.txt","r");//bu ornek için out.txt olmasý lazým.dosya yoksa pointer hatasý alýrsýn.
	while(!feof(fp)){
		ch=getc(fp);
		printf("\n%c",ch);
	}
	getch();
}




FREAD()

prototopi:
	size_t fread(void *ptr,size_t size,size_t n,FILE *stream);
	
	
	açýklama:
		belirtilen boyuttaki veriyi belirtilen bloga okur.
		
		ptr =verinin içine okunacagý blogu iþaret eder.
		size =her blogun boyutunu isaret eder.
		n=kac tane okunacagýný belirtir.
		stream=dosya gostericisidir.
		
		
		21.00

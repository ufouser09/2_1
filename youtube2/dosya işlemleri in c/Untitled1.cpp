https://www.youtube.com/watch?v=fNXjahQ46jI&ab_channel=BilgisayarKavramlari


dosya nedir?
bir diskin �zerinde verilerimizi tuttugumuz zaman bu disk ssd de olabilir sonucta bir yerde tuttugunuzda
ram d�s�nda diske genelde ikincil haf�za(secondary memory) deniyor.

c de biz dosyan�n i�ine nas�l m�dahale edebiliriz.bunu nas�l yazabiliriz.nas�l okuyabiliriz.
bunu ��renicez. 

veri
disk 
dosya sistemi
i�letim sistemi


DOSYA ��LEMLER� 4 ADIMDAN OLUSUYOR
1-dosya g�stericisi FILE yap�s�ndad�r(structure).Bir dosya tan�mlamam�z gerekiyor.
FILE *p;

2-dosya a��l�r.(fopen)

3-i�lem yap�l�r.

4-dosya kapan�r(fclose)


TEMEL DOSYA ��LEMLER�(C i�in)

fopen-dosyay� a�ar(read/write)tipi belirtilir.(binary/text)

fclose-dosyay� kapat�r.

fread-dosyadan okur.

fwrite-dosyaya yazar.

fseek/fsetpos-dosya i�erisinde g�stericiyi hareket ettirir

ftell/fgetpos-dosya g�stericisinin yerini soyler


DOSYA A�MA �EK�LLER�

r------->
okumak i�in a�ar(text)
dosya varsa dosyan�n bas�n� g�sterir.
dosya yoksa hata doner.



w----------->
yazmak i�in a�ar(text)
dosya varsa i�erigi silinir.
dosya yoksa olusturulur.



a--------->
eklemek i�in a�ar.
dosya varsa dosyan�n sonu g�sterilir.
dosya yoksa olusturulur.

EOF--->her dosyan�n sonun g�steren pointerd�r.


dosyan�n 2 tip modu vard�r:text modu bi de binary modu
text modu a�t�g�n�zda bir editorle i�ini okuyabiliceginiz bizim i�in anlaml� asc�� karakterlerinden olusan
binary mod ise i�inde 1 0 �eklinde verileri tutuyor.dolay�s�yla bir karakter kodlamas� yapmak zorunda degil



D�GER MODLAR

r+
dosyay� okuma ve yazma i�in a�ar ve dosyan�n bas�n� gosterir.

w+
dosyay� okuma ve yazmak i�in acar(mevcut dosyan�n uzerine yazar.)

a+
dosyay� okuma ve yazma i�in a�ar(dosyaya ekleme yapar)


mesela yazmak i�in a�t�n�z fprintf 'i kullanabilirsiniz,ama fscanf'i kullanamazs�n�z.



DOSYAYI ACMA FONKS�YONU

c dilinde(fopen)fonksiyonunun 2 amac� vard�r.

1-ak�s(stream)ile fiziksel olarak dosyan�n baglanmas�
2-C taraf�ndan i�lenebilecek bir program yap�s�n�n(struct)olusturabilmesi

Syntax:
	filepointer=fopen("filename","mode");//burda mode dedigimiz yukar�daki r w a lar.
	
	yukar�daki ifade bir filepointer donduruyor.bu filepointer asl�nda FILE yap�s�nda olan olur.
	yan� ��yle FILE *filepointer=fopen("filename","mode");
	
	

DOSYANIN KAPANMASI

lock(kilit)
buffer(gecici haf�za)
kullan�m�:
fclose(spdata);	

dosyay� kapamazsan�z s�k�nt�lar ��kmaya basl�yor.dosyay� kapamad�g�n�z zaman cogu zaman cal�s�r ama fclose demeden dosyaya yaz�ld�g�ndan em�n olamazs�n�z.fclose 'u koyman�z laz�m.


FPR�NTF()

syntax:
	fprintf(fp,"string",variables);
	
	ornek:
		int i=12;
		float x=2.356;
		char ch='s';
		FILE *fp;
		fp=fopen("out.txt","w");
		fprintf(fp,"%d %f %c",i,x,ch);
		
		printf dedigimiz zaman ekrana bas�yordu fprintf dedigimiz zaman ise file pointer veriyoruz oraya bas�yor.
		
		
	
	
READ�NG AND WR�T�NG F�LES

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


end of file bizde dosyan�n sonuna ulas�ld�g�n�z soyluyor.
her dosyan�n sonunda bir end of file pointer'� var.
bu niye onemli cunku dosyay� okumaya baslad�g�n�zda dosyan�n sonunu bilmezseniz sonuna kadar okumaya devam edebilirsiniz.
dolay�s�yla bir sembole ihtiyac�m�z var art�k daha fazla okunam�cag�n� belirten bir sembole ihtiyac�m�z var o da EOF.

EOF � da c de alan bir tane fonksiyon var feof diye gecen ve bununla okuyabiliyoruz.





�RNEK

#include <stdio.h>
#include <conio.h>

void main(){
	char ch;
	FILE *fp;
	fp=fopen("out.txt","r");//bu ornek i�in out.txt olmas� laz�m.dosya yoksa pointer hatas� al�rs�n.
	while(!feof(fp)){
		ch=getc(fp);
		printf("\n%c",ch);
	}
	getch();
}




FREAD()

prototopi:
	size_t fread(void *ptr,size_t size,size_t n,FILE *stream);
	
	
	a��klama:
		belirtilen boyuttaki veriyi belirtilen bloga okur.
		
		ptr =verinin i�ine okunacag� blogu i�aret eder.
		size =her blogun boyutunu isaret eder.
		n=kac tane okunacag�n� belirtir.
		stream=dosya gostericisidir.
		
		
		21.00

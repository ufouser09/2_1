//-----bu dosyanýn adý file_opr.c'dir.
//-----burda dosyadan okuma ve yazma iþlemleri yapýcaz.
#include <stdio.h>

//this function is used for printing to the file
//gonderdigimiz hasta bilgilerini alýcak 
void printListWithAllInformations(Patient_Node **head){
	FILE *fs=fopen("list.txt","wb");
	if(fs==NULL){
		printf("File cannot be opened\n");
		exit(0);
	}
	Patient_Node *var_head=(*head);
//-----dosya yazdýrma yaparkende yine ayný þekilde fwrite fonksiyonumuz ile
//-----yazdýrcagýnýz nesnenin boyutu,kac tane yazdýrýyoruz,
//-----gene stream nesnemiz var.bu sekilde yazdýrma iþlemi yapýyoruz.
	while(var_head != NULL){
		//bu fonksiyonu kullanarak dosyaya yazma yapýcak 
		fwrite(&(var_head->data),sizeof(Patient),1,fs);
		var_head=var_head->next;
	}
	fclose(fs);
	printf("\nFile is update\n");
}
//this function is used for reading from file
void read_File(){
	Patient patient;
	
	//-----dosyadan okuma yaparken stream nesnemizi olusturuyoruz.
	FILE *fs=fopen("list.txt","rb");
	if(fs==NULL){
		printf("File cannot be opened\n");
		exit(0);
	}
	
	/*
fread(void *buffer,size_t size,size_t count,FILE *stream)
buffer:Pointer to the buffer where data will be stored
size:The size of each element to be read in bytes
count:Number of elements to be read
stream:Pointer to the FILE object from where data is to be read
	*/
//-----asagýdaki fread()fonksiyonu ile okuma yapýyoruz.
//-----burda fread fonksiyonunun parametreleri var.
	
//-----buffer,size,count ve stream olarak.
//-----buffer dedigimiz:yani datanýn tutuldugu yeri iþaret eden iþaretcimizi biz buraya parametre olarak veriyoruz.
//-----ondan sonra dosyadan okunacak olan verinin boyutunu belirtiyoruz.
//-----ne kadar boyutta bir okuma yapýcaz diye.
//-----biz burda hastalarý okuyacagýmýz için Patient yapýmýzý veriyoruz.
//-----ondan sonra her bir seferde okunacak veri sayýsý 1 olucak.
//-----1 tane patient okuyacak.
//-----fs de bizim stream parametremiz.
//-----sonra okudugum veriler artýk patient nesnesinin içerisinde bulunacak
//-----ben burda okudugum veriyi print ediyorum.
//-----patient nokta diyip patient nesnesinin verilerine erisebiliyorum.

	while(fread(&patient,sizeof(Patient),1,fs)){
		printf("\nPatient Informations\n");
		printf("Name : %s\n",patient.name);
		printf("surname:%s\n",patient.surname);
		printf("ID      :%s\n",patient.ID);
		printf("Age : %d\n",patient.age);
		printf("prior:%d\n",patient.prior);
	}
	fclose(fs);
}

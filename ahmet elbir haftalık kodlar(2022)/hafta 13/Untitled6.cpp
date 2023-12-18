#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ogr{
	int  id;       
	char isim[10]; 
	char ders[10]; 
	int puan;	  
}OGR;

int main(){
	FILE *fp;
	char fName[15];
	char temp[10];
	OGR o1[4]={{1,"ali","mat1",100},{2,"veli","mat1",30},{3,"ayse","mat1",80},{4,"fatma","mat1",70}};
	int N = 4,i;
	OGR *ptr;
	fp = fopen("input.txt","w+");
	fwrite(&N,sizeof(int),1,fp);
	fwrite(o1,sizeof(OGR)*N,1,fp);
	//----- lab için yazilacak kodlar
	
	rewind(fp);
	fread(&N, sizeof(int),1,fp);
	ptr = (OGR*) malloc(N*sizeof(OGR));
	fread(ptr,sizeof(OGR)*N,1,fp);
	fclose(fp);	
	for(i=0;i<N;i++){
		printf("%d %s %s %d  \n",ptr[i].id, ptr[i].isim,ptr[i].ders,ptr[i].puan);
		fName[0]='\0';		//strcpy(fName,'\0');
		strcpy(fName,ptr[i].isim);
		strcat(fName,"_");
		itoa(ptr[i].id,temp,10);
		strcat(fName,temp);
        strcat(fName,".txt");//sprintf(fName,"%s_%d.txt",ptr[i].isim,ptr[i].id);
		printf("Dosya %d = %s",i,fName);
        fp = fopen(fName,"w+");
		fprintf(fp,"Sayin %s, %s dersi notunuz %d\nBasarilar",
		ptr[i].isim,ptr[i].ders,ptr[i].puan);
		fclose(fp);
	}	
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ogr{
	char name[10];
	char surname[10];
	int id;
}OGR;
void writeList(char *str, FILE *fp, int N);
void yaz(OGR *ptr, int N);
int main(){
	
	OGR temp={"","",0};
	OGR empty={"","",0};
	FILE *fp;
	int i=0, id;
	int N=10, j=0;
	OGR *ptr = (OGR*) malloc(N*sizeof(OGR));
	char tmp[10];
	srand(time(NULL));
	fp = fopen("Record.txt","w+");
	
	for(i=0;i<N;i++){
		//printf("Enter name, surname, and id, respectively");
		//scanf("%s %s %d",temp.name,temp.surname,&temp.id);
		for(j=0;j<9;j++){
			tmp[j] = rand()%26 + 66; 
		}
		tmp[j] = '\0'; 
		strcpy(temp.name,tmp); 
		strcpy(temp.surname,tmp); 
		temp.id = i+1;
		fwrite(&temp,sizeof(OGR),1,fp);
	}
	writeList("State 0",fp,N);
	rewind(fp);
	fread(ptr,N*sizeof(OGR),1,fp);
	yaz(ptr,N);
	
	rewind(fp);
	printf("Enter ID to update, ID must be > 0");
	scanf("%d",&id);
	fseek(fp,(id-1)*sizeof(OGR),SEEK_SET);
	fread(&temp,sizeof(OGR),1,fp);
	printf("%s\t%s\t%d\n",temp.name,temp.surname,temp.id);
	strcpy(temp.name,"AAAAAAAAA");
	fseek(fp,(id-1)*sizeof(OGR),SEEK_SET);
	fwrite(&temp,sizeof(OGR),1,fp);	
	printf("test");
	writeList("State 1",fp,N);
	
	printf("Enter ID to delete, ID must be > 0");
	scanf("%d",&id);
	fseek(fp,(id-1)*sizeof(OGR),SEEK_SET);
	fwrite(&empty,sizeof(OGR),1,fp);
	writeList("State 2",fp,N);
	
	fclose(fp);
}

void yaz(OGR *ptr, int N){
	int i=0;
	printf("Struct vcerileri\n");
	for(i=0;i<N;i++){
		printf("%s\t%s\t%d\n",ptr->name,ptr->surname,ptr->id);
		ptr++;
	}
}

void writeList(char *str, FILE *fp, int N){
	int i;
	OGR temp;
	printf("%s\n",str);
	printf("Name\tSurname\tID\n=======================\n");
	rewind(fp);
	for(i=0;i<N;i++){
		fread(&temp,sizeof(OGR),1,fp);
		if(temp.id>0)
			printf("%s\t%s\t%d\n",temp.name,temp.surname,temp.id);
	}
}

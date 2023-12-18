#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char isim[20];
    char soyisim[20];
    int no;
}PERSON;

void nokta(PERSON *person){

    FILE *fp;
    int i;

    fp=fopen("lab.txt","r+");

    for(i=0;i<5;i++){

        fscanf(fp,"%s %s %d\n",person[i].isim,person[i].soyisim,&person[i].no);
        printf("%s %s %d\n",person[i].isim,person[i].soyisim,person[i].no);

    }

    fclose(fp);
}


void ok(PERSON *person){

    FILE *fp;
    int i;


    fp=fopen("lab.txt","r+");

    for(i=0;i<5;i++){

        fscanf(fp,"%s %s %d\n",person->isim,person->soyisim,&person->no);
        printf("%s %s %d\n",person->isim,person->soyisim,person->no);
        //printf("Adres:  %p\n ",person);
		person++;
    }

    fclose(fp);


}

int main()
{


   PERSON person[5];
   int secim;

   printf("Ok ile okumak icin 1 nokta ile okumak icin 2\n");
   scanf("%d",&secim);

   switch(secim){

   case 1 : ok(person); break;

   case 2 : nokta(person);break;

   }

    return 0;
}


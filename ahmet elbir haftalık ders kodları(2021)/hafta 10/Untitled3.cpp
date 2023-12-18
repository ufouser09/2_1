#include <stdio.h>
struct ogrenci{
	int id;
	int yas;
};
int main(){
	FILE *fp;
	fp = fopen("emp.txt", "r");
	if(fp==NULL){
		printf("Dosya yok");
	}
	else{
		fprintf(fp,"%d %s",123,"abc");
	}
	
	return 0;
}

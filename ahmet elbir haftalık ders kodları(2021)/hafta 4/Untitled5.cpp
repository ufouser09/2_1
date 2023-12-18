#include<stdio.h>
#include<stdlib.h>

int main(){
	int N,i;
	int *dizi, *tmp;
	printf("Enter N");
	scanf("%d",&N);
	tmp=dizi = (int*) malloc(N*sizeof(int));
	if(dizi!=NULL){
		printf("Array allocated");
	
	for(i=0;i<N;i++){
		printf("Enter %dth value",i);
		//scanf("%d",(dizi+i));
		//scanf("%d",&dizi[i]);
		scanf("%d",tmp); tmp++;
		tmp++;
	}
	for(i=0;i<N;i++){
		printf("%dth value=%d\n",i,*(dizi+i));
	}
	
	free(dizi);	
	return 0;
	}else{
		printf("Array not allocated");
		return -1;
	}
	
}
/*output:
Enter N
5
Array allocatedEnter 0th value1
Enter 1th value2
Enter 2th value3
Enter 3th value4
Enter 4th value5
0th value=1
1th value=0
2th value=2
3th value=0
4th value=3
*/

#include <stdio.h>
#define MAX 15
typedef struct edge{
	int s, d, w;
}EDGE;
typedef struct edgeList{
	EDGE data[MAX];
	int n;
}EDGELIST;

EDGELIST eList;
EDGELIST MSTList;
int Graph[MAX][MAX];

void printList(char *str, EDGELIST list);
void myKruskal(int N);
void sort();
void unifyNodes(int set[], int set1, int set2);
int getSet(int set[], int node);

int main(){
	int N=5;
	Graph[0][0]=0; Graph[0][1]=1;Graph[0][2]=7;Graph[0][3]=10;Graph[0][4]=5;
	Graph[1][0]=1; Graph[1][1]=0;Graph[1][2]=3;Graph[1][3]=0; Graph[1][4]=0;
	Graph[2][0]=7; Graph[2][1]=3;Graph[2][2]=0;Graph[2][3]=4;Graph[2][4]=0;
	Graph[3][0]=10; Graph[3][1]=0;Graph[3][2]=4;Graph[3][3]=0;Graph[3][4]=2;
	Graph[4][0]=5; Graph[4][1]=0;Graph[4][2]=0;Graph[4][3]=2;Graph[4][4]=0;

	myKruskal(N);
	return 0;
}

void myKruskal(int N){
	int i,j;
	int set1, set2;
	int set[MAX];
	eList.n=0;
	for(i=1;i<N;i++){
		for(j=0;j<i;j++){
			if(Graph[i][j]!=0){
				eList.data[eList.n].s = i;
				eList.data[eList.n].d = j;
				eList.data[eList.n].w = Graph[i][j];
				eList.n++;
			}
		}
	}
	printList("Before sorting", eList);
	sort();
	printList("After Sorting", eList);
	
	for(i=0;i<N;i++){
		set[i] = i;
	}
	MSTList.n = 0; 
	i=0;
	
	//for(i=0;i<eList.n;i++){
	while((i<eList.n) && (MSTList.n<N))
		set1 = getSet(set,eList.data[i].s);
		set2 = getSet(set,eList.data[i].d);
		if (set1!=set2){
			MSTList.data[MSTList.n] = eList.data[i];
			MSTList.n++;
			unifyNodes(set,set1,set2);
		}
	}
	
	printList("MST List", MSTList);
	
	
}
void unifyNodes(int set[], int set1, int set2){
	int i;
	for(i=0;i<eList.n;i++){
		if(set[i] == set2 )
			set[i] = set1;
	}
}
int getSet(int set[], int node){
	return set[node];
}

void sort(){
	int i,j;
	
	EDGE temp;
	for(i=1;i<eList.n;i++){
		for(j=0;j<eList.n-1;j++){
			if(eList.data[j].w > eList.data[j+1].w){
				temp = eList.data[j];
				eList.data[j] = eList.data[j+1];
				eList.data[j+1] = temp;
			}
		}
	}
}

void printList(char *str,EDGELIST List ){
	int i;
	int cost = 0;
	printf("%s\n",str);
	for(i=0;i<List.n;i++){
		printf("%d %d : %d\n", List.data[i].s,List.data[i].d,List.data[i].w);
		cost += List.data[i].w;
	}
	printf("COST=%d\n",cost);
}

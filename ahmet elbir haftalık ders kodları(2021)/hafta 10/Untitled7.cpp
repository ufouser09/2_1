//this program calculates all digits of a positive number
#include <stdio.h>
void digits(int x)
{
	 while(x>0)
	 {
	 	printf("%5d",x%10);
	 	x/=10;
	 }
	 return;
}
void digitsR(int x)
{
	if(x==0) return;
	printf("%5d",x%10);
	digitsR(x/10);
} 
int main()
{
	int x;
	printf("Enter x value:");
	scanf("%d",&x);
	printf("Non-recursive: ");digits(x);
	printf("\nrecursive: ");digitsR(x);
	return 0;
	
}


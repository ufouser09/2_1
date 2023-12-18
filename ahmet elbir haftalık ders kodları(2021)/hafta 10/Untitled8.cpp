//this program calculates all digits of a positive number
#include <stdio.h>
int power1(int x, int y){ // T(N) = O(N)
	int i, result=1;
	for(i=1;i<=y;++i){
	 	result = result * x;
	}	 
	return result;
}
int power2(int x, int y){// T(N) = T(N-1) + 1 ==> O(N)
	if (x == 0) return 0;
	if (y == 0) return 1;
	return x*power2(x,y-1); 
}

int power3(int x, int y){// T(N) = 2 T(N/2) + 1 a=2, b=2, d=0 ==> O(N)
	if(y == 0)
		return 1;
	else if (y % 2 == 0)
		return power3(x,y/2)*power3(x,y/2);
	else
		return x*power3(x,y/2)*power3(x,y/2); 
}

int power4(int x, int y){// T(N) = T(N/2) + 1 a=1, b=2, d=0 ==> O(logN)
	int result;
	if(y == 0)
		return 1;
	result = power4(x,y/2);
	if(y % 2 == 0)
		return result*result;
	else
		return x*result*result; 
} 
int main()
{
	int x,y;
	printf("Enter x value:");
	scanf("%d",&x);
	printf("Enter y value:");
	scanf("%d",&y);
	printf("Power1(%d^%d)=%d\n",x,y,power1(x,y));
	printf("Power2(%d^%d)=%d\n",x,y,power2(x,y));
	printf("Power3(%d^%d)=%d\n",x,y,power3(x,y));
	printf("Power4(%d^%d)=%d\n",x,y,power4(x,y));
	return 0;
	
}


/* cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta4_codes
cc -o test hafta4_7_ptrTOfuncs.c 
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*   Function returns the argument a. */
int self_i(int a)
{
	return a;
}
/*   Function returns the square of a. */
int square_i(int a)
{
	return a * a;
}

/*   Function sums integers from x to y. */

/*   Function sums values of *fp applied to integers from x to y. */
int sum_generic(int (*fp)(), int x, int y)
{
	int i, cumsum = 0;
	for (i = x; i <= y; i++)
		cumsum += (*fp)(i);
	return cumsum;
}
int main(){
	int x=5, y=15;
	int (*fp[2])();
	fp[0]=self_i;
	fp[1]=square_i;
	

	printf("Sum of the numbers from %d to %d is: %d\n", x,y, sum_generic(fp[0], x, y) );

	printf("Sum of the squares of the numbers from %d to %d is: %d\n", x,y, sum_generic(fp[1], x, y) );
 	return 0;
}
//bu koda bi da bak

/* how to compile and create exe for the main function:
cd /Users/....
cc -o test hafta10_ex2_chr.c 
*/

#include <stdio.h>
#include <stddef.h> 
#define FAIL 0 
#define SUCCESS 1 
#define LINESIZE 20
#define BLOCKSIZE 512
typedef char DATA;

int x=9;

int copyfile(char * infile, char * outfile){
  FILE *fp1, *fp2;
  if ((fp1 = fopen(infile, "rb" )) == NULL) {
    printf("Could not open the input file\n");
    return FAIL; 
  }
  if ((fp2=fopen (outfile, "wb" )) == NULL)
  {
    printf("Could not open the output file\n");
    fclose ( fp1 );
    return FAIL;
  }
  // **** When the end-of-file is encountered, the feof() function returns a non-0 value. 
  while (!feof( fp1 ))
    putc( getc(fp1), fp2 );

/* NOTE: we cannot use the return value of getc() to test for an end-of-file character
    because the file is opened in the binary mode. For example, if we wrote
    int c;
    while ((c = getc( fp1 )) != EOF)
    the loop will exit whenever the character read has the same value as EOF. 
    This may or may not be a true end-of-file condition in binary files. 
    However, the feof() function will exactly provide us to check if we reach the eof.
*/ 

  fclose(fp1); 
  fclose(fp2); 
  return SUCCESS;
}

int copyfilev2(char * infile, char * outfile){
  int x=0;
  FILE *fp1, *fp2;
  char line[LINESIZE];
  if ((fp1 = fopen( infile, "r" )) == NULL)
     return FAIL;
  if ((fp2 = fopen( outfile, "w" )) == NULL){
    fclose(fp1);
    return FAIL;
  }

  while (fgets ( line, LINESIZE-1, fp1 ) != NULL)
  x++;
    fputs( line, fp2 );
  fclose(fp1); 
  fclose(fp2);
  return x;
}

int copyfilev3(char * infile, char * outfile){
	int h=9;
	static int y=9;
  FILE *fp1, *fp2;
  int num_read; 
  char block[BLOCKSIZE];
  if ((fp1 = fopen( infile, "rb" )) == NULL){
    printf( "Error opening file %s for input.\n", infile );
    return FAIL;
  }
  if ((fp2 = fopen( outfile, "wb" )) == NULL){
    printf( "Error opening file %s for output.\n", outfile );
    fclose(fp1);
    return FAIL;
  }

  while ((num_read = fread( block, sizeof(DATA), BLOCKSIZE, fp1 )) == BLOCKSIZE)
    fwrite( block, sizeof(DATA), num_read, fp2 );

  fwrite( block, sizeof(DATA), num_read, fp2 );
  fclose(fp1); 
  fclose(fp2);
  if (ferror( fp1)) {
    printf( "Error reading file %s\n", infile );
    return FAIL;
  }
  return SUCCESS;
}

int main(){
  char infl[100], outfl[100]; 
  int result, result2;
  printf("enter name of the input file\n"); 
  scanf("%s", infl);

  printf("enter name of the output file\n"); 
  scanf("%s", outfl);
 
  result=copyfile(infl, outfl);
  if(result == SUCCESS)
    printf("input file is copied to the output file \n");
  if(result == FAIL)
    printf("input file could not be copied to the output file \n");
 
 printf("enter name of the output file\n"); 
  scanf("%s", outfl); 
 result2=copyfilev3(infl, outfl);
 printf("Okuma sayisi = %d",result2);   
if(result2 == SUCCESS)
    printf("input file is copied to the output file \n");
  if(result2 == FAIL)
    printf("input file could not be copied to the output file \n");

  return 0; 
}


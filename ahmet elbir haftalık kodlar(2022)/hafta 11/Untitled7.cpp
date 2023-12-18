#include<stdio.h>

int main()
{
    FILE *fp;
    char ch;
    fp = fopen("test.txt","r");
    if(!fp){
        printf("Error in opening file\n");
        return 0;
    }
    //Initially, the file pointer points to the starting of the file.
    printf("1st Position of the pointer : %ld\n",ftell(fp));
    
    while(fread(&ch,sizeof(ch),1,fp)==1){
      printf("%c",ch);
    }
    printf("\n2nd Position of the pointer : %ld\n",ftell(fp));

    rewind(fp);
    printf("3rd Position of the pointer : %ld\n",ftell(fp));
    
    fclose(fp);
    return 0;
}


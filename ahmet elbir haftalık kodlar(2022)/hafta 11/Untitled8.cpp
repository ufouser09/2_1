#include <stdio.h>       
#include <errno.h>       
#include <string.h> 
 
int main(){
    FILE *fp;                                //File Pointer
    fp = fopen("test.txt","r");
    if(fp==NULL){                           //If file doesn't exists 
        printf("Value of errno: %d",errno);
        printf("\nError Message: %s",strerror(errno));
        perror("Message from perror");
    }
    else{
        int num;
        fscanf(fp,"%d",&num);             //Reading integer data from the file
        printf("File Data: %d",num);
        fclose(fp); 
    }
    return 0;
}

